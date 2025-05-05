#ifndef SUMTESTER_H
#define SUMTESTER_H
#include <QObject>
#include <QImage>
#include <QDebug>

class sumTester : public QObject {
    Q_OBJECT
public:
    sumTester() {
        QStringList fileNames = { "../web/img/关键词-词云图.png",
                                 "../web/img/视频内容雷达图.png",
                                 "../web/img/观看时段图.png" };
        for (const QString &fileName : fileNames) {
            QImage image(fileName);
            if (!image.isNull()) {
                v.append(image);
            } else {
                qDebug() << "Failed to load image:" << fileName;
            }
        }
    }

    // 添加方法获取图片数据
    QVector<QImage> getImages() const { return v; }

public slots:
    void handleRequest(QString s) {
        emit sendData(v);
    }

signals:
    void sendData(QVector<QImage> v);

private:
    QVector<QImage> v;
};

#endif // SUMTESTER_H
