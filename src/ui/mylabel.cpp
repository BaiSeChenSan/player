#include "mylabel.h"

myLabel::myLabel(QWidget *parent)
{
    this->setParent(parent);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    setAlignment(Qt::AlignCenter);

    /*
    QPalette palette = this->palette();
    palette.setColor(QPalette::WindowText,Qt::black);
    setPalette(palette);
    */

    show();
}

void myLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

//    QPainter painter(this);
//    painter.fillRect(this->rect(),QColor(255, 255, 0, 125));//绘制半透明的黄色
}
