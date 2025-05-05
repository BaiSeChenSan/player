#include "player.h"
#include"glwidget.h"
#include<QTimer>
#include <QElapsedTimer>
#include<QDateTime>
#include<QDebug>
#include<QCoreApplication>
// #include"tool.h"
QByteArray generateSilence(int ms, const QAudioFormat &format) {
    int bytesPerSample = format.sampleSize() / 8 * format.channelCount();
    int samples = format.sampleRate() * ms / 1000;
    return QByteArray(samples * bytesPerSample, 0); // 填充0
}
Player::Player(QObject *parent)
    : QObject{parent},videoOutput{nullptr},audioOutput{nullptr},source{nullptr}
{
    decoder=new Decoder(this);
    connect(decoder, &Decoder::videoFrameDecoded, this, &Player::handleVideoFrameDecoded, Qt::QueuedConnection);
    connect(decoder, &Decoder::audioBufferDecoded, this, &Player::handleAudioBufferDecoded, Qt::QueuedConnection);
    connect(decoder, &Decoder::finished, this, &Player::handleDecodeFinished, Qt::QueuedConnection);
    connect(decoder,&Decoder::check,this,&Player::checkRemain,Qt::QueuedConnection);

    state=Ended;
    qDebug()<<"player init";

}

void Player::setVideoOutput(GLWidget * widget){
    videoOutput=widget;
}
Player::~Player() {
    qDebug()<<"~player called";
    if (decoder->isRunning()) {
        qDebug()<<"decoder running";
        decoder->stopDecoding();
        decoder->wait();
        disconnect(decoder, nullptr, this, nullptr);
    }
    if (audioOutput) {
        audioOutput->stop();
    }
}

void Player::play()
{
    m_stopped.storeRelease(0);
    qDebug()<<"play called";
    if(state==Playing){
        return;
    }
    if(state==Ended){
        audioClock = 0;
        if(videoBufferQueue.size())videoBufferQueue.clear();
        if(audioBufferQueue.size())audioBufferQueue.clear();
        decoder->seekToStart();
        audioDevice=audioOutput->start();
    }
    state=Playing;
    if(audioOutput&&audioOutput->state()==QAudio::SuspendedState){
        qDebug()<<"resume play";
        audioOutput->resume();
        if(audioBufferQueue.size()){
            while(audioBufferQueue.size()){
                outputAudioFrame();
                outputVideoFrame();
                QCoreApplication::processEvents();
            }
        }
        else {
            qDebug()<<"buffer queue was empty";
            if(decoder->getPaused()&&decoder->getAbort()==false)decoder->resumeDecoding();
        }
        return;
    }
    QByteArray silence = generateSilence(50, audioOutput->format());
    audioDevice->write(silence);
    qDebug()<<"start play";
    decoder->startDecoding();
    // playcontrol();

}


void Player::pause()
{
    if (state != Playing) {
        return;
    }
    qDebug()<<"player pause() call";
    state = Paused;
    if(decoder->getAbort()==false&&decoder->getPaused()==false&&audioBufferQueue.size()>50){
        decoder->pauseDecoding();
    }
    if (audioOutput && audioOutput->state() == QAudio::ActiveState) {
        audioOutput->suspend(); // 暂停音频
    }
}

void Player::setSource(const QUrl& url){
    source=url;
    if(audioOutput){
        qDebug()<<"entry audio Output";
        audioOutput->stop();
        delete audioOutput;
        audioOutput=nullptr;
        decoder->cleanup();

    }

    if (!decoder->open(source)) {
        qDebug() << "Failed to open file!";
        return;
    }
    QAudioFormat format=decoder->getFormat();
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    audioOutput=new QAudioOutput(format,this);
    audioOutput->setVolume(volumeToSet);
    audioOutput->setBufferSize(format.sampleRate() * 4 * sizeof(int16_t) * 0.2);
    audioDevice=audioOutput->start();
    if (!audioDevice) {
        qWarning() << "Failed to start audio output!";
    }
    state=Paused;
    audioClock=0;
    emit positionChanged(audioClock);
    emit durationChanged(duration());
}


void Player::handleVideoFrameDecoded(const QImage &frame, qint64 pts){
    if(m_stopped.loadAcquire())return;
    QMutexLocker locker(&clockMutex);
    qDebug() << "[Video] PTS:" << pts << "ms,video buffer size:"<<videoBufferQueue.size();

    videoBufferQueue.enqueue({frame,pts});

    if(state==Playing){
        outputVideoFrame();
    }
}

void Player::handleAudioBufferDecoded(const QByteArray &buffer, qint64 pts) {
    if(m_stopped.loadAcquire())return;
    QMutexLocker locker(&clockMutex);
    qDebug() << "[Audio] PTS:" << pts << "ms, Bytes:" << buffer.size()<<"audio queue size"<<audioBufferQueue.size();

    audioBufferQueue.enqueue({buffer,pts});

    if(state==Playing){
        outputAudioFrame();
        if(lastFrame<audioClock-20)outputVideoFrame();
    }
}

void Player::handleDecodeFinished() {
    qDebug()<<"finished decode";
    if(audioBufferQueue.size()){
        qDebug()<<"final play call";
        finalPlay();
    }
    audioBufferQueue.clear();
    videoBufferQueue.clear();
    // videoOutput->summarize();
    state = Ended;
    emit stateChanged();

    audioOutput->stop();
    decoder->stopDecoding();

    QCoreApplication::processEvents();
}

void Player::checkRemain(){
    qDebug()<<"checkRemain called";
    while(audioBufferQueue.size()>=10){
        outputVideoFrame();
        outputAudioFrame();
        QCoreApplication::processEvents();
    }
    decoder->condition.wakeAll();
}
void Player::outputVideoFrame(){
    if(videoBufferQueue.size()){
        videoBufferItem vitem=videoBufferQueue.head();
        //todo:20应修改为预期帧间隔
        if(vitem.pts>audioClock+20){
            return;
        }
        else if(vitem.pts<audioClock-20){
            while(videoBufferQueue.size()){
                vitem=videoBufferQueue.head();videoBufferQueue.dequeue();
                decoder->videoCnt.fetch_sub(1, std::memory_order_relaxed);
                if(vitem.pts>audioClock-20)break;
            }
            if(vitem.pts<audioClock-20){
                qDebug()<<"still slow after video queue empty";
            }
            videoOutput->setFrame(vitem.img);
            lastFrame=vitem.pts;
            qDebug()<<"output video pts:"<<vitem.pts<<"remain queue size:"<<videoBufferQueue.size();
        }
        else{
            videoOutput->setFrame(vitem.img);
            videoBufferQueue.dequeue();
            decoder->videoCnt.fetch_sub(1, std::memory_order_relaxed);

            lastFrame=vitem.pts;
            qDebug()<<"output video pts:"<<vitem.pts<<"remain queue size:"<<videoBufferQueue.size();
        }
    }
}
void Player::outputAudioFrame(){
    if (!(audioOutput->state() == QAudio::IdleState||audioOutput->state()==QAudio::ActiveState) ){
        return;
    }

    if(audioBufferQueue.size()){
        audioBufferItem item=audioBufferQueue.head();
        if(audioOutput->bytesFree()>=item.data.size()){

            int written =audioDevice->write(item.data.constData(),item.data.size());
            if (written != item.data.size()) {
                qWarning() << "Audio write mismatch, expected:" << item.data.size() << "actual:" << written;
                return;
            }
            if(item.pts/1000>audioClock/1000){
                emit positionChanged(item.pts);
            }
            audioClock=item.pts;
            audioBufferQueue.dequeue();
            decoder->audioCnt.fetch_sub(1, std::memory_order_relaxed);

            qDebug()<<"output audio pts:"<<item.pts<<"remain queue size:"<<audioBufferQueue.size();

            if(decoder->getPaused()&&decoder->getAbort()==false&&audioBufferQueue.size()<10){//该部分用于暂停后的恢复
                decoder->resumeDecoding();
            }

        }
    }
}

void Player::finalPlay(){
    while(audioBufferQueue.size()){
        outputAudioFrame();
        outputVideoFrame();
        QCoreApplication::processEvents();
    }
}

void Player::playcontrol(){
    while(state!=Ended){
        QThread::usleep(5000);
        outputAudioFrame();
        outputVideoFrame();
        QCoreApplication::processEvents(QEventLoop::AllEvents, 50);
    }
}
