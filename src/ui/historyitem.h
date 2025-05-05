#ifndef HISTORYITEM_H
#define HISTORYITEM_H

#include <QApplication>
#include <QListWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QPushButton>
#include <QPixmap>
#include <QMouseEvent>
#include <QPainter>
#include <QDir>

class HistoryItem : public QWidget
{
    Q_OBJECT

public:    
    explicit HistoryItem(int type, const QString &fileName, const QString &duration, QListWidget *parentList, QListWidgetItem *listItem,QString Path,bool isliked=false,bool isunliked=false);


    ~HistoryItem();
private:
    //监听鼠标进入事件
    void enterEvent(QEvent *event);
    //监听鼠标离开事件
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    QPixmap createRoundedPixmap(const QPixmap &src, int radius);

signals:
    //之后可以带着相应文件的url，来实现播放
    void itemClicked( QString &fileName);
    //实现向ai页面的跳转
    void aiItemclicked(QString &fileName);
    //依次发送点赞，不喜欢，下载状态
    void likeItemClicked(QString &fileName, bool isliked, bool isUnliked);
    void unlikeItemClicked(QString &fileName, bool isliked, bool isUnliked);
    void downloadClicked(QString &fileName, bool isDownLoad);
    //发送添加到播放队列的信号
    void addToList(QString &fileName, QString &duration);

private slots:
    //响应删除按钮
    void removeItem();
    void changeToAi();
    void like();
    void unlike();
    void download();
    void addTolist();
public:
    void downloadfinished(QString);
    void m_highlightWords(QStringList words);

private:
    QPixmap closeIcon;
    QPixmap aiIcon;
    QPixmap likeIcon;
    QPixmap unlikeIcon;
    QPixmap downLoadIcon;
    QPixmap addIcon;

    QPushButton* aiButton;
    QPushButton* closeButton;
    QPushButton* likeButton;
    QPushButton* unlikeButton;
    QPushButton* downLoadButton;
    QPushButton* addButton;
    QLabel* fileLabel;
    QLabel* durationLabel;
    QListWidget *listWidget;
    QListWidgetItem *item;
    QString filePath;
    QString fileName;
    QString m_duration;
    int m_type;
    //点赞
    bool isLiked;
    //踩
    bool isUnliked;
    //是否下载完成
    bool isDownLoad;
    //是否添加到播放队列中
    bool isAdd;
    //播放类型
    int type;
};

#endif // HISTORYITEM_H
