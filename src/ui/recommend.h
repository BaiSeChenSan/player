#ifndef RECOMMEND_H
#define RECOMMEND_H

#include <QDialog>
#include <QVideoWidget>
#include <QPushButton>
#include <QPixmap>
#include <QMouseEvent>  // 添加这个头文件用于处理鼠标事件
#include <QPushButton>
#include <QMediaPlayer>
#include <QTime>
#include <QTimer>
#include <QPoint>
#include <QFileDialog>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QPaintEvent>
#include <QPropertyAnimation>
#include <QResizeEvent>
#include <QIcon>
#include <QMenu>
#include <QDebug>
#include <QSettings>
#include <QMessageBox>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QList>
#include <QTextCodec>
#include <QGridLayout>
#include <QtWidgets/QLabel>
#include <QRandomGenerator>


struct VideoData {
    int id;
    QString filename;
    QStringList tags;
    int emotion;
    QStringList keywords;
    QString typeContent;
    QString typeForm;
    int duration;
    int isDownloaded;
    QString uri;
    QStringList source;
    int isWatched;
    bool isLiked;
    bool isUnliked;
    int rank;
    QDateTime dateTime;
};



struct RCMD_Stats {
    QMap<QString, QPair<double, int>> typeContentStats; // typeContent -> (avgRank, count)
    QMap<QString, QPair<double, int>> typeFormStats;    // typeForm -> (avgRank, count)
    QMap<QString, QPair<double, int>> keywordStats;     // keyword -> (avgRank, count)
};


class recommend : public QDialog
{
    Q_OBJECT

public:
    explicit recommend(QWidget *parent = nullptr);
    ~recommend();


    QString m_filepath;
    QList<VideoData> m_historyVideos;
    QList<VideoData> m_allVideos;
    QList<VideoData> m_rcmdVideos;


    void init();
        QList<VideoData> readCSV(const QString& filePath);

    QString m_path_csv;

    void m_getRCMDrefreshed();
        RCMD_Stats m_computeStatistics(const QList<VideoData>& historyVideos);
        QPair<int,QStringList> m_computePredictedRank(const VideoData& video, const RCMD_Stats& stats);
        void m_get_predictRanks(const QList<VideoData>& historyVideos, QList<VideoData>& allVideos);
        void m_debugStats(const RCMD_Stats& stats) const;
        // 统计 HV 的 Type 和 Keywords 数据
    void m_getSearchResult();

};

#endif // RECOMMEND_H
