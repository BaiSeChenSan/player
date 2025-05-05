#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QLabel>
#include <QPainter>
#include <QFont>

class myLabel:public QLabel
{
    Q_OBJECT
public:
    myLabel(QWidget *parent=nullptr);
    virtual void paintEvent(QPaintEvent *event) override;

    QFont *font;

};

#endif // MYLABEL_H
