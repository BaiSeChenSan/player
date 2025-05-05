#ifndef DECODE_H
#define DECODE_H

#include<QObject>
#include<QImage>
#include<QUrl>
#include<QThread>
#include<QMutex>
#include<QWaitCondition>
#include<QAudioFormat>
// #include"tool.h"
#include<atomic>
extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>
#include<sonic.h>
}

class Decoder:public QThread
{
    Q_OBJECT
public:
    explicit Decoder(QObject *parent = nullptr);
    ~Decoder();

    bool open(const QUrl &url);
    bool getPaused(){
        return paused;
    }
    bool getAbort(){
        return abort;
    }
    void startDecoding();
    void pauseDecoding();
    void stopDecoding();
    void resumeDecoding();
    void seekToStart();
    QAudioFormat getFormat();
    void setPlayTime(qint64 time);
    void seek(qint64 pos);
    void setSpeed(double speed);
    qint64 getFilelen(){
        return filelen;
    }
    void cleanup();
    void setHardwareAccel(bool val){
        useHardwareAccel=val;
    }
    std::atomic_int videoCnt{0};
    std::atomic<int> audioCnt{0};  // 音频队列当前大小
    QWaitCondition condition;
    void setZero(){
        videoCnt.store(0);
        audioCnt.store(0);
    }
signals:
    // void videoFrameDecoded(const yuvItem &frame, qint64 pts);
    void videoFrameDecoded(const QImage &frame, qint64 pts);
    void audioBufferDecoded(const QByteArray &buffer, qint64 pts);
    void finished();
    void check();
protected:
    void run() override;
private:
    // FFmpeg 相关
    AVFormatContext *fmtCtx = nullptr;
    AVCodecContext *videoCodecCtx = nullptr, *audioCodecCtx = nullptr;
    SwsContext *swsCtx = nullptr;
    SwrContext *swrCtx = nullptr;
    int videoStreamIdx = -1, audioStreamIdx = -1;

    // 同步控制
    QMutex mutex;

    bool abort = false;
    bool paused = false;


    // 时间基准
    AVRational videoTimeBase;
    AVRational audioTimeBase;

    // 初始化/清理函数
    bool initVideo();
    bool initAudio();

    //视频数据
    qint64 playTime=0;
    qint64 filelen=0;


    //播放控制
    qint64 seek_target_pts=-1;
    QMutex seek_mutex;
    bool need_seek=false;
    bool catch_up=true;
    sonicStream sncStream;
    double playback_speed=1;
    qint64 lastEmitVideoPts=0;
    qint64 lastEmitAudioPts=0;
    bool lastDecodeIsVideo=false;
    QList<int> m_HWDeviceTypes;
    enum AVPixelFormat hwPixFmt = AV_PIX_FMT_NONE;
    bool useHardwareAccel=false;


    const int MAX_VIDEO_BUFFER = 30;     // 视频队列最大容量
    const int MAX_AUDIO_BUFFER = 50;

};
#endif // DECODE_H
