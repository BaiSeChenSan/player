#include "MainWindow.h"
#include "./ui_mainwindow.h"
#include "SettingsDialog.h"  // 引入子界面头文件
#include "systemdialog.h"
#include "aboutdialog.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include<QDebug>
#include"../core/player.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),step(5)
{
    qDebug()<<"currentpath in main first"<<QDir::currentPath();
     setWindowFlag(Qt::FramelessWindowHint);  // 去掉标题栏和边框
//    setAttribute(Qt::WA_NoSystemBackground);
    ui->setupUi(this);
    ui->AiLogo->installEventFilter(this);  // 安装事件过滤器
    ui->tags->setAttribute(Qt::WA_StyledBackground, true);
    ui->tags->setStyleSheet(
        "QWidget {"
        "background: qlineargradient(x1:0 y1:0 x2:1 y2:1 stop:0 #1e293b stop:1 #334155);"
        "border-radius: 12px;"
        "border: 1px solid #475569;"
        "box-shadow: 0 4px 12px rgba(0,0,0,0.2);"
        "padding: 10px;"
        "}"
    );

    // 绑定快捷键
    connect(new QShortcut(QKeySequence(Qt::Key_Escape), this), &QShortcut::activated, this, &MainWindow::close);

    connect(new QShortcut(QKeySequence(Qt::Key_Left), this), &QShortcut::activated, this, [=]() {
        qDebug() << "666";
        qint64 position = pPlayer->position();
        qint64 newPosition = position - step * 1000;
        pPlayer->setPosition(qMax(newPosition, 0LL));
    });

    connect(new QShortcut(QKeySequence(Qt::Key_Right), this), &QShortcut::activated, this, [=]() {
        qDebug() << "777";
        qint64 position = pPlayer->position();
        qint64 newPosition = position + step * 1000;
        pPlayer->setPosition(qMin(newPosition, pPlayer->duration()));
    });

    connect(new QShortcut(QKeySequence(Qt::Key_Up), this), &QShortcut::activated, this, [=]() {
        qDebug() << "888";
        int currentVolume = pPlayer->volume();
        int setVol = qMin(currentVolume + 10, 100);
        pPlayer->setVolume(setVol);
        ui->voice->setText(QString("%1%").arg(setVol));
        ui->voiceSlider->setValue(setVol);
    });

    connect(new QShortcut(QKeySequence(Qt::Key_Down), this), &QShortcut::activated, this, [=]() {
        qDebug() << "999";
        int currentVolume = pPlayer->volume();
        int setVol = qMax(currentVolume - 10, 0);
        pPlayer->setVolume(setVol);
        ui->voice->setText(QString("%1%").arg(setVol));
        ui->voiceSlider->setValue(setVol);
    });

    connect(new QShortcut(QKeySequence(Qt::Key_Space), this), &QShortcut::activated, this, [=]() {
        ui->playIcon->click();
    });

    //gif动态图
    QPixmap pixmap(":/new/prefix1/icons/no1.ico");
    QIcon icon(pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    QMovie *movie = new QMovie(":/new/prefix1/icons/ai.gif");
    movie->setCacheMode(QMovie::CacheAll);
    ui->AiLogo->setMovie(movie);
    movie->start();


    // 设置窗口标题
    //setWindowTitle("Lumos Player");
    setAttribute(Qt::WA_OpaquePaintEvent);
    //2025-3-3-subtitle
    systemDialog = new SystemDialog(0,this);

    // 初始化图片
    playIcon.load(":/new/prefix1/icons/play.svg");
    pauseIcon.load(":/new/prefix1/icons/pause.svg");
    nextIcon.load(":/new/prefix1/icons/next.svg");
    lastIcon.load(":/new/prefix1/icons/last.svg");
    stopIcon.load(":/new/prefix1/icons/stop.svg");
    voiceOnIcon.load(":/new/prefix1/icons/voice-on.svg");
    voiceOffIcon.load(":/new/prefix1/icons/voice-off.svg");
    allIcon.load(":/new/prefix1/icons/all.svg");
    offIcon.load(":/new/prefix1/icons/off.svg");
    maxIcon.load(":/new/prefix1/icons/max.svg");
    minIcon.load(":/new/prefix1/icons/min.svg");
    closeIcon.load(":/new/prefix1/icons/close.svg");
    normalIcon.load(":/new/prefix1/icons/normal.svg");
    logoIcon.load(":/new/prefix1/icons/logo.svg");
    dayIcon.load(":/new/prefix1/icons/days.svg");
    nightIcon.load(":/new/prefix1/icons/nights.svg");

    initOpenButton();
    initPlayBcakground();
    initListButton();
    initPlayLabel();
    initSystemMenu();
    //initfunc();
    ui->playListBtn->setToolTip("播放列表");
    ui->historyButton->setToolTip("播放历史");
    ui->aiButton->setToolTip("AI分析");
    ui->personalityButton->setToolTip("个性推荐");
    //初始化搜索页面
    initsearchFrame();
    //初始化播放列表中的顶部栏
    initPlayList();
    //初始化播放列表的顶部栏
    initPersonFrame();
    this->installEventFilter(this);  // 在构造函数中注册
    // 设置默认图标
    ui->playIcon->setIcon(pauseIcon);
    ui->lastIcon->setIcon(lastIcon);
    ui->nextIcon->setIcon(nextIcon);
    ui->stopIcon->setIcon(stopIcon);
    ui->voiceIcon->setIcon(voiceOnIcon);
    ui->playIcon->setIcon(playIcon);  // 设置为暂停图标
    ui->allButton->setIcon(allIcon);
    ui->dayAndNight->setIcon(nightIcon);


    ui->min->setIcon(minIcon);
    ui->max->setIcon(maxIcon);
    ui->close->setIcon(closeIcon);


//    ui->comboBox->setCurrentIndex(2);  //设定当前的combox中显示的倍率
//    ui->comboBox->setView(new  QListView());

    ui->slider->installEventFilter(this);  // 让 MainWindow 监听 slider 事件


    // 初始化播放状态
    isPlaying = false;  // 初始状态为暂停
    // 初始化播放资源的加载状况
    isSource = false;
    //ui->comboBox->setEnabled(false);
    //初始化音量
    voiceOn = true;
    //初始化
    isopen=false;

    currentIndex = -1;
    isFullScreen=false;
    // 连接 QSlider 的 valueChanged 信号到槽函数
    //connect(ui->slider, &QSlider::valueChanged, this, &MainWindow::on_slider_valueChanged);

    //初始化创建播放器等对象
    pPlayer=new Player(this);;          //播放器对象,即电影放映员
    //pPlayerList= new QMediaPlaylist;    //播放器队列对象，即电影胶带
    pVideoWidget = new GLWidget(ui->playlabel);    //显示视频界面对象，即电影屏幕


    // 启用主窗口的鼠标跟踪
    setMouseTracking(true);

    hideListButtonTimer = new QTimer(this);
    connect(hideListButtonTimer, &QTimer::timeout, this, [this]() {
            ui->listButton->hide();
        });

    show();
    //设置播放器的播放队列
    //pPlayer->setPlaylist(pPlayerList);
    //设置播放器的显示窗口
    pPlayer->setVideoOutput(pVideoWidget);

    //对于播放列表界面的设定
    isListViewVisible = true;
    ui->listButton->setText(">");
    originalWidth = ui->listView->width();
    //用于添加动画效果
    setupAnimation();

//    loadHistory(); //FIXME 3
    readAndParseCsv(QString("../mediaplayer-main/history/history_records.csv"));


    isMax=false;
    isDay=true;
    on_dayAndNight_clicked();

    connect(pPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(GetDuration(qint64)));     //获取总时间
    connect(pPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(upDateSlider(qint64)));
    //connect(ui->slider, SIGNAL(sliderMoved(int)), this, SLOT(MoveVideo(int)));              //拖动进度条
    connect(ui->slider, &QSlider::valueChanged, this, &MainWindow::on_slider_valueChanged);   //点击进度条
    connect(pPlayer, SIGNAL(stateChanged()), this, SLOT(onPlayerStateChanged()));

    // 创建子界面（功能设置界面）
    settingsDialog = new SettingsDialog(this);

    //子界面传过来的信号的连接
    connect(settingsDialog, &SettingsDialog::buttonClicked, this, &MainWindow::receiveSignal);
    connect(settingsDialog, &SettingsDialog::speedChanged, this, &MainWindow::speedChanged);
    connect(settingsDialog, &SettingsDialog::sizeChanged, this, &MainWindow::sizeChanged);
    connect(settingsDialog, &SettingsDialog::rotateView, this, &MainWindow::rotateView);
    //2025-3-2-subtitle
    connect(settingsDialog, SIGNAL(call_addSrt(QString)), this,SLOT(called_orNot_addSrt(QString)));
    connect(systemDialog,SIGNAL(call_apply_setting_Srt()),this,SLOT(called_setSrt()));


    m_subtitle=new myLabel(ui->videoPlay);
    // 设置标签文本
    called_setSrt();
    //m_subtitle->setText("这里是字幕^w^");
    m_subtitle->resize(ui->videoPlay->width(),ui->videoPlay->height()/3);
    double x=ui->videoPlay->mapToGlobal(QPoint(0, 0)).x();
    double y=ui->videoPlay->mapToGlobal(QPoint(0, 0)).y();
    m_subtitle->move(x+ui->videoPlay->width()/2-m_subtitle->width()/2,y+ui->videoPlay->height()*3/4);
    m_subtitle->show();
    //m_subtitle->hide();
    updateVideoWidgetSize();

    //用于添加播放历史
    // initHistoryList();
     m_recommendVideos=new recommend();
     initRecommendList(m_recommendVideos->m_rcmdVideos);

    
     //2025-4-9 python thread
     //Py_SetPythonHome(L"E:/XYG/mediaplayer-main/mediaplayer-main/Python312");

     Py_Initialize();
     m_mainTS = PyEval_SaveThread();
     qDebug() << "Current path:" << QDir::currentPath();

}

MainWindow::~MainWindow()
{
    qDebug()<<"~mainwindow called";
    delete ui;
    if (pPlayer) {
        if(!pPlayer->getUrl().isEmpty()) pPlayer->stop();
        // player->pause();
        delete pPlayer;
    }
//    saveHistory(); // FIXME 1
    saveCsvRecords(QString("../mediaplayer-main/history/history_records.csv"));

    //2025-4-9 python thread
    PyEval_RestoreThread(m_mainTS);
    Py_Finalize();
}

//用于初始化播放列表中的播放模式选择和删除播放队列
void MainWindow::initPlayList(){
    QMenu* filterMenu = new QMenu(this);
    filterMenu->addAction("顺序播放");
    filterMenu->addAction("列表循环");
    filterMenu->addAction("随机播放");

    ui->scheme->setMenu(filterMenu);
    ui->scheme->setToolTip("播放模式");
    ui->deleteAll->setToolTip("清空");

    //样式调整
    filterMenu->setStyleSheet(R"(
        QMenu {
            background-color: #f0f0f0;
            border: 1px solid #ccc;
            padding: 5px;
            font-size: 18px;
        }

        QMenu::item {
            padding: 5px 20px;
            color: #333;
        }

        QMenu::item:selected {
            background-color: #0078d7;
            color: white;
        }
    )");

    //将筛选框于按钮进行绑定
    connect(filterMenu, &QMenu::triggered, this, &MainWindow:: onSchemeSelected);

}

//对于用户播放模式选择响应
void MainWindow:: onSchemeSelected(QAction *action) {
    QString currentFilter = action->text();
     ui->scheme->setText(currentFilter);

}
//对于删除所有历史记录进行响应、
void MainWindow:: on_deleteAll_clicked(){
    qDebug()<<"删除列表所有播放记录";
}


//初始化历史记录相关搜索框等组件
void MainWindow:: initsearchFrame(){
    QMenu* filterMenu = new QMenu(this);
    filterMenu->addAction("全部");
    filterMenu->addAction("推荐");
    filterMenu->addAction("历史");

    ui->filterButton->setMenu(filterMenu);
    ui->filterButton->setToolTip("筛选");

    //样式调整
    filterMenu->setStyleSheet(R"(
        QMenu {
            background-color: #f0f0f0;
            border: 1px solid #ccc;
            padding: 5px;
            font-size: 18px;
        }

        QMenu::item {
            padding: 5px 20px;
            color: #333;
        }

        QMenu::item:selected {
            background-color: #0078d7;
            color: white;
        }
    )");

    //将筛选框于按钮进行绑定
    connect(filterMenu, &QMenu::triggered, this, &MainWindow::onFilterSelected);

        // 搜索框 + 图标
    ui->searchLine->setPlaceholderText("请输入搜索内容...");

    QAction *searchIcon = new QAction(QIcon(":/new/prefix1/icons/search.svg"), "", this);
    ui->searchLine->addAction(searchIcon, QLineEdit::LeadingPosition);

    //对于搜索框可以让用户点击回车进行搜索和按下搜索图标进行搜索
    connect(ui->searchLine, &QLineEdit::returnPressed, this, &MainWindow::onSearchTextChanged);
    connect(searchIcon, &QAction::triggered, this, &MainWindow::onSearchTextChanged);

}

//对于用户筛选条件选择响应
void MainWindow::onFilterSelected(QAction *action) {
    QString currentFilter = action->text();
     ui->filterButton->setText(currentFilter);

}


//对于用户搜索事件的响应
void MainWindow::onSearchTextChanged() {
    qDebug()<<ui->searchLine->text();
    //emit searchTriggered(searchEdit->text(), currentFilter);
}

//初始化个性推荐界面
void MainWindow:: initPersonFrame(){
        // 搜索框 + 图标
    ui->lineEdit->setPlaceholderText("想看什么？告诉我吧！");
    ui->refreshButton->setToolTip("刷新");
    QAction *searchIcon = new QAction(QIcon(":/new/prefix1/icons/search.svg"), "", this);
    ui->lineEdit->addAction(searchIcon, QLineEdit::LeadingPosition);

    //对于搜索框可以让用户点击回车进行搜索和按下搜索图标进行搜索
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::onPersonSearchTextChanged);
    connect(searchIcon, &QAction::triggered, this, &MainWindow::onPersonSearchTextChanged);
}
//对于用户搜索事件的响应
/*
void MainWindow::onPersonSearchTextChanged() {
    //emit searchTriggered(searchEdit->text(), currentFilter);
    m_recommendVideos->m_rcmdVideos.clear();
    ui->personilityList->clear();
    QString text=ui->lineEdit->text();
    qDebug()<<"onPersonSearch..:"<<text;
    QStringList enter=text.split(' ',Qt::SkipEmptyParts);

    int num_found=0;
    for(auto a : this->m_recommendVideos->m_allVideos){
        if(num_found>=6)break;
        bool found=false;
        for (auto e : enter){
            if(a.filename.contains(e) ){
                found=true;
                break;
            }
            if(!found){
                for(auto j: a.tags){
                    if(j.contains(e)){
                        found=true;
                        break;
                    }
                }
            }
        }
        if(found){
             num_found+=1;
             qDebug()<<a.filename;
             m_recommendVideos->m_rcmdVideos+=a;
        }
    }


    int sz=m_recommendVideos->m_allVideos.size();
    while(num_found<6){
        auto a=m_recommendVideos->m_allVideos[QRandomGenerator::global()->bounded(sz)];
        m_recommendVideos->m_rcmdVideos+=a;
        num_found+=1;
    }

    initRecommendList(m_recommendVideos->m_rcmdVideos);
    ui->personilityList->update();

}
*/

void MainWindow::onPersonSearchTextChanged() {
    QString text=ui->lineEdit->text();
    qDebug()<<"onPersonSearch..:"<<text;
    QMessageBox::information(NULL,"提示","分析用户需求并搜索中..."+text);

    QString n_text = text.simplified(); // 去除多余空格，合并多个空格为单个空格
    n_text.replace("\"", "\\\"");       // 转义双引号
    n_text.replace("'", "\\'");         // 转义单引号


    QDir baseDir(QDir::currentPath());
    baseDir.cdUp();
    baseDir.cd("mediaplayer-main");
    baseDir.cd("mediaplayer-main");

    QString basePath = baseDir.absolutePath();
    QString pythonBasePath = basePath + "/py312";
    QString pythonPath = baseDir.filePath("Python312/python.exe");
    QString scriptPath = baseDir.filePath("src/TEST_QT_BV_Working.py"); // 这里放 Python 脚本文件名

    // 其余代码保持不变
    QProcess* process = new QProcess(this);
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert("PATH", pythonBasePath + "/Library/bin;" + env.value("PATH"));
    env.insert("PYTHONPATH", pythonBasePath);
    process->setProcessEnvironment(env);

    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [=](int exitCode, QProcess::ExitStatus exitStatus) {
        if (exitStatus == QProcess::NormalExit && exitCode == 0) {
            onPythonScriptFinished();
        }
        process->deleteLater();
    });

    qDebug()<<n_text;

    process->start(pythonPath, QStringList() << scriptPath << n_text);
    if (!process->waitForStarted()) {
        qDebug() << "Failed to start Python process";
    }
}


void MainWindow::onPythonScriptFinished()
{
    QMessageBox::information(NULL,"提示","搜索完成");
    m_recommendVideos->m_getSearchResult();
    ui->personilityList->clear();
    initRecommendList(m_recommendVideos->m_rcmdVideos,1);
    ui->stackedWidget->setCurrentWidget(ui->personilityList);
}

//个性推荐刷新
 void MainWindow:: on_refreshButton_clicked(){
    qDebug()<<"刷新按钮";
    ui->personilityList->clear();
    m_recommendVideos->m_getRCMDrefreshed();
    initRecommendList(m_recommendVideos->m_rcmdVideos);
 }


 void MainWindow::initRecommendList(QList<VideoData> &temp,int  type){
     for(int i=0;i<temp.size();i++){
         qDebug()<<temp[i].filename;
     }

     for (auto &data : temp) {
         QListWidgetItem* item = new QListWidgetItem(ui->personilityList);
        // item->setSizeHint(QSize(300, 40));
         HistoryItem *historyItem;
         if(type==1) historyItem= new HistoryItem(1, data.filename, "推荐理由："+data.typeContent, ui->personilityList, item,m_recommendVideos->m_filepath,data.isLiked,data.isUnliked);
         else if(type==0) historyItem= new HistoryItem(1, data.filename, data.typeContent+" / "+data.typeForm+"\n评估值:"+QString::number(data.rank), ui->personilityList, item,m_recommendVideos->m_filepath,data.isLiked,data.isUnliked);


         historyItem->m_highlightWords(data.source);
         connect(historyItem, &HistoryItem::itemClicked, this, &MainWindow::personalityChoosePlay);
         connect(historyItem,&HistoryItem::downloadClicked,this,&MainWindow::m_download_historyitem);
         connect(this,&MainWindow::m_downloadfinished_history,historyItem,&HistoryItem::downloadfinished);
         //connect(historyItem, &HistoryItem::aiItemclicked, this,&MainWindow::aiPlay);
         connect(historyItem, &HistoryItem::likeItemClicked, this, [&](QString filename,bool islike,bool isunlike){
             data.isLiked=islike;
             data.isUnliked=isunlike;
             qDebug()<<"in mainwindow.cpp data:"<<data.filename<<data.isLiked<<data.isUnliked;

             for(auto t:m_recommendVideos->m_rcmdVideos){
                 if(t.filename==filename)
                     qDebug()<<"in mainwindow.cpp t[data]:"<<t.filename<<t.isLiked<<t.isUnliked;
             }
         });
         connect(historyItem,&HistoryItem::addToList,this, [&](QString filename,QString duration) {
            VideoData a;
            a.filename=filename;
            for(auto &t:m_recommendVideos->m_rcmdVideos){
                if(t.filename==filename){
                    qDebug()<<"in mainwindow.cpp when addtolist():"<<t.filename;
                    a=t;
                }
            }
            a.typeContent=duration;
            m_playlist<<a;
         });
         ui->personilityList->setItemWidget(item, historyItem);
     }
     ui->personility->update();

 }



//初始化系统菜单栏
void MainWindow::initSystemMenu(){
    //初始化应用名称处的按钮
    ui->selectedButton->setText("Lumos Player");
    m_menu1 = new QMenu(this);
    QMenu* fileMenu = m_menu1->addMenu(QIcon(":/new/prefix1/icons/file.svg"),"文件");

    //文件栏
    fileMenu->addAction("打开文件",this,SLOT(on_openBtn_clicked()));
    fileMenu->addAction("打开文件夹",this,SLOT(on_openFolderButton_clicked()));
    QMenu* recentFile = fileMenu->addMenu("最近播放");
    recentFile->addAction("清除最近文件",this,SLOT(MActionsSlot()));
    //添加一个分界线
    recentFile->addSeparator();
    //然会需要根据最近的相关记录来进行添加menu


    //隐私栏
    QMenu* privicyMenu = m_menu1->addMenu(QIcon(":/new/prefix1/icons/privicy.svg"),"隐私");
    privicyMenu->addAction("清除播放痕迹",this,SLOT(clearRecordclicked()));
    privicyMenu->addAction("开启无痕播放",this,SLOT(setClearModeClicked()));

    //设置栏
    QMenu* settingMenu = m_menu1->addMenu(QIcon(":/new/prefix1/icons/setting2.svg"),"设置");
    settingMenu->addAction("系统设置",this,SLOT(systemDialogclicked()));
    settingMenu->addAction("播放设置",this,SLOT(systemDialogclicked()));
    settingMenu->addAction("字幕设置",this,SLOT(systemDialogclicked()));
    settingMenu->addAction("鼠标热键",this,SLOT(systemDialogclicked()));

    //帮助栏
    QMenu* helpMenu = m_menu1->addMenu(QIcon(":/new/prefix1/icons/help.svg"),"帮助");
    //helpMenu->addAction("在线升级",this,SLOT(MActionsSlot()));
    helpMenu->addAction("关于",this,SLOT(aboutDialogclicked()));

    //退出栏
   // QMenu* exitMenu = m_menu1->addMenu(QIcon(":/new/prefix1/icons/exit.svg"),"退出");
    m_menu1->addAction(QIcon(":/new/prefix1/icons/exit.svg"),"退出",this,SLOT(closeMenuClicked()));


    // 设置字体和文字对齐方式
    QFont font;
    font.setPointSize(12);  // 设置字体大小
    m_menu1->setFont(font);
    fileMenu->setFont(font);
    recentFile->setFont(font);
    privicyMenu->setFont(font);
    settingMenu->setFont(font);
    helpMenu->setFont(font);

    //设计样式表
    m_menu1->setStyleSheet(
        "QMenu {"
        "background-color: #404244;"              // 设置背景颜色
        "color: #ffffff;"
        "border: 1px solid #444444;"            // 设置边框颜色
        "selection-background-color: #0096ff;"  // 设置选中项的背景颜色
        "selection-color: #ffffff;"               // 设置选中项的文字颜色
        "min-width: 200px;"                     // 增加菜单的宽度
        "min-height: 60px;"
        "}"
        "QMenu::item {"
        "color: #dddddd;"                         // 设置文字颜色
        "padding: 5px 5px 5px 60px;"                    // 设置文字和图标的左右内边距
         "min-width: 200px;"
         "min-height: 40px;"
        "align: left;"                          // 设置文字和图标的对齐方式
        "}"
        "QMenu::item:selected {"
        "background-color: #0096ff;"            // 设置选中菜单项的背景色
        "}"
        "QMenu::indicator {"
        "width: 12px; height: 12px;"            // 设置箭头的宽度和高度
        "}"
        "QAction {"
        "font-size: 12px;"                      // 设置字体大小
        "color: white;"                         // 设置字体颜色
        "padding-left: 10px;"                   // 设置左边距
        "}"
        "QMenu::icon {"
        "padding-left: 20px;"
        "margin-left: 10px;"                   // 设置图标和文字之间的右边距
        "}"

    );

    //添加菜单的点击后的显示的图标
    connect(m_menu1, &QMenu::aboutToShow, this, &MainWindow::onMenuAboutToShow);
    connect(m_menu1, &QMenu::aboutToHide, this, &MainWindow::onMenuAboutToHide);

}

void MainWindow::aboutDialogclicked(){

    //创建关于的对象
    aboutdialog = new aboutDialog(this);
    aboutdialog->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    aboutdialog->size(),
                    this->geometry()  // 相对于主窗口的几何区域
                )
            );
    aboutdialog->exec();
}
void MainWindow::systemDialogclicked(){
    //确定用户选中的具体选项
    QAction *action = qobject_cast<QAction *>(sender());
    int selectednum = 0;
        if (!action) return;

        QString actionText = action->text(); // 获取选中的菜单项文本

        if (actionText == "系统设置") {
            selectednum = 0;
        } else if (actionText == "播放设置") {
           selectednum = 1;
        } else if (actionText == "字幕设置") {
             selectednum = 3;
        } else if (actionText == "鼠标热键") {
           selectednum = 5;
        }

    //2025-3-3-subtitle
    systemDialog->setRow(selectednum);

    // 设置子界面相对于主界面的位置
    systemDialog->setGeometry(
           QStyle::alignedRect(
               Qt::LeftToRight,
               Qt::AlignCenter,
               systemDialog->size(),
               this->geometry()  // 相对于主窗口的几何区域
           )
       );
    // 显示子界面
    systemDialog ->exec();  // 弹出并阻塞等待用户操作
}

//清除播放记录
void MainWindow::clearRecordclicked(){
    //这个需要根据播放记录的具体的存储方式来实现
    //配置文件 (例如 .ini 文件)：可以使用 Qt 提供的 QSettings 类来存储和读取配置文件（.ini 文件），其中保存用户的播放记录、播放历史、当前播放位置等信息。使用配置文件可以简单快速地记录这些信息。
    qDebug()<<"清除播放记录";
}

//开启无痕模式
void MainWindow::setClearModeClicked(){
    //
    qDebug()<<"开启无痕模式";
}
//打开文件夹
void MainWindow::on_openFolderButton_clicked(){
    // 打开文件夹选择对话框
    QString folderPath = QFileDialog::getExistingDirectory(
        this,                      // 父窗口
        "选择文件夹",               // 对话框标题
        QDir::homePath(),           // 默认路径（用户的主目录）
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks // 只显示文件夹，不解析符号链接
    );

    QMessageBox msgBox ;
    // 设置按钮

    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.button(QMessageBox::Ok)->setText("确定");
     msgBox.button(QMessageBox::Cancel)->setText("取消");
    //对样式表进行改动
    msgBox.setStyleSheet(
            "QMessageBox {"
            "background-color: white;"         // 设置背景颜色为深灰色
            "color: black;"                      // 设置文字颜色为白色
            "border: 2px solid #444444;"         // 设置边框颜色
            "font-family: Arial, sans-serif;"    // 设置字体
            "font-size: 28px;"                   // 设置字体大小
            "}"
            "QMessageBox QPushButton {"
            "background-color: #4CAF50;"         // 设置按钮的背景颜色
            "color: white;"                      // 设置按钮文字颜色为白色
            "border-radius: 5px;"                // 设置按钮的圆角
            "font-size: 24px;"                   // 设置按钮字体大小
            "padding: 5px 15px;"                 // 设置按钮内边距
            "}"
            "QMessageBox QPushButton:hover {"
            "background-color: #45a049;"         // 设置按钮悬停时的背景颜色
            "}"
        );

    //megBox的尺寸是自适应的没办法改变
     qDebug()<<"对话框的尺寸是："<<msgBox.size();
    // 如果用户选择了文件夹
    if (!folderPath.isEmpty()) {
        // 在这里处理所选文件夹的路径
         msgBox.setWindowTitle("选中的文件夹");
         msgBox.setText(folderPath);

    } else {
        // 如果用户取消了选择
        msgBox.setWindowTitle("没有选择");
        msgBox.setText("没有选择任何文件夹");
    }
    msgBox.exec();
}
void MainWindow:: onMenuAboutToShow()
   {
       // 当菜单显示时，切换箭头为上
       ui->selectedButton->setIcon(QIcon(":/new/prefix1/icons/up.svg"));
       qDebug()<<"当前图标的大小是："<<ui->selectedButton->iconSize();

   }

void MainWindow::onMenuAboutToHide()
   {
       // 当菜单隐藏时，切换箭头为向下
      ui->selectedButton->setIcon(QIcon(":/new/prefix1/icons/down.svg"));
      qDebug()<<"当前图标的大小是："<<ui->selectedButton->iconSize();

}
void MainWindow::MActionsSlot()
{
    QAction *action = (QAction*)sender();
    QString actionText = action->text();

    qDebug()<<actionText<<"triggerred!"<<endl;

    /*
    if("1_1" == actionText) {
        //...
    } else if("1_2" == actionText) {
        //...
    }
*/
        //...
}

//处理在系统菜单中关闭的事件
void MainWindow::closeMenuClicked(){
    close();
}
//触发系统菜单事件
void MainWindow::on_selectedButton_clicked(){
    // 获取按钮的位置信息
       QPoint buttonPos = ui->selectedButton->pos();  // 获取按钮相对主窗口的位置
       QSize buttonSize = ui->selectedButton->size(); // 获取按钮的尺寸

       // 计算菜单显示的起始位置
       QPoint menuPos = buttonPos + QPoint(0, buttonSize.height());  // 将菜单放在按钮的下方

       // 调用 exec() 方法来显示菜单，并将菜单显示在计算出的固定位置
       m_menu1->exec(ui->selectedButton->mapToGlobal(menuPos)); // 使用 mapToGlobal 来转换为全局坐标
}

void MainWindow::on_slider_valueChanged(int value) {
    if (ui->slider->isSliderDown()) {
        MoveVideo(value);
    }
}
//重写检测鼠标移动的事件响应函数
//void MainWindow::mouseMoveEvent(QMouseEvent *event) {
//    QMainWindow::mouseMoveEvent(event);
//    //QPoint mousePos = event->pos();

//        // 打印鼠标坐标
//    //qDebug() << "Mouse position: (" << mousePos.x() << "," << mousePos.y() << ")";
//       // 显示listButton并重置定时器
//       if (!ui->listButton->isVisible()) {
//           ui->listButton->show();
//       }
//        hideListButtonTimer->start(1000);

//}

//初始化播放区域的背景
void MainWindow::initPlayBcakground(){
    ui->backgroundlabel->setFixedHeight(height()-ui->topBar->height()-ui->funcBar->height()-ui->func->height());
    ui->backgroundlabel->setFixedWidth(width()-ui->listView->width());
    //导入背景照片
    background.load(":/new/prefix1/icons/bg.jpg");
    //设置背景的位置
    ui->backgroundlabel->lower();
    //修改backgroundlabel的尺寸
    //int bwidth =width()- ui->listView->width() * 8;
    //int bheight = ui->frame_3->height() - ui->func->height() - ui->funcBar->height();
    //ui->backgroundlabel->setGeometry(0, 0,ui->videoPlay->width(), ui->videoPlay->height());
    //qDebug()<<"播放区域的大小是"<< ui->backgroundlabel->size();
   // ui->backgroundlabel->setPixmap(background.scaled(ui->backgroundlabel->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));

}
//初始化播放区域大小
void MainWindow::initPlayLabel(){
    ui->playlabel->setGeometry(0,0,width()-ui->listView->width(),height()-ui->topBar->height()-ui->funcBar->height()-ui->func->height());
    ui->playlabel->setFixedHeight(height()-ui->topBar->height()-ui->funcBar->height()-ui->func->height());
    ui->playlabel->setFixedWidth(width()-ui->listView->width());
    //设置背景的位置
    ui->playlabel->lower();
}

void MainWindow::initOpenButton(){
    ui->func->setFixedHeight(50);
    ui->funcBar->setFixedHeight(34);
    ui->openBtn->move((width()-ui->listView->width() - ui->openBtn->width())/2, (height() -ui->func->height()-ui->funcBar->height() -ui->openBtn->height())/2);

}
//初始化listbutton的位置
void MainWindow::initListButton(){
    ui->listButton->move(width()- ui->listView->width() -ui->listButton->width(), (height() -ui->func->height()-ui->funcBar->height() -ui->openBtn->height())/2);
    ui->listButton->raise();
}
//初始化funct的位置
void MainWindow::initfunc(){
    //先设定中间的位置
    ui->playIcon->move((width()-ui->listView->width() - ui->playIcon->width())/2, ui->playIcon->y());
    ui->lastIcon->move((width()-ui->listView->width() - ui->playIcon->width())/2-5, ui->playIcon->y());
    ui->nextIcon->move((width()-ui->listView->width() - ui->playIcon->width())/2+5, ui->playIcon->y());
    ui->stopIcon->move((width()-ui->listView->width() - ui->playIcon->width())/2-65, ui->playIcon->y());
}

//重写界面大小调整
void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);

    //调整打开文件按钮的位置、此时还存在当打开和关闭list后不能做出相应的改变
    ui->openBtn->move((width()-ui->listView->width() - ui->openBtn->width())/2, (height() -ui->func->height()-ui->funcBar->height() -ui->openBtn->height())/2);
    // 调整背景大小
    ui->backgroundlabel->setFixedHeight(height()-ui->func->height()-ui->funcBar->height());
    ui->backgroundlabel->setFixedWidth(width()-ui->listView->width());
    //调整播放银幕的大小
    ui->playlabel->setFixedHeight(height()-ui->func->height()-ui->funcBar->height()-ui->topBar->height());
    ui->playlabel->setFixedWidth(width()-ui->listView->width());
    //qDebug()<<"调整之后的大小是："<<ui->backgroundlabel->size();
    ui->backgroundlabel->setPixmap(background.scaled(ui->backgroundlabel->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    // 调整listbutton按钮的位置
    ui->listButton->move(width()- ui->listView->width() -ui->listButton->width()-6, (height() -ui->func->height()-ui->funcBar->height() -ui->openBtn->height())/2);

}




//更新视频进度
void MainWindow::MoveVideo(int videoData) {
    qint64 duration = pPlayer->duration();
    qint64 position = (videoData * duration) / 100;
    pPlayer->setPosition(position);
}



// 更新进度条
void MainWindow::upDateSlider(qint64 position) {
    if (ui->slider->isSliderDown()) {
        return;  // 防止手动拖动时更新进度条
    }

    double num_p = position;
    double num_d = pPlayer->duration();

    ui->slider->setSliderPosition(100 * num_p / num_d);


    QTime currentTime(0, 0, 0, 0);
    currentTime = currentTime.addMSecs(position);
    currentFormatTime = currentTime.toString("mm:ss");
    ui->BeginTime->setText(currentFormatTime);

    //2025-2-26-subtitle
    QTime timeCrt = QTime(0,0,0);
    timeCrt = timeCrt.addMSecs(position);
    QTime timeTotal =QTime(0,0,0);
    timeTotal = timeTotal.addMSecs(pPlayer->duration());
    bool bShow = false;
    foreach(const Srt item,m_srtList)
    {
        bool ok=item.Start<timeCrt && item.End>timeCrt;
        if(ok)
        {
            writeSubtitle(item.Content);
            bShow = true;
            break;
        }
    }
    if(!bShow)
    {
        writeSubtitle("");
    }
}


// 获取视频时间信息
void MainWindow::GetDuration(qint64 duration) {
    // 设置进度条的最大值100
    ui->slider->setMaximum(100);


    // 计算总时间
    QTime totalTime = QTime(0, 0, 0, 0);
    totalTime = totalTime.addMSecs(duration);

    // 格式化时间为 mm:ss 格式
    totalFormatTime = totalTime.toString("mm:ss");

    // 显示结束时间
    ui->EndTime->setText(totalFormatTime);
}


void MainWindow::onPlayerStateChanged() {
    qDebug()<<"end slot call";
    // if (state == Player::playState::Ended) {
    //     // 视频播放完毕，确保进度条在最右侧
    ui->slider->setSliderPosition(ui->slider->maximum());

    //     qDebug() << "视频播放完成，进度条已到达最右侧";
    // }
    ui->playIcon->setIcon(playIcon);
    isPlaying=false;
}

// 打开视频或音频文件按钮
void MainWindow::on_openBtn_clicked()
{

    //改为可以选择多个文件
    QStringList filenames = QFileDialog::getOpenFileNames(
        this,
        "选择文件",
        "",
        "All Files (*.*);;MP3 Files (*.mp3);;MP4 Files (*.mp4);;MKV Files (*.mkv);;AVI Files (*.avi)"
    );

    if(filenames.isEmpty()){
        return;
    }

    // 添加文件到播放列表
    for (const QString& filename : filenames) {
//        VideoInfo info;
//        info.path = filename;
//        info.lastPlayTime = 0;  // 初始为 0，后续可从文件中加载
//        info.duration = 0;      // 初始未知，播放时更新
//        info.title = QFileInfo(filename).fileName();  // 使用文件名作为标题
//        historyList.append(info);

//        // 添加到 UI 的播放列表
//        QListWidgetItem* item = new QListWidgetItem(ui->ui_playlist);
//        item->setSizeHint(QSize(300, 40));

//        HistoryItem *historyItem = new HistoryItem(0,info.title, "0", ui->ui_playlist, item, filename);

//        connect(historyItem, &HistoryItem::itemClicked, this, &MainWindow::listChoosePlay);
//        connect(historyItem, &HistoryItem::aiItemclicked, this,&MainWindow::aiPlay);
// //        ui->historyListWidget->setItemWidget(item, historyItem); //FIXME 2
//        ui->ui_playlist->setItemWidget(item, historyItem);

        VideoData a;
        a.filename=filename;
        a.typeContent="本地视频";
        m_playlist<<a;

//        ui->ui_playlist->update();
//        this->repaint();

//        HistoryItem *historyItem = new HistoryItem(1,data.filename, data.typeContent, ui->personilityList, item,m_recommendVideos->m_filepath);
//        connect(historyItem, &HistoryItem::itemClicked, this, &MainWindow::ui_playlistChoosePlay);
//        connect(historyItem,&HistoryItem::downloadClicked,this,&MainWindow::m_download_historyitem);
//        connect(this,&MainWindow::m_downloadfinished_history,historyItem,&HistoryItem::downloadfinished);
//        //connect(historyItem, &HistoryItem::aiItemclicked, this,&MainWindow::aiPlay);
//        ui->ui_playlist->setItemWidget(item, historyItem);
    }
    on_playListBtn_clicked();
    //    // 默认选中第一个文件并加载
    //    if (!historyList.isEmpty()) {
    //        currentIndex = 0;
    //        pPlayer->setSource(QUrl::fromLocalFile(historyList[currentIndex].path));
    //        isopen = true;
    //        ui->historyListWidget->setCurrentRow(currentIndex);//给第一个文件加高亮
    //    }



}





QString MainWindow::formatTime(int seconds)
{
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int remainingSeconds = seconds % 60;

    return QString::asprintf("%02d:%02d:%02d", hours, minutes, remainingSeconds);
}

void MainWindow::on_voiceSlider_valueChanged(int value)
{
    // 更新标签显示播放的音量大小
       updateVoiceLabel(value);
       //实现拖动滑块来调节声音大小
       pPlayer->setVolume(value);
}


void MainWindow::paintEvent(QPaintEvent* e)
{
    if(isopen)
      pVideoWidget->resize(ui->videoPlay->size());
}
void MainWindow::updateVoiceLabel(int value)
{
    //QString totalTime = formatTime(totalDuration);  // 总音量（100%）

    // 格式化并显示百分比
    ui->voice->setText(QString("%1%").arg(value));
}

void MainWindow::on_playIcon_clicked()
{
//暂时写了对暂停和播放图标的切换，对于播放记录存在等因素的考虑，之后再来解决

        // 切换播放和暂停图标
        if (isPlaying) {
            ui->playIcon->setIcon(playIcon);  // 设置为暂停图标
        } else {
            ui->playIcon->setIcon(pauseIcon);   // 设置为播放图标
        }

        // 切换播放状态
        isPlaying = !isPlaying;
        //isSource = true;
        //ui->comboBox->setEnabled(true);
        // 你也可以在这里调用播放或暂停的相关逻辑
        if (isPlaying) {
                    if (!isopen  ||
                        currentIndex < 0 ) {
                        qDebug() << "没有可播放的资源或未选中视频";
                        isPlaying = false;
                        ui->playIcon->setIcon(playIcon);
                        return;
                    }
        //            pPlayer->setSource(QUrl::fromLocalFile(historyList[currentIndex].path));
                    pPlayer->play();
                    QString path = pPlayer->getUrl().toLocalFile();
                    //通过路径的第一个字符是否是"."判断是推荐视频还是本地视频
                    int type = 0;
                    if(path[0]=='.') type = 2;
                    else type = 1;
                    update_history_records(pPlayer->getUrl().toLocalFile(), type);//点击播放时添加到历史列表
                    on_historyButton_clicked();
                    videoFilePath=pPlayer->getUrl().toLocalFile();

                    // 更新界面
                    ui->backgroundlabel->setVisible(false);
                    ui->openBtn->setVisible(false);
                    ui->playlabel->lower();
                    ui->playlabel->setVisible(true);
                    QApplication::processEvents();
                    this->repaint();
                    QCoreApplication::processEvents();
                } else {
            qDebug() << "暂停播放";
            // 执行播放器的暂停逻辑
            pPlayer->pause();
            // player->pause();
        }
}


void MainWindow::on_lastIcon_clicked()
{
     qDebug() << "上一个视频";
}

void MainWindow::on_nextIcon_clicked()
{
     qDebug() << "下一个视频";
}

void MainWindow::on_stopIcon_clicked()
{
     qDebug()<<QSslSocket::sslLibraryBuildVersionString();
     qDebug() << "停止";
     //如果一开始并没有资源在播放，此时如果用户点击了暂停可以提示此时没有播放资源

     pPlayer->stop();
     //此时资源会被暂时移出，所以也不允许被选中
    // isSource = false;
     isPlaying = false;
     //ui->comboBox->setEnabled(false);
     if (!isPlaying) {
         ui->playIcon->setIcon(playIcon);  // 设置为暂停图标
         ui->backgroundlabel->setVisible(true);
         ui->openBtn->setVisible(true);
         ui->playlabel->setVisible(false);
         this->update();
         QApplication::processEvents();
         // this->repaint();

         // qApp->flush();
     }
}

void MainWindow::on_voiceIcon_clicked()
{
    // 切换播放和暂停图标
    if (voiceOn) {
        ui->voiceIcon->setIcon(voiceOffIcon);  // 设置为静音图标
        ui->voiceSlider->setValue(0);
    } else {
        ui->voiceIcon->setIcon(voiceOnIcon);   // 设置为正常图标
        ui->voiceSlider->setValue(20);
    }

    // 切换播放状态
    voiceOn = !voiceOn;

    if (voiceOn) {
        qDebug() << "解除静音";
    } else {
        qDebug() << "打开静音";

    }
}

//全屏
void MainWindow::on_allButton_clicked()
{
    if(!isFullScreen)
    {
       this->showFullScreen();
        updateVideoWidgetSize();
       ui->allButton->setIcon(offIcon);
       isFullScreen=true;
    }
    else
       {
         this->showNormal();  // 恢复正常窗口状态
        updateVideoWidgetSize();
         ui->allButton->setIcon(allIcon);
         isFullScreen=false;
       }
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    //这种修改倍速的方式会改变声音的音色和视频的质量，具体该如何很好解决需要涉及到视频帧的处理和对音频的处理
    //实现对视频的倍速播放
    qDebug() << arg1;
    //得到用户的速度选择
    double speed = arg1.toDouble();
    if(!isSource){
        qDebug() <<"当前还没有待播放的资源";
    }else{
         //设置视频的具体播放速度
        pPlayer->setPlaybackRate(speed);
    }

}
//用于实现对历史列表的出现与隐藏
void MainWindow::on_listButton_clicked()
{
    isListViewVisible = !isListViewVisible;

    if (isListViewVisible) {
        // 展开列表视图
        animation->setStartValue(0);
        animation->setEndValue(originalWidth);
        ui->listButton->setText(">");
        ui->listView->setFixedWidth(originalWidth);
        updateVideoWidgetSize();
     } else {
        // 折叠列表视图
        animation->setStartValue(originalWidth);
        animation->setEndValue(0);
        ui->listButton->setText("<");
        ui->listView->setFixedWidth(0);
        updateVideoWidgetSize();
      }

       animation->start();
       //qDebug() <<"点击后宽度是："<< ui->listView->width();
       //qDebug() <<"点击后高度是："<< ui->func->height();
       //qDebug() <<"点击后高度是："<< ui->funcBar->height();
       //调整相应的布局
       ui->openBtn->move((width()-ui->listView->width() - ui->openBtn->width())/2, (height() -ui->func->height()-ui->funcBar->height() -ui->openBtn->height())/2);
       ui->listButton->move(width()- ui->listView->width() -ui->listButton->width()-6, (height() -ui->func->height()-ui->funcBar->height() -ui->openBtn->height())/2);
      // initfunc();
       //调整背景
       ui->backgroundlabel->setFixedHeight(height()-ui->topBar->height()-ui->funcBar->height()-ui->func->height());
       ui->backgroundlabel->setFixedWidth(width()-ui->listView->width());
       ui->backgroundlabel->setPixmap(background.scaled(ui->backgroundlabel->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
       //调整播放荧幕
       ui->playlabel->setFixedHeight(height()-ui->topBar->height()-ui->funcBar->height()-ui->func->height());
       ui->playlabel->setFixedWidth(width()-ui->listView->width());

       //计时显示listbutton
       ui->listButton->show();
       hideListButtonTimer->start(1500);

}

void MainWindow::setupAnimation() {
        animation = new QPropertyAnimation(ui->listView, "maximumWidth");
        animation->setDuration(100);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
}


void MainWindow::on_setting_clicked()
{

    // 获取按钮的位置
    QPoint buttonPos = ui->setting->mapToGlobal(QPoint(0, 0));

    // 计算子界面应该显示的位置
    // 这里我们将子界面显示在按钮的右上角
    int offsetX = ui->setting->width();  // 按钮的宽度
    int offsetY = -settingsDialog->height();  // 使用子界面的高度，确保子界面显示在按钮的上面

    // 将子界面移动到按钮的右上角
    settingsDialog->move(buttonPos.x() - 4*offsetX, buttonPos.y() + offsetY);

    // 显示子界面
    settingsDialog->exec();
}

//滑动进度条
void MainWindow::on_slider_sliderMoved(int position)
{

    // 将进度条值转化为相对于视频总时长的播放位置
    pPlayer->setPosition(position);

}

//窗口最小化
void MainWindow::on_min_clicked()
{
     this->showMinimized();
}

//窗口最大化
void MainWindow::on_max_clicked()
{
    if(!isMax)
    {
        this->showFullScreen();
        updateVideoWidgetSize();
        isMax=!isMax;
        ui->max->setIcon(normalIcon);

    }
    else
    {
        this->showNormal();
        updateVideoWidgetSize();
        isMax=!isMax;
        ui->max->setIcon(maxIcon);
    }


}

//关闭窗口
void MainWindow::on_close_clicked()
{
    //清除播放
    stopPlayback();
    //只是简单对界面清除
    this->close();

}
void MainWindow::stopPlayback()
{
    // 假设你有一个播放器对象 player
    if (pPlayer) {
        pPlayer->stop(); // 停止播放线程或解码逻辑
        delete pPlayer;  // 释放播放器资源
        pPlayer = nullptr;
    }
}

void MainWindow::on_dayAndNight_clicked()    //主题切换
{


    if(!isDay)
    {
       QString lightTheme = "QWidget { background-color: #ffffff; color: #000000; }"
                               "QPushButton { background-color: #2196F3; color: white; border-radius: 5px; }"
                               "QPushButton:hover { background-color: #1976D2; }"
                               "QComboBox { background-color: #ffffff; color: #000000; }"
                               "QLabel { color: #000000; }";

         this->setStyleSheet(lightTheme);  // 应用浅色主题
         ui->centralwidget->setStyleSheet("QWidget { background-color: #ffffff; color: #000000; }");
         ui->func->setStyleSheet("QFrame { background-color: #ffffff; color: #000000; }");
         ui->topBar->setStyleSheet("QWidget { background-color: #ffffff; color: #000000; }");
         ui->videoPlay->setStyleSheet("QFrame { background-color: #ffffff; color: #000000; }");
         ui->BeginTime->setStyleSheet( "QLabel {  background-color: #ffffff; color: #000000; }");

         ui->EndTime->setStyleSheet( "QLabel {  background-color: #ffffff; color: #000000; }");
         //ui->title->setStyleSheet( "QLabel {  background-color: #ffffff; color: #000000; }");
        // ui->listView->setStyleSheet( "QListView {  background-color: #cccccc; color: #000000; }");
         ui->funcBar->setStyleSheet("QFrame { background-color: #ffffff; color: #000000; }");
         ui->slider->setStyleSheet("QSlider{ background-color: #ffffff; color: #000000;}");
         ui->voiceSlider->setStyleSheet("QSlider{ background-color: #ffffff; color: #000000; }");
         ui->voice->setStyleSheet( "QLabel {  background-color: #ffffff; color: #000000; }");
         ui->dayAndNight->setIcon(dayIcon);
         isDay=!isDay;
         QSettings settings;
         settings.setValue("theme", "dark");  // 保存用户选择的主题
    }
    else if(isDay)
    {
        QString darkTheme = "QWidget { background-color: rgb(30, 30, 30); color: rgb(255, 255, 255); }"
                               "QPushButton { background-color: #4CAF50; color: white; border-radius: 5px; }"
                               "QPushButton:hover { background-color: #45a049; }"
                               "QComboBox { background-color: rgb(30, 30, 30); color: rgb(255, 255, 255); }"
                               ;

           //this->setStyleSheet(darkTheme);  // 应用深色主题
           ui->centralwidget->setStyleSheet("QWidget { background-color: #1e1e1e;; color: rgb(255, 255, 255); }");
           ui->func->setStyleSheet("QFrame { background-color: #1e1e1e;; color: rgb(255, 255, 255); }");         ui->topBar->setStyleSheet("QFrame { background-color: #ffffff; color: #000000; }");
           ui->topBar->setStyleSheet("QWidget { background-color: #1e1e1e;; color: rgb(255, 255, 255); }");
           ui->videoPlay->setStyleSheet("QFrame { background-color: #000000;; color:rgb(255, 255, 255); }");
           ui->BeginTime->setStyleSheet( "QLabel {  background-color:#1e1e1e;; color: #b3b3b3; }");
           ui->EndTime->setStyleSheet( "QLabel {  background-color:#1e1e1e;; color:#b3b3b3; }");
           //ui->title->setStyleSheet( "QLabel {  background-color: #1e1e1e;; color: #b3b3b3; }");
          // ui->listView->setStyleSheet( "QListView {  background-color: #1e1e1e; color: #000000; }");
           ui->funcBar->setStyleSheet("QFrame { background-color: #000000;; color:rgb(255, 255, 255); }");
           ui->slider->setStyleSheet("QSlider{ background-color: #000000;; color:rgb(255, 255, 255);}");
           ui->voiceSlider->setStyleSheet("QSlider{ background-color: #000000;; color:rgb(255, 255, 255);  }");
           ui->voice->setStyleSheet("QSlider{ background-color: #000000;; color:rgb(255, 255, 255);  }");

        ui->dayAndNight->setIcon(nightIcon);
        isDay=!isDay;

        QSettings settings;
        settings.setValue("theme", "light");  // 保存用户选择的主题
    }
  updateVideoWidgetSize();
}


void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_dragStartPos = event->globalPos();  // 记录鼠标按下的全局位置
        m_geometryBeforeDrag = geometry();    // 记录窗口当前的几何信息
        m_cursorPos = calculateCursorPosition(event->pos()); // 计算鼠标所在区域
    }

    QMainWindow::mousePressEvent(event);
}


void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    // 调用基类的 mouseMoveEvent 保持默认行为
    QMainWindow::mouseMoveEvent(event);

    // 1. 打印鼠标坐标（调试时使用）
    //qDebug() << "Mouse position: (" << event->pos().x() << "," << event->pos().y() << ")";
    // 2. 显示 listButton 并启动定时器
    //只有当鼠标是在播放荧幕的区域的时候开始计时
    if (!ui->listButton->isVisible()) {
        ui->listButton->show();
    }
    hideListButtonTimer->start(1000);  // 启动定时器来隐藏按钮

    // 3. 更新光标形状
    updateCursorShape(event->pos());  // 更新光标形状

    // 4. 如果鼠标左键按下，处理拖动窗口或调整窗口大小event->buttons() & Qt::LeftButton
    if (event->buttons() & Qt::LeftButton) {
        if (m_cursorPos == TitleBar)
        {   // 拖动窗口
            QPoint delta = event->globalPos() - m_dragStartPos;
            move(pos() + delta);
            m_dragStartPos = event->globalPos();
        }else{
            // 调整窗口大小
            adjustWindowSize(event->globalPos());
        }

    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    //m_cursorPos = None;  // 清除状态
    setCursor(Qt::ArrowCursor);
    QMainWindow::mouseReleaseEvent(event);
}



// 计算鼠标所在区域
MainWindow::CursorPosition MainWindow::calculateCursorPosition(const QPoint &pos) {
    const int borderWidth = 2;  // 边缘检测宽度（像素）
    // 检查标题栏区域
       if (pos.y() <= 51 && pos.y() > 2){
           //qDebug() << "In TitleBar area: " << pos.y();  // 打印坐标
           return TitleBar;
       }
    // 检测窗口边缘
    bool left = (pos.x() <= borderWidth);
    bool right = (pos.x() >= width() - borderWidth);
    bool top = (pos.y() <= borderWidth);
    bool bottom = (pos.y() >= height() - borderWidth);

    if (left && top)       return TopLeft;
    else if (right && top) return TopRight;
    else if (left && bottom) return BottomLeft;
    else if (right && bottom) return BottomRight;
    else if (left)  return Left;
    else if (right) return Right;
    else if (top)   return Top;
    else if (bottom) return Bottom;

    return None;
}

//用于调整界面的大小尺寸
void MainWindow::adjustWindowSize(const QPoint &globalMousePos) {
    QRect newGeometry = m_geometryBeforeDrag;
    QPoint delta = globalMousePos - m_dragStartPos;

    switch (m_cursorPos) {
    case Left:
        newGeometry.setLeft(newGeometry.left() + delta.x());
        break;
    case Right:
        newGeometry.setRight(newGeometry.right() + delta.x());
        break;
    case Top:
        newGeometry.setTop(newGeometry.top() + delta.y());
        break;
    case Bottom:
        newGeometry.setBottom(newGeometry.bottom() + delta.y());
        break;
    case TopLeft:
        newGeometry.setTopLeft(newGeometry.topLeft() + delta);
        break;
    case TopRight:
        newGeometry.setTopRight(newGeometry.topRight() + delta);
        break;
    case BottomLeft:
        newGeometry.setBottomLeft(newGeometry.bottomLeft() + delta);
        break;
    case BottomRight:
        newGeometry.setBottomRight(newGeometry.bottomRight() + delta);
        break;
    default:
        break;
    }

    // 确保窗口最小尺寸
    if (newGeometry.width() < minimumWidth()) {
        newGeometry.setWidth(minimumWidth());
    }
    if (newGeometry.height() < minimumHeight()) {
        newGeometry.setHeight(minimumHeight());
    }

    setGeometry(newGeometry);
}


//用于修改鼠标的形状

void MainWindow::updateCursorShape(const QPoint &pos) {
    CursorPosition cursorPos = calculateCursorPosition(pos);

    switch (cursorPos) {
    case TitleBar:
        setCursor(Qt::ArrowCursor);
        break;
    case Top:
    case Bottom:
        setCursor(Qt::SizeVerCursor);
        break;
    case Left:
    case Right:
        setCursor(Qt::SizeHorCursor);
        break;
    case TopLeft:
    case BottomRight:
        setCursor(Qt::SizeFDiagCursor);
        break;
    case TopRight:
    case BottomLeft:
        setCursor(Qt::SizeBDiagCursor);
        break;
    default:
        setCursor(Qt::ArrowCursor);
        break;
    }
}

//重写快捷键
void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        // 按下Esc键时关闭窗口
        close();
    } else if (event->key() == Qt::Key_Left) {
        qDebug()<<"666";
        qint64 position = pPlayer->position();
        qint64 newPosition = position - step*1000;  // 快退
        if (newPosition < 0) {
            newPosition = 0;  // 限制最小值
        }
        pPlayer->setPosition(newPosition);  // 设置新的播放位置
    } else if (event->key() == Qt::Key_Right) {
        qDebug()<<"777";
        qint64 position = pPlayer->position();
        qint64 totalDuration = pPlayer->duration();
        // 按右键时快进
       qint64 newPosition = position + step*1000; ;  // 快进
       if (newPosition > totalDuration) {
           newPosition = totalDuration;  // 限制最大值
       }
       pPlayer->setPosition(newPosition);  // 设置新的播放位置
    } else if (event->key() == Qt::Key_Up) {
        qDebug()<<"888";
        // 按下上键时调节音量增加
       int currentVolume = pPlayer->volume();  // 获取当前音量，返回值范围是 0 到 100
       int setVol=currentVolume+10;
       // 设置音量
       pPlayer->setVolume(setVol);
       ui->voice->setText(QString("%1%").arg(setVol));
       ui->voiceSlider->setValue(setVol);


    } else if (event->key() == Qt::Key_Down) {
        qDebug()<<"999";

        // 按下上键时调节音量增加
       int currentVolume = pPlayer->volume();  // 获取当前音量，返回值范围是 0 到 100
       int setVol=currentVolume-10;

       // 设置音量
       pPlayer->setVolume(setVol);
       ui->voice->setText(QString("%1%").arg(setVol));
       ui->voiceSlider->setValue(setVol);

    }else if(event->key()==Qt::Key_Space){
        ui->playIcon->click();
    }
}


void MainWindow::receiveSignal(QString str,int index){

    if(str=="selectedOption")
    {
        if(index==1)
        {
           step=5;
        }else if(index==2){
           step=10;
        }else if(index==2){
           step=20;
        }
    }else if(str=="viewOption"){

        if(index==1)
        {

        }else if(index==2){

        }else if(index==2){

        }
    }
}



void MainWindow::speedChanged(double speed)
{
     pPlayer->setPlaybackRate(speed);
}



void MainWindow::sizeChanged(int widthRatio,int heightRatio)
{
    isAdjusting=true;
    if(widthRatio==4)
    {
        videoAspectRatio = 4;

    }else{
        videoAspectRatio = 16;
    }
    updateVideoWidgetSize();

}

void MainWindow::updateVideoWidgetSize() {
    int videoHeight, videoWidth;

    // 根据 listView 是否可见来决定视频区域大小
    if (isListViewVisible) {
        if (videoAspectRatio == 4) {
            // 设置 4:3 比例
            videoHeight = (width() - ui->listView->width()) * (3.0 / 4.0);
            videoWidth = width() - ui->listView->width();
            // 设置视频控件的宽度和高度
            pVideoWidget->setFixedWidth(videoWidth);
            pVideoWidget->setFixedHeight(videoHeight);

            // 居中显示 pVideoWidget（水平和垂直居中）
            int xPos = (width() - ui->listView->width() - videoWidth) / 2;
            int yPos = (height() - videoHeight) / 4;

            // 使用 move 来居中 pVideoWidget
            pVideoWidget->move(xPos, yPos);
        } else {
            // 设置 16:9 比例
            videoHeight = (width() - ui->listView->width()) * (9.0 / 16.0);
            videoWidth = width() - ui->listView->width();
            // 设置视频控件的宽度和高度
            pVideoWidget->setFixedWidth(videoWidth);
            pVideoWidget->setFixedHeight(videoHeight);

            // 居中显示 pVideoWidget（水平和垂直居中）
            int xPos = (width() - ui->listView->width() - videoWidth) / 2;
            int yPos = (height() - videoHeight) / 3;

            // 使用 move 来居中 pVideoWidget
            pVideoWidget->move(xPos, yPos);
        }


    } else {
        // 如果 listView 不可见，根据剩余空间调整视频区域大小
        if (videoAspectRatio == 4) {
            // 设置 4:3 比例
            videoHeight = height() - ui->func->height() - ui->funcBar->height() - ui->topBar->height();
            videoWidth = videoHeight * (4.0 / 3.0);
        } else {
            // 设置 16:9 比例
            videoHeight = height() - ui->func->height() - ui->funcBar->height() - ui->topBar->height();
            videoWidth = width();
        }
        // 设置视频控件的宽度和高度
        pVideoWidget->setFixedWidth(videoWidth);
        pVideoWidget->setFixedHeight(videoHeight);

        // 居中显示 pVideoWidget（水平和垂直居中）
        int xPos = (width() - videoWidth) / 2;
        // 使用 move 来居中 pVideoWidget
        pVideoWidget->move(xPos, 0);
    }

    // 忽略原始比例，强制拉伸或压缩以填充控件
    //pVideoWidget->setAspectRatioMode(Qt::IgnoreAspectRatio);
}





void MainWindow::rotateView(int choice)
{
    switch(choice){
    case 1:{
        qDebug()<<"顺时针";
        break;
    }
    case 2:{
        qDebug()<<"逆时针";
        break;

    }
    case 3:{
        break;

    }
    case 4:{
        break;

    }
    }

}



void MainWindow::on_ai_clicked()
{


    qDebug()<<"666";
    Dialog *dialog = new Dialog();

   // 计算弹窗的位置，使其在主窗口的正中心
   int x = this->x() + (this->width() - dialog->width()) / 2;
   int y = this->y() + (this->height() - dialog->height()) / 2;
   dialog->move(x, y);

   dialog->exec();

}

void MainWindow::on_deleteListButton_clicked(){
    qDebug() << "删除所有的播放记录";
}

//历史记录部分的槽函数
void MainWindow::on_historyButton_clicked(){
    //跳转到对应的播放区域
    ui->stackedWidget->setCurrentWidget(ui->videoHistory);
    ui->historyListWidget->clear();
    init_historylist();
    //historyListWidget
}

void MainWindow::on_personalityButton_clicked(){
    ui->stackedWidget->setCurrentWidget(ui->personility);
    ui->lineEdit->clear();
}

void MainWindow::on_aiButton_clicked(){
    ui->stackedWidget->setCurrentWidget(ui->AI);
}
void MainWindow::on_playListBtn_clicked(){
     ui->stackedWidget->setCurrentWidget(ui->playList);
     ui->ui_playlist->clear();
     init_playlist(m_playlist);
}

void MainWindow::init_playlist(QList<VideoData> &temp){ //NOTE 初始化播放列表
    for(int i=0;i<temp.size();i++){
        qDebug()<<temp[i].filename;
    }

    for ( auto data : temp) {
        QListWidgetItem* item = new QListWidgetItem(ui->ui_playlist);
       // item->setSizeHint(QSize(300, 40));

        HistoryItem *historyItem;
        if(data.typeContent=="本地视频"){
           historyItem = new HistoryItem(0,data.filename, data.typeContent, ui->ui_playlist, item,data.filename);
           connect(historyItem, &HistoryItem::itemClicked, this, &MainWindow::ui_playlistChoosePlay2);
        }
        else{
            historyItem = new HistoryItem(1,data.filename, data.typeContent, ui->ui_playlist, item,m_recommendVideos->m_filepath,data.isLiked,data.isUnliked);
            connect(historyItem, &HistoryItem::itemClicked, this, &MainWindow::ui_playlistChoosePlay);
            connect(historyItem,&HistoryItem::downloadClicked,this,&MainWindow::m_download_historyitem);
            connect(this,&MainWindow::m_downloadfinished_history,historyItem,&HistoryItem::downloadfinished);
            connect(historyItem, &HistoryItem::likeItemClicked, this, [&](QString filename,bool islike,bool isunlike){
                data.isLiked=islike;
                data.isUnliked=isunlike;
            });

        }
//        connect(historyItem, &HistoryItem::aiItemclicked, this,&MainWindow::aiPlay);
        ui->ui_playlist->setItemWidget(item, historyItem);
    }
    ui->ui_playlist->update();
}

void MainWindow::init_historylist() {
    for (int i = historyRecords.size() - 1; i >= 0; --i) {
        const auto &data = historyRecords[i];

        QListWidgetItem* item = new QListWidgetItem(ui->historyListWidget);
        QString lastTime = data.lastTime.toString("yyyy/M/d H:mm");
        HistoryItem *historyItem = new HistoryItem(2, data.title, lastTime, ui->historyListWidget, item, data.url);

        connect(historyItem, &HistoryItem::itemClicked, this, &MainWindow::history_playlistChoose);
        ui->historyListWidget->setItemWidget(item, historyItem);
    }
    ui->ui_playlist->update();
}
//void MainWindow::init_historylist() {
//    for (int i = historyRecords.size() - 1; i >= 0; --i) {
//        const auto &data = historyRecords[i];

//        QListWidgetItem* item = new QListWidgetItem(ui->historyListWidget);
//        QString lastTime = data.lastTime.toString("yyyy/M/d H:mm");
//        HistoryItem *historyItem = new HistoryItem(2, data.title, lastTime, ui->historyListWidget, item, data.url);

//        connect(historyItem, &HistoryItem::itemClicked, this, &MainWindow::history_playlistChoose);
//        ui->historyListWidget->setItemWidget(item, historyItem);
//    }
//    ui->ui_playlist->update();
//}

/*
void MainWindow::initHistoryList(){

    struct HistoryData {
            QString fileName;
            QString duration;
        };

        QList<HistoryData> history = {
            {"跑步.mp4", "00:00:13"},
            {"真无语，为啥是表现的文字的关系，为啥因为文字的缘故就不能实现自动换行了", "00:00:23"},
            {"真无语，为啥是表现的文字的关系，为啥因为文字的缘故就不能实现自动换行了", "00:00:23"},
            {"跑步.mp4", "00:00:13"},
            {"真无语，为啥是表现的文字的关系，为啥因为文字的缘故就不能实现自动换行了", "00:00:23"},
            {"跑步.mp4", "00:00:13"},
            {"真无语，为啥是表现的文字的关系，为啥因为文字的缘故就不能实现自动换行了", "00:00:23"},
            {"真无语，为啥是表现的文字的关系，为啥因为文字的缘故就不能实现自动换行了", "00:00:23"},
            {"视频QQ202中文5125-161338.mp4", "00:00:45"},
            {"飞鸟.mp4", "00:00:42"},
            {"视频QQ202中文5125-161338.mp4", "00:00:45"},
            {"跑步.mp4", "00:00:13"},
            {"练习.mp4", "00:00:10"}
        };

        for (const auto &data : history) {
            QListWidgetItem* item = new QListWidgetItem(ui->historyListWidget);
           // item->setSizeHint(QSize(300, 40));

            HistoryItem *historyItem = new HistoryItem(data.fileName, data.duration, ui->historyListWidget, item);
            connect(historyItem, &HistoryItem::itemClicked, this, &MainWindow::listChoosePlay);
            connect(historyItem, &HistoryItem::aiItemclicked, this,&MainWindow::aiPlay);
            ui->historyListWidget->setItemWidget(item, historyItem);
        }


}
*/

//处理选中历史中对应的选项后想要点击之后播放相应的视频
void MainWindow::listChoosePlay(QString &fileName) //NOTE 点击事件处槽函数
{
    // 获取当前选中的行索引oppk
    m_index_List = ui->historyListWidget->currentRow();

    qDebug() << "从播放历史中选中的文件是：" << fileName;
    qDebug() << "选中的文件是第：" << m_index_List << "个";

    QString filenames = fileName;


    qDebug()<<"sameNameSubtitle"<<systemDialog->settings.value("sameNameSubtitle").toBool();
    qDebug()<<"otherNameSubtitle"<<systemDialog->settings.value("otherNameSubtitle").toBool();
    bool found=false;

    if(systemDialog->settings.value("sameNameSubtitle").toBool()){
        int nIndex = filenames.lastIndexOf('.');//寻找‘.’符号在字符串中的id
        nIndex++;
        QString srtfile =filenames.mid(0,nIndex); //截取‘.’符号后面的字符串，这是为了获取文件后缀名
        srtfile +="srt";
        found=called_orNot_addSrt(srtfile);
    }
    if(!found&&systemDialog->settings.value("otherNameSubtitle").toBool()){
        QFileInfo videoFileInfo(filenames);
        QString videoPath = videoFileInfo.path(); // 获取视频文件所在目录
        QDir dir(videoPath);
        QStringList srtFiles = dir.entryList(QStringList() << "*.srt", QDir::Files); // 获取目录下所有 .srt 文件

        if(srtFiles.size()>0){
            qDebug()<<"同文件夹下字幕文件:"<<srtFiles.last();
            QString srtFile =  dir.absoluteFilePath(srtFiles.last());
            called_orNot_addSrt(srtFile);
        }
    }

    // 确保索引有效
    if (m_index_List >= 0 && m_index_List < historyList.size()) {
        currentIndex = m_index_List;  // 更新 currentIndex
        if(!pPlayer->getUrl().isEmpty()){//防止在没有文件加载进来的时候调用stop使程序崩溃
            pPlayer->stop();
        }
        pPlayer->setSource(QUrl::fromLocalFile(historyList[currentIndex].path));
        qDebug() << "播放时长是：" << pPlayer->duration();

        isopen = true;
        // 如果正在播放状态，立即播放新选中的文件
        if (isPlaying) {
            pPlayer->play();
            update_history_records(pPlayer->getUrl().toLocalFile());//TODO 历史列表点击
        }
    } else {
        qDebug() << "无效的索引：" << m_index_List;
    }

}


void MainWindow::personalityChoosePlay(QString &fileName) //NOTE 点击事件处槽函数
{
    // 获取当前选中的行索引oppk
    m_index_List = ui->personilityList->currentRow();

    qDebug() << "从推荐中选中的文件是：" << fileName;
    qDebug() << "选中的文件是第：" << m_index_List << "个";

    QString filenames = fileName;
    //systemDialog->settings.setValue("sameNameSubtitle",true);
    qDebug()<<systemDialog->settings.value("sameNameSubtitle").toBool();
    if(systemDialog->settings.value("sameNameSubtitle").toBool()){
        int nIndex = filenames.lastIndexOf('.');//寻找‘.’符号在字符串中的id
        nIndex++;
        QString srtfile =filenames.mid(0,nIndex); //截取‘.’符号后面的字符串，这是为了获取文件后缀名
        srtfile +="srt";
        called_orNot_addSrt(srtfile);
    }
    else if(systemDialog->settings.value("otherNameSubtitle").toBool()){
        QFileInfo videoFileInfo(filenames);
        QString videoPath = videoFileInfo.path(); // 获取视频文件所在目录
        QDir dir(videoPath);
        QStringList srtFiles = dir.entryList(QStringList() << "*.srt", QDir::Files); // 获取目录下所有 .srt 文件

        if(srtFiles.size()>0){
            QString srtFile =  dir.absoluteFilePath(srtFiles.last());
            called_orNot_addSrt(srtFile);
        }
    }

    QList<VideoData> temp=m_recommendVideos->m_rcmdVideos;
    // 确保索引有效
    if (m_index_List >= 0 && m_index_List < temp.size()) {
        currentIndex = m_index_List;  // 更新 currentIndex
        if(!pPlayer->getUrl().isEmpty()){//防止在没有文件加载进来的时候调用stop使程序崩溃
            pPlayer->stop();
        }

        VideoData d=temp[currentIndex];
        qDebug()<<m_recommendVideos->m_filepath+'/'+d.filename+".mp4";

        QString video_path=m_recommendVideos->m_filepath+d.filename+".mp4";
        QString avatar_path=m_recommendVideos->m_filepath+d.filename+".jpg";

        ui->titles->setText(d.filename);
        videoFilePath=video_path;
        ui->type->setText(d.typeContent+'/'+d.typeForm);
        qDebug()<<"封面图片路径"<<avatar_path;
        ui->avatar->setIcon(QPixmap(avatar_path));
        tags = d.keywords.join(",");  // 逗号连接成一个字符串
        qDebug()<<"标签关键词"<<tags;
        updateTags();

        if (QFile::exists(video_path)) {
            qDebug() << "Web File exists:" << video_path;
            pPlayer->setSource(QUrl::fromLocalFile(video_path));
            qDebug() << "播放时长是：" << pPlayer->duration();
            
          
            isopen = true;
            // 如果正在播放状态，立即播放新选中的文件
            if (isPlaying) {
                pPlayer->play();
                update_history_records(pPlayer->getUrl().toLocalFile(), 2);
            }    
        } else{
            isopen=false;
        }

    } else {
        qDebug() << "无效的索引：" << m_index_List;
    }
}


void MainWindow::ui_playlistChoosePlay(QString &fileName) //NOTE 点击事件处槽函数
{
    // 获取当前选中的行索引oppk
    m_index_List = ui->ui_playlist->currentRow();

    qDebug() << "从播放清单中选中的文件是：" << fileName;
    qDebug() << "选中的文件是第：" << m_index_List << "个";

    // 确保索引有效
    if (m_index_List >= 0 && m_index_List < m_playlist.size()) {
        currentIndex = m_index_List;  // 更新 currentIndex
        if(!pPlayer->getUrl().isEmpty()){//防止在没有文件加载进来的时候调用stop使程序崩溃
            pPlayer->stop();
        }

        VideoData d=m_playlist[currentIndex];
        qDebug()<<m_recommendVideos->m_filepath+'/'+d.filename+".mp4";

        QString video_path=m_recommendVideos->m_filepath+d.filename+".mp4";
        QString avatar_path=m_recommendVideos->m_filepath+d.filename+".jpg";

        if (QFile::exists(video_path)) {
            qDebug() << "Web File exists:" << video_path;
            pPlayer->setSource(QUrl::fromLocalFile(video_path));
            qDebug() << "播放时长是：" << pPlayer->duration();

            ui->titles->setText(d.filename);
            videoFilePath=video_path;
            ui->type->setText(d.typeContent);
            qDebug()<<"封面图片路径"<<avatar_path;
            ui->avatar->setIcon(QPixmap(avatar_path));
            tags = d.keywords.join(",");  // 逗号连接成一个字符串
            qDebug()<<"标签关键词"<<tags;
            updateTags();

            isopen = true;
            // 如果正在播放状态，立即播放新选中的文件
            if (isPlaying) {
                pPlayer->play();
                update_history_records(pPlayer->getUrl().toLocalFile(), 2);
            }
        } else{
            isopen=false;
        }

    } else {
        qDebug() << "无效的索引：" << m_index_List;
    }
}

void MainWindow::history_playlistChoose(QString &fileName){
    // 获取当前选中的行索引oppk
    m_index_List = ui->historyListWidget->currentRow();

    qDebug() << "从播放清单中选中的文件是：" << fileName;
    qDebug() << "选中的文件是第：" << m_index_List << "个";

    QString filenames = fileName;
    systemDialog->settings.setValue("sameNameSubtitle",false);
    systemDialog->settings.setValue("otherNameSubtitle",false);

    qDebug()<<systemDialog->settings.value("sameNameSubtitle").toBool();
    if(systemDialog->settings.value("sameNameSubtitle").toBool()){
        int nIndex = filenames.lastIndexOf('.');//寻找‘.’符号在字符串中的id
        nIndex++;
        QString srtfile =filenames.mid(0,nIndex); //截取‘.’符号后面的字符串，这是为了获取文件后缀名
        srtfile +="srt";
        called_orNot_addSrt(srtfile);
    }
    else if(systemDialog->settings.value("otherNameSubtitle").toBool()){
        QFileInfo videoFileInfo(filenames);
        QString videoPath = videoFileInfo.path(); // 获取视频文件所在目录
        QDir dir(videoPath);
        QStringList srtFiles = dir.entryList(QStringList() << "*.srt", QDir::Files); // 获取目录下所有 .srt 文件

        if(srtFiles.size()>0){
            QString srtFile =  dir.absoluteFilePath(srtFiles.last());
            called_orNot_addSrt(srtFile);
        }
    }

    // 确保索引有效
    if (m_index_List >= 0 && m_index_List < historyRecords.size()) {
        currentIndex = m_index_List;  // 更新 currentIndex
        if(!pPlayer->getUrl().isEmpty()){//防止在没有文件加载进来的时候调用stop使程序崩溃
            pPlayer->stop();
        }
        pPlayer->setSource(QUrl::fromLocalFile(historyRecords[historyRecords.size()-1-currentIndex].url));
        qDebug() << "播放时长是：" << pPlayer->duration();

        isopen = true;
        // 如果正在播放状态，立即播放新选中的文件
        if (isPlaying) {
            pPlayer->play();
            update_history_records(pPlayer->getUrl().toLocalFile(), 0);
            on_historyButton_clicked();
        }
    } else {
        qDebug() << "无效的索引：" << m_index_List;
    }
}

void MainWindow::ui_playlistChoosePlay2(QString &fileName){
    // 获取当前选中的行索引oppk
    m_index_List = ui->ui_playlist->currentRow();

    qDebug() << "从播放清单中选中的文件是：" << fileName;
    qDebug() << "选中的文件是第：" << m_index_List << "个";

    QString filenames = fileName;
    systemDialog->settings.setValue("sameNameSubtitle",false);
    systemDialog->settings.setValue("otherNameSubtitle",false);

    qDebug()<<systemDialog->settings.value("sameNameSubtitle").toBool();
    if(systemDialog->settings.value("sameNameSubtitle").toBool()){
        int nIndex = filenames.lastIndexOf('.');//寻找‘.’符号在字符串中的id
        nIndex++;
        QString srtfile =filenames.mid(0,nIndex); //截取‘.’符号后面的字符串，这是为了获取文件后缀名
        srtfile +="srt";
        called_orNot_addSrt(srtfile);
    }
    else if(systemDialog->settings.value("otherNameSubtitle").toBool()){
        QFileInfo videoFileInfo(filenames);
        QString videoPath = videoFileInfo.path(); // 获取视频文件所在目录
        QDir dir(videoPath);
        QStringList srtFiles = dir.entryList(QStringList() << "*.srt", QDir::Files); // 获取目录下所有 .srt 文件

        if(srtFiles.size()>0){
            QString srtFile =  dir.absoluteFilePath(srtFiles.last());
            called_orNot_addSrt(srtFile);
        }
    }

    // 确保索引有效
    if (m_index_List >= 0 && m_index_List < m_playlist.size()) {
        currentIndex = m_index_List;  // 更新 currentIndex
        if(!pPlayer->getUrl().isEmpty()){//防止在没有文件加载进来的时候调用stop使程序崩溃
            pPlayer->stop();
        }
        VideoData d=m_playlist[currentIndex];
        pPlayer->setSource(QUrl::fromLocalFile(d.filename));
        qDebug() << "播放时长是：" << pPlayer->duration();

        videoFilePath=d.filename;
        QFileInfo qfi(d.filename);
        ui->titles->setText(qfi.baseName());
        ui->type->setText("本地视频");
        ui->avatar->setIcon(QPixmap(":/new/prefix1/icons/default.png"));
        tags="本地视频,还没分析哦,单击上方AI图标开始分析";
        updateTags();

        isopen = true;
        // 如果正在播放状态，立即播放新选中的文件
        if (isPlaying) {
            pPlayer->play();
            update_history_records(pPlayer->getUrl().toLocalFile(), 1);
        }
    } else {
        qDebug() << "无效的索引：" << m_index_List;
    }
}

void MainWindow::aiPlay(QString &filePath){
    //跳转到ai界面
    ui->stackedWidget->setCurrentWidget(ui->AI);
    videoFilePath=filePath;
    ui->titles->setText(videoFilePath);
    ui->avatar->setIcon(QPixmap(":/new/prefix1/icons/default.png"));
    qDebug()<<videoFilePath;
}

//2025-3-2-subtitle
void MainWindow::writeSubtitle(QString str){
    m_subtitle->setText(str);
    m_subtitle->setWordWrap(true);
    //subtitle->adjustSize();
    double x=ui->videoPlay->mapToGlobal(QPoint(0, 0)).x();
    double y=ui->videoPlay->mapToGlobal(QPoint(0, 0)).y();
    m_subtitle->move(x+ui->videoPlay->width()/2-m_subtitle->width()/2,y+ui->videoPlay->height()*3/4);
}
//2025-3-3-subtitle
void MainWindow::called_setSrt(){
    //qDebug()<<"what";
    QFont *font=new QFont(systemDialog->settings.value("subtitleFont","微软雅黑").toString(),systemDialog->settings.value("subtitleFontSize", "12").toInt());
    font->setBold(systemDialog->settings.value("subtitleFontBold",false).toBool());
    font->setItalic(systemDialog->settings.value("subtitleFontItalic",false).toBool());
    font->setUnderline(systemDialog->settings.value("subtitleFontUnderline",false).toBool());
    m_subtitle->setFont(*font);
    m_subtitle->setStyleSheet("QLabel { color: "+systemDialog->settings.value("subtitleColor", "black").toString()+"; }");
}
bool MainWindow::called_orNot_addSrt(QString srtfile)
{
    m_srtList.clear();
    QFile file(srtfile);
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"未找到外挂字幕文件："<<srtfile<<endl;
        return false;
    }
    m_srtList.clear();
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");

    QTextStream stream_src(&file);
    stream_src.setCodec(codec);
    //int t=1;
    while(!stream_src.atEnd()) {
        QString str = stream_src.readLine();
        str = str.replace('\r',"");//替换回车符
        str = str.replace('\n',"");//替换换行符
        bool ok;
        qint16 nID = str.toInt(&ok,10);
        if(ok)
        {
            Srt info;
            info.Num = nID;
            if(stream_src.atEnd())
                break;
            QString str2=stream_src.readLine();

            str2 = str2.replace('\r',"");//替换回车符
            str2 = str2.replace('\n',"");//替换换行符
            str2 = str2.replace(' ',"");//替换空格符

            if(str2=="")
                continue;
            info.Start = QTime::fromString(str2.split('-').first(),"hh:mm:ss,zzz");
            info.End = QTime::fromString(str2.split('>').last(),"hh:mm:ss,zzz");

            QString str3=stream_src.readLine();
            if(str3=="")
                continue;
            str3 = str3.replace('\r',"");//替换回车符
            str3 = str3.replace('\n',"");//替换换行符
            info.Content = str3;

            QString str4=stream_src.readLine();
            if(str4!=""){
            str4 = str4.replace('\r',"");//替换回车符
            str4 = str4.replace('\n',"");//替换换行符
            info.Content.append('\n');
            info.Content.append(str4);
            }

            m_srtList.append(info);

        }
    }
    file.close();
    return true;
}


void MainWindow::saveHistory()
{
    qDebug()<<"saveHistory is called";
    QSettings settings("Lumos", "VideoPlayer");  // 公司名和应用名
    settings.remove("HistoryList"); //删除上一次的系统注册表（因为可能会删除一些文件，但是注册表的信息较难更新）
    settings.beginWriteArray("HistoryList");
    for (int i = 0; i < historyList.size(); ++i) {
        settings.setArrayIndex(i);
        settings.setValue("path", historyList[i].path);
        settings.setValue("lastPlayTime", historyList[i].lastPlayTime);
        settings.setValue("duration", historyList[i].duration);
        settings.setValue("title", historyList[i].title);
    }
    settings.endArray();
    settings.setValue("currentIndex", currentIndex);  // 保存当前播放索引
}

bool MainWindow::saveToCsvAdvanced(const QString& fileName, const QList<QStringList>& data)//TODO 1
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "无法打开文件以写入:" << fileName;
        return false;
    }

    QTextStream out(&file);

    for (const QStringList& row : data)
    {
        QStringList formattedRow;
        for (const QString& field : row)
        {
            QString formattedField = field;
            if (field.contains(',') || field.contains('"'))
            {
                formattedField = "\"" + formattedField.replace("\"", "\"\"") + "\"";
            }
            formattedRow << formattedField;
        }
        out << formattedRow.join(",") << "\n";
    }
    return true;
}

bool MainWindow::saveCsvRecords(const QString& fileName){
    QList<QStringList> data;
    //添加csv文件的标题行
    data << QStringList{"url","title","isLiked","isDownload","watchTimes","lastTime","type"};
    //添加数据行
    for (const HistoryInfo& record : historyRecords) {
            data << record.toQStringList();
    }
    return saveToCsvAdvanced(fileName, data);
}

QList<QStringList> MainWindow::readFromCsv(const QString& fileName) //NOTE 读取外部csv转化为QList<QStringList>
{
    QList<QStringList> data;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "无法打开文件以读取:" << fileName;
        return data;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields;
        QString field;
        bool inQuotes = false;

        for (int i = 0; i < line.length(); ++i)
        {
            QChar currentChar = line[i];
            if (currentChar == '"')
            {
                if (inQuotes && i + 1 < line.length() && line[i + 1] == '"')
                {
                    field.append('"');
                    ++i;
                }
                else
                {
                    inQuotes = !inQuotes;
                }
            }
            else if (currentChar == ',' && !inQuotes)
            {
                fields.append(field.trimmed());
                field.clear();
            }
            else
            {
                field.append(currentChar);
            }
        }
        if (!field.isEmpty() || line.endsWith(','))
        {
            fields.append(field.trimmed());
        }
        if (!fields.isEmpty())
        {
            data.append(fields);
        }
    }
    file.close();
    return data;
}

bool MainWindow::readAndParseCsv(const QString& fileName) {
//    QList<HistoryInfo> records;
    QList<QStringList> rawData = readFromCsv(fileName);

    // 跳过空行和标题行（假设第一行是标题）
    for (int i = 1; i < rawData.size(); ++i) {
        const QStringList& row = rawData[i];
        if (row.isEmpty()) continue; // 过滤无效行
        historyRecords.append(HistoryInfo(row));
    }
    return true;
}

bool MainWindow::update_history_records(const QString& path_need_add, int type) {
    int existingIndex = -1;

    // 遍历查找是否已存在该视频记录
    for (int i = 0; i < historyRecords.size(); ++i) {
        if (historyRecords[i].url == path_need_add) {
            existingIndex = i;
            break;
        }
    }

    HistoryInfo updatedRecord;

    if (existingIndex != -1) {
        // 如果存在，提取原记录，删除旧位置
        updatedRecord = historyRecords.takeAt(existingIndex);
        updatedRecord.watchTimes += 1;
        updatedRecord.lastTime = QDateTime::currentDateTime();
    } else {
        // 如果不存在，创建新的记录
        updatedRecord.url = path_need_add;

        // 你可能想从路径提取一个标题，比如文件名
        QFileInfo fileInfo(path_need_add);
        updatedRecord.title = fileInfo.fileName();

        updatedRecord.watchTimes = 1;
        updatedRecord.lastTime = QDateTime::currentDateTime();
        updatedRecord.isDownload = 0;
        updatedRecord.isLiked = 0;
        updatedRecord.type = type;
    }

    // 添加到列表尾部（时间最新）
    historyRecords.append(updatedRecord);

    return true;
}



bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    // 处理 QSlider 的点击事件
    if (obj == ui->slider) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if (mouseEvent->button() == Qt::LeftButton) {
                int mouseX = mouseEvent->pos().x();
                int sliderWidth = ui->slider->width();
                int sliderValue = ui->slider->value();
                int sliderMax = ui->slider->maximum();

                double percentage = static_cast<double>(mouseX) / sliderWidth;
                percentage = qBound(0.0, percentage, 1.0);  // 限制范围 0~1
                int newValue = static_cast<int>(percentage * sliderMax);

                int handleWidth = 20;
                int handlePosition = (sliderValue * sliderWidth) / sliderMax;
                if (abs(mouseX - handlePosition) <= handleWidth / 2) {
                    return false;
                }

                ui->slider->setValue(newValue);
                MoveVideo(newValue);
                return true;
            }
        }
    }

    // 处理 QLabel（AiLogo）点击事件
    if (obj == ui->AiLogo) {
        if (event->type() == QEvent::MouseButtonRelease) {
            qDebug() << "AiLogo clicked!";
            if(isopen){
                m_keywordsSelected.clear();
                AiLogo_clicked();
            }
            else {
                QMessageBox::information(NULL,"提示","未获取资源，无法AI分析");
            }
            return true;
        }
    }

    // 处理键盘事件
    if (event->type() == QEvent::KeyPress) {
        if (obj == this || obj->parent() == this) {
            keyPressEvent(static_cast<QKeyEvent*>(event));
            return true;
        }
    }

    // 处理 QLabel（标签）的点击事件
    if (event->type() == QEvent::MouseButtonPress) {
        QLabel *label = qobject_cast<QLabel*>(obj);
        if (label) {
            QString tag = label->property("tagText").toString();
            qDebug() << "标签被点击:" << tag;  // 打印标签内容

            // 为了确认点击事件确实到达了这里，可以添加更多调试信息
            qDebug() << "Label's text:" << label->text();  // 打印标签的实际文本

            m_keywordsSelected.insert(label->text());

            return true;  // 拦截事件，防止 Qt 默认行为
        }
    }

    return QMainWindow::eventFilter(obj, event);  // 交给 Qt 继续处理其他事件
}


void MainWindow::on_ui_keywordLike_clicked(){
    QStringList te=m_keywordsSelected.values();
    if(te.size()>0)QMessageBox::information(NULL,"提示",te.join("\n")+"已收藏");
    else QMessageBox::information(NULL,"提示","未选中");
    m_keywordsSelected.clear();
}

void MainWindow::on_ui_keywordLike_2_clicked(){
    QStringList te=m_keywordsSelected.values();
    if(te.size()>0)QMessageBox::information(NULL,"提示",te.join("\n")+"已屏蔽");
    else QMessageBox::information(NULL,"提示","未选中");
    m_keywordsSelected.clear();
}

void MainWindow::on_ui_keywordSearch_clicked(){
    QStringList te=m_keywordsSelected.values();
    ui->lineEdit->setText(te.join(" "));
    ui->stackedWidget->setCurrentWidget(ui->personility);
    onPersonSearchTextChanged();
    ui->lineEdit->clear();
}

void MainWindow::on_ui_keywordSearch_2_clicked() {
    // 创建 sumTester
    sumTester* tester = new sumTester();

    // 获取图片数据
    QVector<QImage> chartImages = tester->getImages();


    // 触发初始图片加载
    tester->handleRequest("最近7天");


}


void MainWindow::loadHistory()
{
    QSettings settings("Lumos", "VideoPlayer");
    int size = settings.beginReadArray("HistoryList");
    qDebug()<<"loadHistory is called";
    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        VideoInfo info;
        info.path = settings.value("path").toString();
        info.lastPlayTime = settings.value("lastPlayTime", 0).toLongLong();
        info.duration = settings.value("duration", 0).toLongLong();
        info.title = settings.value("title", QFileInfo(info.path).fileName()).toString();
        historyList.append(info);

        // 添加到 UI
        QListWidgetItem* item = new QListWidgetItem(ui->historyListWidget);
        item->setSizeHint(QSize(300, 40));

        HistoryItem *historyItem = new HistoryItem(2,info.title, QString::number(info.duration), ui->historyListWidget, item, info.path);

        connect(historyItem, &HistoryItem::itemClicked, this, &MainWindow::listChoosePlay);
        connect(historyItem, &HistoryItem::aiItemclicked, this,&MainWindow::aiPlay);
        ui->historyListWidget->setItemWidget(item, historyItem);
    }
    settings.endArray();
//    this->repaint();
}


//点击动态的AI按钮
void MainWindow::AiLogo_clicked()
{

    accumulatedOutput.clear();
    appendMessage(videoFilePath,"get");

    // 获取应用程序所在目录
    QDir baseDir(QDir::currentPath());
    baseDir.cdUp();  // 退

    QString basePath = baseDir.absolutePath();  // 获取正确的路径
    QString pythonBasePath = basePath + "/Python312";


    QString pythonPath = baseDir.filePath("Python312/python.exe");
    QString scriptPath1 = baseDir.filePath("src/Detail-analyse.py");
    QString scriptPath2 = baseDir.filePath("src/Quick-analyse.py");




//========================================================================================//

    // 创建进程2（先运行）
    QProcess* process2 = new QProcess(this);
    m_processTimestamps.insert(process2, QDateTime::currentDateTime());
    QProcessEnvironment env2 = QProcessEnvironment::systemEnvironment();
    env2.insert("PATH", pythonBasePath + "/Library/bin;" + env2.value("PATH"));
    env2.insert("PYTHONPATH", pythonBasePath); // 添加 Python 环境路径
    process2->setProcessEnvironment(env2);

    // 监听进程2标准输出
    connect(process2, &QProcess::readyReadStandardOutput, [=](){
        QByteArray data = process2->readAllStandardOutput();
        QString output = QString::fromUtf8(data);
//        qDebug() << "Raw Process2 output:" << output;

        QStringList lines = output.split('\n', Qt::SkipEmptyParts);
        for (const QString& line : lines) {
            QString trimmedLine = line.trimmed();
//            qDebug() << "Trimmed line:" << trimmedLine;

            if (trimmedLine.startsWith("image_path:")) {
                QString imagePath = QDir::fromNativeSeparators(trimmedLine.mid(11));
                qDebug() << "Detected image path:" << imagePath;

                QFile imageFile(imagePath);
                qDebug() << "Image file exists:" << imageFile.exists();

                QPixmap pixmap;
                if (pixmap.load(imagePath)) {
                    qDebug() << "Image loaded successfully, size:" << pixmap.size();
                    QTextDocument* doc = ui->result->document();
                    QString imageKey = "image_" + QString::number(qrand());
                    doc->addResource(QTextDocument::ImageResource, QUrl(imageKey), pixmap);

                    QTextCursor cursor = ui->result->textCursor();
                    QTextImageFormat imageFormat;
                    imageFormat.setName(imageKey);
                    imageFormat.setWidth(300);
                    imageFormat.setHeight(300 * pixmap.height() / pixmap.width());
                    cursor.insertImage(imageFormat);
                    ui->result->append("");  // 换行
                    ui->result->moveCursor(QTextCursor::End);
                    qDebug() << "Image inserted into QPlainTextEdit";
                } else {
                    qDebug() << "Failed to load image:" << imagePath;
                    ui->result->append("[错误] 无法加载图片: " + imagePath);
                }
            } else {
                //ui->result->append(trimmedLine);
                ui->result->moveCursor(QTextCursor::End);
            }
        }
    });

    // 监听进程2错误输出
    connect(process2, &QProcess::readyReadStandardError, [=](){
        QString errorOutput = QString::fromUtf8(process2->readAllStandardError()).trimmed();
        ui->result->append("[进程2错误] " + errorOutput);
        qDebug() << "[进程2错误] " << errorOutput;  // 调试信息
    });

    // 监听进程2结束，完成后再启动 process1
    connect(process2, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
        this, [=](int exitCode, QProcess::ExitStatus exitStatus){
            QDateTime startTime = m_processTimestamps.value(process2);
            QString duration = QString::number(startTime.msecsTo(QDateTime::currentDateTime())) + "ms";

            if (exitStatus == QProcess::NormalExit) {
                ui->result->append(QString("进程2完成，耗时：%1\n").arg(duration));
            } else {
                ui->result->append(QString("[错误] 进程2异常终止（代码：%1）").arg(exitCode));
            }

            process2->deleteLater();
            m_processTimestamps.remove(process2);

            // `process2` 完成后，启动 `process1`
            QProcess* process1 = new QProcess(this);
            m_processTimestamps.insert(process1, QDateTime::currentDateTime());
            QProcessEnvironment env1 = QProcessEnvironment::systemEnvironment();
            env1.insert("PATH", pythonBasePath + "/Library/bin;" + env1.value("PATH"));
            process1->setProcessEnvironment(env1);

            // 监听标准输出
            connect(process1, &QProcess::readyReadStandardOutput, [=](){
                QString output = QString::fromUtf8(process1->readAllStandardOutput()).trimmed();
                ui->textEdit->insertPlainText(QString("%1").arg(output));
                ui->textEdit->moveCursor(QTextCursor::End);
                accumulatedOutput += output ; // 累积输出
            });


            // 监听进程1结束
            connect(process1, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
                this, [=](int exitCode, QProcess::ExitStatus exitStatus){
                    QDateTime startTime = m_processTimestamps.value(process1);
                    QString duration = QString::number(startTime.msecsTo(QDateTime::currentDateTime())) + "ms";

                    if (exitStatus == QProcess::NormalExit) {
                        ui->textEdit->appendPlainText(QString("进程1完成，耗时：%1\n").arg(duration));
                        updateTags(); // 调用封装函数更新标签
                    } else {
                        ui->textEdit->appendPlainText(QString("[错误] 进程1异常终止（代码：%1）").arg(exitCode));
                    }

                    process1->deleteLater();
                    m_processTimestamps.remove(process1);
                });

            // 启动进程1
            process1->start(pythonPath, QStringList() << scriptPath1 << videoFilePath);
            if (!process1->waitForStarted()) {
                ui->textEdit->appendPlainText("[错误] 进程1未成功启动！");
            }

        });

    // 启动进程2
    process2->start(pythonPath, QStringList() << scriptPath2 << videoFilePath);
    if (!process2->waitForStarted()) {
        ui->textEdit->appendPlainText("[错误] 进程2未成功启动！");
    }
}



void MainWindow::appendMessage(const QString message, QString type)
{
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    // 根据消息类型设置不同的样式
       if (type == "info") {
           QString icon = "✅";  // 信息图标
           ui->textEdit->appendPlainText(QString("%1 处理完成\n").arg(icon));
           ui->textEdit->appendPlainText(QString("[%1] 分析结果：%2").arg(timestamp).arg(message));
           ui->textEdit->appendPlainText("\n");  // 额外的换行
       } else if (type == "error") {
           QString icon = "❌";  // 信息图标
           ui->textEdit->appendPlainText(QString("[%1] 脚本异常\n").arg(icon));
           ui->textEdit->appendPlainText(QString("[%1] 分析结果：%2").arg(timestamp).arg(message));
           ui->textEdit->appendPlainText("\n");  // 额外的换行
       } else if (type == "loading") {
           QString icon = "🔄";  // 信息图标
           ui->textEdit->appendPlainText(QString("%1 %2\n").arg(icon).arg(message));
       }else
       {
           QString icon = "🚀";  // 信息图标
           ui->textEdit->appendPlainText(QString("%1 [%2] 分析启动：%3").arg(icon).arg(timestamp).arg(message));
           ui->textEdit->appendPlainText("\n");  // 额外的换行
       }
}

//2025-4-9 python thread

void MainWindow::m_download_historyitem(QString fileName, bool isdownloaded){
    QMessageBox::information(NULL,"提示","下载中");
    for(auto a:m_recommendVideos->m_rcmdVideos){
        if(a.filename==fileName){
            qDebug() << "Start DownLoading..." << fileName ;
            qDebug()<<"With uri:" <<a.uri;
            m_pythonTaskStart(QString("QT_getBV"),QString("getVideo_DOWNLOADED_COMMENTS"),QStringList{a.filename,a.uri});
        }
    }
}

void MainWindow::m_pythonTaskStart(const QString& pythonName,const QString& funcName,const QStringList& params) {
        // 复制 MainController 的 startPythonTask 实现
        QThread* thread = new QThread(this);
        PythonWorker* worker = new PythonWorker;
        worker->set_m_allinfo(pythonName, funcName, params);
        worker->moveToThread(thread);
        connect(thread, &QThread::started, worker, &PythonWorker::execute);
        connect(worker, &PythonWorker::finished, this,

            [this, thread, worker](QString py,QString func,QStringList par) {
                thread->quit();
                thread->wait();
                thread->deleteLater();
                worker->deleteLater();
                m_handleFinishedPythonTask(py,func,par);
            });
        thread->start();
}


void MainWindow::m_handleFinishedPythonTask(QString py,QString func,QStringList par){
    qDebug()<<"In mainwindow:"<<py<<func<<par;
    if(func=="getVideo_DOWNLOADED_COMMENTS"){
        QMessageBox::information(NULL,"提示","视频下载完成");
        for(auto a : m_recommendVideos->m_rcmdVideos){
            QString video_path=m_recommendVideos->m_filepath+a.filename+".mp4";
            if (QFile::exists(video_path)) {
                emit m_downloadfinished_history(a.filename);
            }
        }
    }
}

void MainWindow::on_analyse_button_clicked(){
    ui->stackedWidget_2->setCurrentWidget(ui->Analyse);
}

void MainWindow::on_type_button_clicked(){
    ui->stackedWidget_2->setCurrentWidget(ui->Type);
}

// 封装函数：提取并更新标签
void MainWindow::updateTags() {
    // 调试：输出原始 accumulatedOutput
    qDebug() << "综合分析结果原始内容:" << accumulatedOutput;

    // 提取综合分析结果中的视频类别标签
    // 调整正则：支持全角冒号和任意换行符（\n 或 \r\n）
    QRegularExpression re("【综合分析结果】视频类别[：:]([^\\n]+)(\\r\\n|\\n|$)");
    QRegularExpressionMatch match = re.match(accumulatedOutput);
    if (match.hasMatch()) {
        tags = match.captured(1).trimmed(); // 提取 "动作,射击,工业"
        qDebug() << "Extracted tags:" << tags;
        accumulatedOutput.clear();
    }else{
        tags=tags;
    }
        // 清空 ui->tags 中的旧标签
        for (QObject *obj : ui->tags->children()) {
            if (QLabel *label = qobject_cast<QLabel*>(obj)) {
                label->deleteLater();
            }
        }

        // 处理标签
        QStringList tagList = tags.split(",", QString::SkipEmptyParts);
        const int margin = 10; // 标签间距
        const int tagHeight = 30; // 标签高度
        QSize tagsSize = ui->tags->size();
        QList<QPoint> usedPositions;

        for (QString &tag : tagList) {
            tag = tag.trimmed();
            QLabel *tagLabel = new QLabel(tag, ui->tags);

            // 设置样式
            tagLabel->setStyleSheet(
                "QLabel {"
                    "background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #4facfe, stop:1 #00f2fe);"
                    "color: white;"
                    "border-radius: 8px;"
                    "padding: 4px 14px;"
                    "border: 1px solid #00c4cc;"
                    "font-size: 14px;"
                    "font-weight: bold;"
                    "line-height: 1.2em;"
                    "qproperty-alignment: AlignCenter;"
                    "min-height: 32px;"
                    "}"
                "QLabel:pressed {"
                    "background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #3d8ce0, stop:1 #00d4e0);"
                    "box-shadow: 1px 1px 3px rgba(0, 0, 0, 0.4);"
                    "}"
            );

            // 计算并设置大小
            QFontMetrics fm(tagLabel->font());
            int tagWidth = fm.horizontalAdvance(tag) + 34;
            int maxWidth = tagsSize.width() - 20;

            if (tagWidth > maxWidth) {
                tagWidth = maxWidth;
                tagLabel->setText(fm.elidedText(tag, Qt::ElideRight, tagWidth - 10));
            }

            tagLabel->setFixedSize(tagWidth, tagHeight);
            tagLabel->setToolTip(tag);
            tagLabel->setAlignment(Qt::AlignCenter);

            // 设置点击属性并安装事件过滤器
            tagLabel->setProperty("tagText", tag); // 存储 tag 内容
            tagLabel->installEventFilter(this);    // 安装事件过滤器

            // 随机位置，防止重叠
            bool positionFound = false;
            int maxAttempts = 50;
            while (!positionFound && maxAttempts-- > 0) {
                int x = QRandomGenerator::global()->bounded(margin, tagsSize.width() - tagWidth - margin);
                int y = QRandomGenerator::global()->bounded(margin, tagsSize.height() - tagHeight - margin);
                QRect newRect(x, y, tagWidth, tagHeight);
                positionFound = true;
                for (const QPoint &pos : usedPositions) {
                    QRect existingRect(pos.x(), pos.y(), fm.horizontalAdvance(tagList[usedPositions.indexOf(pos)]) + 20, tagHeight);
                    if (newRect.intersects(existingRect)) {
                        positionFound = false;
                        break;
                    }
                }
                if (positionFound) {
                    tagLabel->move(x, y);
                    usedPositions.append(QPoint(x, y));
                }
            }
            if (!positionFound) {
                tagLabel->move(margin, margin + usedPositions.size() * (tagHeight + margin));
                usedPositions.append(tagLabel->pos());
            }

            tagLabel->show();
        }

}

