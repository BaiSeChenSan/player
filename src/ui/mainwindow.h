#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QVideoWidget>
#include <QPushButton>
#include "../core/player.h"
#include"../core/glwidget.h"
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
#include "SettingsDialog.h"  // 引入子界面头文件
#include "Dialog.h"
#include "aboutdialog.h"
#include "systemdialog.h"
#include "mylabel.h"
#include "historyitem.h"
#include <QMovie>
#include <QShortcut>
#include<QRandomGenerator>
#include "recommend.h"
#include"pythonworker.h"
#include"../core/sumTester.h"
namespace Ui {
class MainWindow;
}

struct Srt
{
    qint16 Num;
    QTime Start;
    QTime End;
    QString Content;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // 视频信息结构体，用来保存播放列表的视频信息
      struct VideoInfo {
          QString path;           // 视频文件路径
          qint64 lastPlayTime;    // 上次播放位置（毫秒）
          qint64 duration;        // 视频总时长（毫秒）
          QString title;          // 视频标题（可选，从文件名提取或元数据）
      };
      //历史播放信息结构体，用来保存历史播放信息
      struct HistoryInfo{
          QString url; //视频路径
          QString title; //视频标题
          int isLiked; //是否点赞 -1:点踩，0:未评价，1:点赞
          int isDownload; //是否下载 0:未下载，1:已下载
          int watchTimes; //观看次数
          QDateTime lastTime; //最近一次观看时间
          int type; //0代表未定义，1代表本地视频，2代表推荐视频


          // 默认构造函数
          HistoryInfo() : isLiked(0), isDownload(0), watchTimes(0), type(0) {}

          // 从CSV行解析的构造函数
          explicit HistoryInfo(const QStringList& csvRow) {
              // 基础字段解析
              url = csvRow.value(0);
              title = csvRow.value(1);
              isLiked = csvRow.value(2).toInt();
              isDownload = csvRow.value(3).toInt();
              watchTimes = csvRow.value(4).toInt();
              // 时间解析
              lastTime = QDateTime::fromString(csvRow.value(5), "yyyy/M/d H:mm");
              type = csvRow.value(6).toInt();
          }

          // 转换为QStringList
          QStringList toQStringList() const {
              return {
                  url,
                  title,
                  QString::number(isLiked),
                  QString::number(isDownload),
                  QString::number(watchTimes),
                  lastTime.toString("yyyy/M/d H:mm"),
                  QString::number(type)
              };
          }
      };

private slots:
    void on_openBtn_clicked();

    void updateVoiceLabel(int value);


    void on_voiceSlider_valueChanged(int value);


    void on_playIcon_clicked();


    void on_lastIcon_clicked();

    void on_nextIcon_clicked();

    void on_stopIcon_clicked();

    void on_voiceIcon_clicked();

    void on_allButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_listButton_clicked();
    //void on_sideButton_clicked();

    void upDateSlider(qint64 position);

    void GetDuration(qint64 duration);

    void MoveVideo(int videoData);

    void onPlayerStateChanged();


    void on_setting_clicked();
    void stopPlayback();

    void on_slider_sliderMoved(int position);
    void on_slider_valueChanged(int value) ;
    void initRecommendList(QList<VideoData> &temp,int type=0);

    void on_min_clicked();

    void on_max_clicked();

    void on_close_clicked();

    void on_dayAndNight_clicked();
    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


    void updateCursorShape(const QPoint &pos);

    void adjustWindowSize(const QPoint &globalMousePos) ;

    void keyPressEvent(QKeyEvent *event) override;

    void MActionsSlot();
    void on_selectedButton_clicked();
    void on_openFolderButton_clicked();
    void onMenuAboutToShow();
    void onMenuAboutToHide();
    void closeMenuClicked();
    void clearRecordclicked();
    void setClearModeClicked();
    void systemDialogclicked();
    void aboutDialogclicked();

    void on_historyButton_clicked();
    void on_personalityButton_clicked();
    void on_aiButton_clicked();
    //void initHistoryList();
    void listChoosePlay(QString &fileName);
    void personalityChoosePlay(QString &fileName);

    void aiPlay(QString &fileName);

    //信号处理函数
    void receiveSignal(QString str,int index) ;

    void speedChanged(double speed);

    void sizeChanged(int widthRatio,int heightRatio);

    void rotateView(int choice);

    void updateVideoWidgetSize();


    void on_ai_clicked();

    void on_deleteListButton_clicked();
    //2025-3-2-subtitle
    bool called_orNot_addSrt(QString);
    void called_setSrt();

    //void on_AiLogo_clicked();
    void appendMessage(const QString message, QString type);

    void AiLogo_clicked();

    void onFilterSelected(QAction *action);
    void onSearchTextChanged();

    void on_analyse_button_clicked();

    void on_type_button_clicked();

    void on_playListBtn_clicked();
    void onSchemeSelected(QAction *action);
    void on_deleteAll_clicked();
    void on_refreshButton_clicked();
    void onPersonSearchTextChanged();


    void on_ui_keywordLike_clicked();

    void on_ui_keywordSearch_2_clicked();

    void on_ui_keywordLike_2_clicked();

    void on_ui_keywordSearch_clicked();

protected:
    void paintEvent(QPaintEvent* e);
    void resizeEvent(QResizeEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);
    //void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;

    // 标记鼠标当前所在的窗口区域
      enum CursorPosition {
          None,           // 无操作
          Top,            // 上边缘
          Bottom,         // 下边缘
          Left,           // 左边缘
          Right,          // 右边缘
          TopLeft,        // 左上角
          TopRight,       // 右上角
          BottomLeft,     // 左下角
          BottomRight,    // 右下角
          TitleBar        // 标题栏区域（可拖动）
      };

    QPixmap playIcon;     // 用于保存播放图标
    QPixmap pauseIcon;    // 用于保存暂停图标
    QPixmap nextIcon;     // 用于保存下一个图标
    QPixmap lastIcon;    // 用于保存上一个图标
    QPixmap stopIcon;    // 用于保存停止图标
    QPixmap voiceOnIcon;
    QPixmap voiceOffIcon;
    QPixmap allIcon;
    QPixmap offIcon;
    QPixmap background;  //用于保存背景图片
    QPixmap maxIcon;
    QPixmap minIcon;
    QPixmap closeIcon;
    QPixmap normalIcon;
    QPixmap logoIcon;
    QPixmap dayIcon;
    QPixmap nightIcon;


    //QPushButton play;



    bool isPlaying;       // 播放状态
    bool isSource;          //是否存在播放文件
    bool voiceOn;           //是否静音
    bool isopen;           //文件打开
    bool isFullScreen;     //全屏
    bool isListViewVisible;    //是否打开播放列表
    bool isMax;             //是否是最大化
    int originalWidth;         //初始列表宽度
    bool isDay;         //是否是白天模式
    int currentIndex;

   QTransform transform;
   bool flip = false;  // 水平翻转标志
   bool flipVertically = false;  // 垂直翻转标志
   bool isAdjusting=false;
   int currentAngle = 0;  // 当前旋转角度
   int videoAspectRatio = 16;  // 视频的宽高比，初始为 0，表示未设置

    QString totalFormatTime;
    QString currentFormatTime;
    qint64 step;
    QString formatTime(int seconds);  // 格式化时间为 HH:MM:SS 格式
    CursorPosition calculateCursorPosition(const QPoint &pos);
    QString accumulatedOutput; // 累积流式输出
    QString tags;

    sumTester *tester;
    //API测试
    QNetworkAccessManager *networkManager;
    void callDeepSeekApi();


    //创建动画
    void setupAnimation();
    //初始化背景
    void initPlayBcakground();
    //初始化打开按钮
    void initOpenButton();
    //初始化listbutton按钮的位置
    void initListButton();
    //初始化荧幕位置
    void initPlayLabel();
    //初始化播放栏的位置关系
    void initfunc();
    //初始化系统菜单栏
    void initSystemMenu();
    //初始化搜索框
    void initsearchFrame();

    //将本地文件的历史播放记录加载到播放列表中
       void loadHistory();
       //将历史播放列表保存到本地文件
       void saveHistory();
       void updateTags();

       //把QList<QStringList>转化成csv
       bool saveToCsvAdvanced(const QString& fileName, const QList<QStringList>& data);
       //把csv转化成QList<QStringList>
       QList<QStringList> readFromCsv(const QString& fileName);
       //解析csv文件到程序中
       bool readAndParseCsv(const QString& fileName);
       //将程序中历史记录的数据结构保存到本地csv文件中
       bool saveCsvRecords(const QString& fileName);
       //更新历史记录列表
       bool update_history_records(const QString& path_need_add, int type=0);

       //初始化播放列表
      void initPlayList();


      //初始化个性化推荐
      void  initPersonFrame();
    //创建对应的成员变量
    Player* pPlayer;
    //QMediaPlaylist* pPlayerList;
    GLWidget* pVideoWidget;

    QList<VideoInfo> historyList;  // 播放列表
    QList<HistoryInfo> historyRecords;//真正的历史记录，上面那个是播放列表

    QPropertyAnimation *animation;
    QTimer *hideListButtonTimer;
    QMenu* m_menu1;
    aboutDialog* aboutdialog;

    CursorPosition m_cursorPos;   // 当前鼠标位置状态
    QPoint m_dragStartPos;        // 拖动起始位置
    QRect m_geometryBeforeDrag;   // 拖动前的窗口几何信息

    SettingsDialog* settingsDialog;
    SystemDialog* systemDialog;

    // 创建 QGraphicsScene 和 QGraphicsView
   QGraphicsScene *scene = new QGraphicsScene();
   //QGraphicsView *view = new QGraphicsView(scene);

   //2025-3-2-subtitle
   myLabel *m_subtitle ;
   void writeSubtitle(QString);
   QList<Srt>   m_srtList;

   QHash<QProcess*, QDateTime> m_processTimestamps;  // 时间戳管理

   QString videoFilePath;
   recommend *m_recommendVideos;
   int m_index_List=-2;

   //2025-4-9 thread python
   PyThreadState* m_mainTS ;
   QStringList* m_downloading_list={};
   QList<VideoData> m_playlist;
   QSet<QString> m_keywordsSelected={};
   void init_playlist(QList<VideoData> &temp);
   void init_historylist();
   void ui_playlistChoosePlay(QString &fileName);
   void ui_playlistChoosePlay2(QString &fileName); //为了在播放列表播放本地视频
   void history_playlistChoose(QString &fileName); //为了在历史列表播放本地视频
public:
   void m_download_historyitem(QString fileName, bool isdownloaded);
   void m_pythonTaskStart(const QString& pythonName,const QString& funcName,const QStringList& params) ;
   void m_handleFinishedPythonTask(QString py,QString func,QStringList par);
   void m_searchVideo();
   void onPythonScriptFinished();

signals:
   void m_downloadfinished_history(QString);


};

#endif // MAINWINDOW_H
