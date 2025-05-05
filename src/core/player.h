#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include<QAudioOutput>
#include<QImage>
#include<QUrl>
#include<QPointer>
#include<QQueue>
#include<QTime>
#include"decode.h"
#include"glwidget.h"
// #include"tool.h"
struct audioBufferItem
{
    QByteArray data;
    qint64 pts;
};
struct videoBufferItem
{
    QImage img;
    qint64 pts;
};
class Player : public QObject
{
    Q_OBJECT
public:
    enum playState{
        Ended,
        Playing,
        Paused
    };
    explicit Player(QObject *parent = nullptr);
    ~Player();
    void setVideoOutput(GLWidget * widget);
    void play();
    void pause();
    void setSource(const QUrl &source);
    QString getCurrentTime(){
        QString res=QTime(0, 0, 0).addSecs(audioClock/1000).toString(QString::fromLatin1("HH:mm:ss"));
        return res;
    }
    int volume(){
        if(audioOutput==nullptr)return 1;
        return (int)(audioOutput->volume()*100);
    }
    void setVolume(int vol){
        qreal new_vol=(qreal)vol/100.0;
        if(audioOutput==nullptr){
            volumeToSet=new_vol;
            return;
        }
        else{
            audioOutput->setVolume(new_vol);
        }

    }
    void setPlaybackRate(double speed){
        playbackRate=speed;
        decoder->setSpeed(playbackRate);
        videoBufferQueue.clear();
        audioBufferQueue.clear();
        decoder->setZero();
        qDebug()<<"set playbackRate called"<<speed;
    }
    qint64 duration(){
        return decoder->getFilelen();
    }
    qint64 position(){
        return audioClock;
    }

    void setPosition(qint64 pos){//input:Msec
        QMutexLocker locker(&clockMutex);
        audioBufferQueue.clear();
        videoBufferQueue.clear();
        qDebug()<<"set postion called"<<pos/1000;
        audioClock=pos;
        decoder->seek(pos);
    }
    void stop(){
        m_stopped.storeRelease(1);
        qDebug()<<"stop func called";
        decoder->stopDecoding();
        if(audioOutput)audioOutput->stop();
        audioBufferQueue.clear();
        videoBufferQueue.clear();
        audioClock=0;
        state=Ended;
        emit positionChanged(audioClock);
    }

    QUrl getUrl(){
        return source;
    }

signals:
    void durationChanged(qint64);
    void positionChanged(qint64);
    void stateChanged();
private slots:
    void handleVideoFrameDecoded(const QImage &frame, qint64 pts);
    void handleAudioBufferDecoded(const QByteArray &buffer, qint64 pts);
    void handleDecodeFinished();
    void checkRemain();
private :
    void syncVideoToAudio();
    void outputVideoFrame();
    void outputAudioFrame();
    void finalPlay();
    void playcontrol();
    // 同步相关
    qint64 audioClock = 0; // 主时钟（单位：毫秒）
    qint64 lastVideoPts = 0;
    QMutex clockMutex;

    // 组件
    QPointer<GLWidget> videoOutput;
    QAudioOutput* audioOutput;
    Decoder * decoder;
    QIODevice *audioDevice;

    QUrl source;
    playState state;
    QQueue<audioBufferItem> audioBufferQueue;
    QQueue<videoBufferItem> videoBufferQueue;
    double playbackRate=1.0;
    qint64 lastFrame=-1;
    qreal volumeToSet=1;
    QAtomicInt m_stopped;

};

#endif // PLAYER_H
