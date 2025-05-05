#include "ui/mainwindow.h"

#include <QApplication>
#include<QDebug>
#include<QVector>
#include"core/sumTester.h"
#include "ui/summary.h"

// void testDecode(QApplication& app){
//     auto decoder=new Decoder();
//     auto videoTester=new VideoTester();
//     auto audioTester=new AudioTester();
//     QObject::connect(decoder, &Decoder::videoFrameDecoded, videoTester, &VideoTester::onVideoFrame);
//     QObject::connect(decoder, &Decoder::audioBufferDecoded, audioTester, &AudioTester::onAudioBuffer);
//     QObject::connect(decoder, &Decoder::finished, &app, &QCoreApplication::quit);
//     QObject::connect(decoder, &Decoder::finished, [=]() {
//         decoder->deleteLater();      // 安全释放内存
//         videoTester->deleteLater();
//         audioTester->deleteLater();
//     });
//     QString testFile = "D:\\Qtprojects\\mediaPlayer\\tests\\fk2.mp4";
//     if (!decoder->open(QUrl::fromLocalFile(testFile))) {
//         qCritical() << "Failed to open file";
//         return ;
//     }

//     decoder->startDecoding();
// }


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    MainWindow w;
//    w.show();

    Summary* page=new Summary();
    page->show();

    return app.exec();
}

