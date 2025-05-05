#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QObject>
#include<QImage>
#include<QPainter>
#include<QDebug>
#include<QTimer>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include<QMutex>
#include<QFile>

class GLWidget : public QWidget {
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = nullptr) : QWidget(parent) {
        setAttribute(Qt::WA_OpaquePaintEvent); // 避免背景重绘
    }

    void setFrame(const QImage &frame) {
        qDebug()<<"set frame";
        currentFrame=frame;
        this->update();
        setCnt++;
    }

    void summarize(){
        qDebug()<<"set cnt & paint cnt"<<setCnt<<" "<<paintCnt;
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.drawImage(this->rect(), currentFrame);
        paintCnt++;
    }

private:
    QImage currentFrame;
    qint64 setCnt=0;
    qint64 paintCnt=0;
};
#endif // GLWIDGET_H
