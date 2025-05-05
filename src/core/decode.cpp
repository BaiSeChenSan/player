#include "decode.h"
#include<QDebug>
#include<QElapsedTimer>
#include<QAudioFormat>

// #include"tool.h"
extern "C" {
#include <libavutil/time.h>
#include <libavformat/avformat.h>
#include<libavutil/hwcontext.h>
#include<libavutil/avutil.h>
#include<libavutil/pixdesc.h>
}


Decoder::Decoder(QObject *parent) : QThread(parent) {
    AVHWDeviceType type = AV_HWDEVICE_TYPE_NONE;      // ffmpeg支持的硬件解码器
    QStringList strTypes;

    while ((type = av_hwdevice_iterate_types(type)) != AV_HWDEVICE_TYPE_NONE)       // 遍历支持的设备类型。
    {
        m_HWDeviceTypes.append(type);
        const char* ctype = av_hwdevice_get_type_name(type);  // 获取AVHWDeviceType的字符串名称。
        if(ctype)
        {
            strTypes.append(QString(ctype));
        }
    }
    qDebug() << "支持的硬件解码器：" << strTypes;



}

Decoder::~Decoder() {
    stopDecoding();
    cleanup();
}


bool Decoder::open(const QUrl &url){
    // cleanup();
    QString filepath;
    if(url.isLocalFile()){
        filepath=url.toLocalFile();
    }
    else{
        filepath=url.toString();
    }
    QByteArray filePathUtf8 = filepath.toUtf8();

    if (avformat_open_input(&fmtCtx, filePathUtf8.constData(), nullptr, nullptr) != 0) {
        qWarning("Failed to open file");
        return false;
    }
    if (avformat_find_stream_info(fmtCtx, nullptr) < 0) {
        qWarning("Failed to find stream info");
        avformat_close_input(&fmtCtx);
        return false;
    }
    if (!initAudio()) {
        return false;
    }

    // 视频初始化失败仅当存在视频流时报错
    if (!initVideo() && videoStreamIdx >0) {
        return false;
    }

    return true;
}



bool Decoder::initVideo(){
    videoStreamIdx=av_find_best_stream(fmtCtx,AVMEDIA_TYPE_VIDEO,-1,-1,nullptr,0);
    if(videoStreamIdx<0){
        qWarning("No Video Stream found");
        return false;
    }
    AVStream* stream=fmtCtx->streams[videoStreamIdx];
    AVCodecID codecId=stream->codecpar->codec_id;
    qDebug()<<"codec id:"<<avcodec_get_name(codecId);


    const AVCodec* codec = nullptr;
    void* i = 0;
    while ((codec = av_codec_iterate(&i))) {
        if (av_codec_is_decoder(codec) && codec->id == codecId) {
            qDebug() << "Available decoder:" << codec->name;  // 输出所有可用的解码器
        }
    }

    AVBufferRef* hw_device_ctx=nullptr;
    AVHWDeviceType hwType=AV_HWDEVICE_TYPE_NONE;
    const char * hwDecoderName=nullptr;
    if(useHardwareAccel){
        if (codecId == AV_CODEC_ID_H264) {
            hwDecoderName = "h264_cuvid";
            hwType = AV_HWDEVICE_TYPE_CUDA;
        } else if (codecId == AV_CODEC_ID_HEVC) {
            hwDecoderName = "hevc_cuvid";
            hwType = AV_HWDEVICE_TYPE_CUDA;
        }

        // **优先尝试 cuvid (NVIDIA)**
        if(hwDecoderName)codec = avcodec_find_decoder_by_name(hwDecoderName);
        if(!codec){
            if(codecId==AV_CODEC_ID_H264){
                hwDecoderName="h264_qsv";
                hwType=AV_HWDEVICE_TYPE_QSV;
            }
            else if(codecId==AV_CODEC_ID_HEVC){
                hwDecoderName="hevc_qsv";
                hwType=AV_HWDEVICE_TYPE_QSV;
            }
        }


        if(hwDecoderName){
            codec=avcodec_find_decoder_by_name(hwDecoderName);
            if (codec) {
                if (av_hwdevice_ctx_create(&hw_device_ctx, hwType, nullptr, nullptr, 0) < 0) {
                    qWarning("Failed to create hardware device context for %s", hwDecoderName);
                    hw_device_ctx = nullptr;  // 回退到软件解码
                    codec=nullptr;
                }
            }
        }
    }




    if (!codec) {
        codec = avcodec_find_decoder(codecId);
        if (!codec) {
            qWarning("No suitable decoder found");
            return false;
        }
        useHardwareAccel=false;
    }
    qDebug() << "Selected decoder:" << codec->name;

    if(useHardwareAccel){
        for (int i = 0;; i++) {
            const AVCodecHWConfig* config = avcodec_get_hw_config(codec, i);
            if (!config) {
                qWarning("Decoder %s does not support QSV", codec->name);
                return false;
            }
            qDebug() << "HW support method:" << config->methods << "Type:" << config->device_type;
            if (config->methods & AV_CODEC_HW_CONFIG_METHOD_HW_DEVICE_CTX &&
                config->device_type == hwType) {
                hwPixFmt = config->pix_fmt; // 记录硬件像素格式
                break;
            }
        }
    }


    videoCodecCtx=avcodec_alloc_context3(codec);
    avcodec_parameters_to_context(videoCodecCtx,stream->codecpar);
    if(useHardwareAccel&&hw_device_ctx){
        videoCodecCtx->pix_fmt=hwPixFmt;
        videoCodecCtx->hw_device_ctx = av_buffer_ref(hw_device_ctx); // 引用硬件设备上下文
        qDebug()<<"hwPixFmt"<<hwPixFmt;
        av_buffer_unref(&hw_device_ctx);
    }


    if(avcodec_open2(videoCodecCtx,codec,nullptr)<0){
        qWarning("failed to open video codec");
        return false;
    }

    videoTimeBase=stream->time_base;
    qDebug()<<"init video success";
    return true;
}

bool Decoder::initAudio(){
    audioStreamIdx = av_find_best_stream(fmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
    if (audioStreamIdx < 0) {
        qWarning("No audio stream found!");
        return false;
    }

    AVStream *stream = fmtCtx->streams[audioStreamIdx];
    const AVCodec *codec = avcodec_find_decoder(stream->codecpar->codec_id);
    if (!codec) {
        qWarning("Unsupported audio codec");
        return false;
    }

    audioCodecCtx = avcodec_alloc_context3(codec);
    avcodec_parameters_to_context(audioCodecCtx, stream->codecpar);
    if (avcodec_open2(audioCodecCtx, codec, nullptr) < 0) {
        qWarning("Failed to open audio codec");
        return false;
    }

    AVChannelLayout in_ch_layout, out_ch_layout;

    // 从 codecpar 中获取输入声道布局
    av_channel_layout_copy(&in_ch_layout, &stream->codecpar->ch_layout);

    // 设置输出为立体声布局
    av_channel_layout_from_mask(&out_ch_layout, AV_CH_LAYOUT_STEREO);

    swr_alloc_set_opts2(&swrCtx,
        &out_ch_layout,                     // 输出声道布局
        AV_SAMPLE_FMT_S16,                  // 输出采样格式
        stream->codecpar->sample_rate,      // 输出采样率
        &in_ch_layout,                      // 输入声道布局
        (AVSampleFormat)stream->codecpar->format, // 输入采样格式
        stream->codecpar->sample_rate,      // 输入采样率
        0, nullptr);

    // 清理临时布局
    av_channel_layout_uninit(&in_ch_layout);
    av_channel_layout_uninit(&out_ch_layout);

    swr_init(swrCtx);

    audioTimeBase = stream->time_base;
    qDebug()<<"init audio success,file len:"<<stream->duration*av_q2d(audioTimeBase)*1000;
    filelen=stream->duration*av_q2d(audioTimeBase)*1000;

    sncStream=sonicCreateStream(stream->codecpar->sample_rate,2);
    sonicSetSpeed(sncStream,playback_speed);
    return true;
}

QAudioFormat Decoder::getFormat(){
    QAudioFormat format;
    format.setSampleSize(16);
    format.setSampleRate(audioCodecCtx->sample_rate);
    format.setChannelCount(2);
    return format;
}

void Decoder::setSpeed(double speed){
    playback_speed=speed;
    sonicSetSpeed(sncStream,playback_speed);
}
void Decoder::seek(qint64 pos_ms){
    QMutexLocker locker(&seek_mutex);
    seek_target_pts=pos_ms*1000;
    qDebug()<<"seek target pts"<<seek_target_pts;
    need_seek=true;
    audioCnt.store(0);
    videoCnt.store(0);
}



void Decoder::run(){
    qDebug()<<"run";
    AVPacket *packet = av_packet_alloc();
    AVFrame *frame = av_frame_alloc();
    QElapsedTimer timer;
    timer.start();

    while (!abort) {
        {
            QMutexLocker locker(&mutex);
            while (paused&&!abort) {
                condition.wait(&mutex);
            }
            while((audioCnt>=MAX_AUDIO_BUFFER)&&!abort){//check mutex
                emit check();
                qDebug()<<videoCnt<<' '<<audioCnt;
                condition.wait(&mutex);
            }
        }

        if(need_seek){
            qDebug()<<"seek action";
            QMutexLocker locker(&seek_mutex);
            catch_up=false;
            avcodec_flush_buffers(videoCodecCtx);
            avcodec_flush_buffers(audioCodecCtx);

            avformat_seek_file(fmtCtx,-1,0,seek_target_pts,seek_target_pts,AVSEEK_FLAG_BACKWARD);

            need_seek=false;
            lastEmitVideoPts=0;
            lastEmitAudioPts=0;
        }
        int ret = av_read_frame(fmtCtx, packet);
        if (ret < 0) {
            if (ret == AVERROR_EOF) {
                qDebug()<<"emit finished";
                emit finished();
                break;
            }
            continue;
        }

        // 视频解码
        if (packet->stream_index == videoStreamIdx) {

            ret = avcodec_send_packet(videoCodecCtx, packet);
            while (ret >= 0) {
                AVFrame* frame=av_frame_alloc();
                ret = avcodec_receive_frame(videoCodecCtx, frame);

                if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF){
                    av_frame_free(&frame);
                    break;
                }

                // 计算PTS（单位：毫秒）

                qint64 pts = av_rescale_q(frame->best_effort_timestamp, videoTimeBase, {1, 1000});
                // qint64 expectedPts=pts/playback_speed;
                if(seek_target_pts!=-1&&pts<seek_target_pts/1000-1000){
                    qDebug()<<"uncatch seek target ,skip"<<pts<<" "<<seek_target_pts;
                    continue;
                }
                if(pts/playback_speed<=lastEmitVideoPts/playback_speed&&lastEmitVideoPts!=0){
                    qDebug()<<"skip frame"<<pts<<" "<<lastEmitVideoPts;
                    continue;
                }
                lastEmitVideoPts=pts;


                AVFrame* sw_frame = av_frame_alloc();
                if(!sw_frame){
                    qDebug()<<"Failed to alloc sw_frame";
                    av_frame_free(&frame);
                    continue;
                }
                if(useHardwareAccel){
                    if (frame->hw_frames_ctx) {
                        int err = av_hwframe_transfer_data(sw_frame, frame, 0);
                        if (err < 0) {
                            char errbuf[AV_ERROR_MAX_STRING_SIZE];
                            av_strerror(err, errbuf, sizeof(errbuf));
                            qDebug() << "Transfer failed:" << errbuf
                                     << "| HW format:" << frame->format
                                     << "| SW format:" << sw_frame->format;

                            av_frame_free(&frame);
                            av_frame_free(&sw_frame);
                            continue;
                        }

                    } else {
                        av_frame_move_ref(sw_frame, frame);
                    }
                    av_frame_free(&frame);
                }
                else{
                    av_frame_ref(sw_frame, frame);
                    av_frame_free(&frame);
                }

                if (!swsCtx || sw_frame->format != videoCodecCtx->pix_fmt) {
                    if (swsCtx) {
                        sws_freeContext(swsCtx);
                    }
                    swsCtx = sws_getContext(
                        sw_frame->width, sw_frame->height,
                        (AVPixelFormat)sw_frame->format,
                        sw_frame->width, sw_frame->height,
                        AV_PIX_FMT_RGB32,
                        SWS_BILINEAR, nullptr, nullptr, nullptr
                        );

                    if (!swsCtx) {
                        qDebug() << "Failed to create SWS context for format:"
                                 << av_get_pix_fmt_name((AVPixelFormat)sw_frame->format);
                        av_frame_free(&sw_frame);
                        continue;
                    }
                }

                // // 转换YUV到RGB
                QImage image(sw_frame->width, sw_frame->height, QImage::Format_RGB32);
                uint8_t *dst[] = { image.bits() };
                int dstStride[] = { static_cast<int>(image.bytesPerLine()) };

                sws_scale(swsCtx, sw_frame->data, sw_frame->linesize, 0, sw_frame->height, dst, dstStride);
                emit videoFrameDecoded(image, pts);
                videoCnt.fetch_add(1, std::memory_order_relaxed);
                av_frame_free(&sw_frame);
                qint64 nowTime=timer.elapsed();
                qDebug()<<"pts & nowTime"<<pts<<"  "<<nowTime;
                if(catch_up&&lastDecodeIsVideo==false&&pts/playback_speed>nowTime/playback_speed){
                    qDebug()<<"sleep call by video's pts and nowtime"<<pts<<" "<<nowTime;
                    av_usleep((pts-nowTime)/playback_speed);
                }
                lastDecodeIsVideo=true;
                if(pts>seek_target_pts){
                    catch_up=true;
                }
            }
        }

        // 音频解码
        else if (packet->stream_index == audioStreamIdx) {
            ret = avcodec_send_packet(audioCodecCtx, packet);
            while (ret >= 0) {
                ret = avcodec_receive_frame(audioCodecCtx, frame);
                if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
                    break;

                if(frame->best_effort_timestamp==AV_NOPTS_VALUE){
                    qDebug()<<"Invalid pts";
                    continue;
                }
                // 计算 PTS

                qint64 pts = av_rescale_q(frame->best_effort_timestamp, audioTimeBase, {1, 1000});
                // qint64 expectedAudioPts=pts/(playback_speed);
                if(pts<0){
                    // qDebug()<<"pts<0"<<pts<<" "<<expectedAudioPts;
                    continue;
                }
                if(pts<seek_target_pts/1000-1000){
                    continue;
                }
                // 计算输出缓冲区大小
                int out_samples = swr_get_out_samples(swrCtx, frame->nb_samples);


                // 分配重采样缓冲区
                uint8_t **resampled_data = nullptr;
                av_samples_alloc_array_and_samples(&resampled_data, nullptr,
                   2, // 输出声道数（立体声）
                   out_samples,
                   AV_SAMPLE_FMT_S16,
                   0
                   );

                // 执行重采样
                out_samples = swr_convert(swrCtx,
                  resampled_data, out_samples,        // 输出
                  (const uint8_t**)frame->data, frame->nb_samples // 输入
                  );



                // 发送音频数据（注意数据长度计算）
                // QByteArray buffer(
                //     reinterpret_cast<char*>(resampled_data[0]),
                //     out_samples * 2 * sizeof(int16_t) // 16-bit stereo: 2 声道 × 2 bytes
                //     );
                sonicWriteShortToStream(sncStream,(short*)resampled_data[0],out_samples);
                int num_samples=sonicSamplesAvailable(sncStream);

                QByteArray buffer;
                buffer.resize(num_samples*2*sizeof(short));
                int new_samples=sonicReadShortFromStream(sncStream,(short*)buffer.data(),num_samples);
                buffer.resize(new_samples*2*sizeof(short));

                qDebug()<<"emit audio:"<<pts/playback_speed<<' '<<pts;
                emit audioBufferDecoded(buffer, pts);
                audioCnt.fetch_add(1, std::memory_order_relaxed);
                // 清理资源

                qint64 nowTime=timer.elapsed();
                if(catch_up&&pts>nowTime&&lastDecodeIsVideo){
                    // qDebug()<<"delay call by audio"<<expectedAudioPts<<" "<<nowTime;
                    av_usleep((pts-nowTime)/playback_speed);
                }
                lastDecodeIsVideo=false;
                if(pts>seek_target_pts){
                    catch_up=true;
                }
                av_freep(&resampled_data[0]);
                av_freep(&resampled_data);
            }
        }

        av_packet_unref(packet);
    }

    av_packet_free(&packet);
    av_frame_free(&frame);
}
void Decoder::startDecoding() {
    QMutexLocker locker(&mutex);
    abort = false;
    paused = false;
    lastEmitAudioPts=0;
    lastEmitVideoPts=0;
    playback_speed=1;
    audioCnt.store(0);
    videoCnt.store(0);
    if (!isRunning()) {
        QThread::start(QThread::HighPriority);
    }
}

void Decoder::pauseDecoding() {
    QMutexLocker locker(&mutex);
    paused = true;
}

void Decoder::resumeDecoding() {
    QMutexLocker locker(&mutex);
    paused = false;
    condition.wakeAll(); // 唤醒被暂停的线程
}

void Decoder::stopDecoding() {
    {
        QMutexLocker locker(&mutex);
        abort = true;
        // paused=false;
        condition.wakeAll();
    }
    if (isRunning()) {
        qDebug()<<"wait"<<paused;
        wait();
    }
}

void Decoder::seekToStart() {
    QMutexLocker locker(&mutex);
    qDebug()<<"seek to start called";
    if (fmtCtx) {
        av_seek_frame(fmtCtx, -1, 0, AVSEEK_FLAG_BACKWARD);
        seek_target_pts=0;
        qDebug()<<"seek to 0";
        if (videoCodecCtx) avcodec_flush_buffers(videoCodecCtx);
        if (audioCodecCtx) avcodec_flush_buffers(audioCodecCtx);
    }
    else{
        need_seek=true;
        seek_target_pts=0;
        if (videoCodecCtx) avcodec_flush_buffers(videoCodecCtx);
        if (audioCodecCtx) avcodec_flush_buffers(audioCodecCtx);
    }
}

void Decoder::cleanup() {
    qDebug()<<"clean up";
    if (swsCtx) {
        sws_freeContext(swsCtx);
        swsCtx = nullptr;
    }
    if (videoCodecCtx) {
        avcodec_free_context(&videoCodecCtx);
        videoCodecCtx=nullptr;
    }

    // 释放音频资源
    if (swrCtx) {
        swr_free(&swrCtx);
        swrCtx=nullptr;
    }
    if (audioCodecCtx) {
        avcodec_free_context(&audioCodecCtx);
        audioCodecCtx=nullptr;
    }

    // 释放格式上下文
    if (fmtCtx) {
        avformat_close_input(&fmtCtx);
        fmtCtx=nullptr;
    }
    if (sncStream) {
        sonicDestroyStream(sncStream);
        sncStream = nullptr;
    }
}

void Decoder::setPlayTime(qint64 time){
    qDebug()<<"set playtime "<<time;
    playTime=time;
}


