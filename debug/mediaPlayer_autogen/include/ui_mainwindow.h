/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QFrame *topBar;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *titleIcon;
    QFrame *settingFrame;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *selectedButton;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *dayAndNight;
    QPushButton *min;
    QPushButton *max;
    QPushButton *close;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout;
    QFrame *videoPlay;
    QPushButton *openBtn;
    QPushButton *listButton;
    QLabel *backgroundlabel;
    QLabel *playlabel;
    QFrame *funcBar;
    QHBoxLayout *horizontalLayout_2;
    QLabel *BeginTime;
    QSlider *slider;
    QLabel *EndTime;
    QFrame *func;
    QHBoxLayout *horizontalLayout;
    QPushButton *voiceIcon;
    QSlider *voiceSlider;
    QLabel *voice;
    QSpacerItem *horizontalSpacer;
    QPushButton *stopIcon;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *lastIcon;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *playIcon;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *nextIcon;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;
    QPushButton *setting;
    QPushButton *allButton;
    QFrame *listView;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *playListBtn;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *personalityButton;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *aiButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *historyButton;
    QSpacerItem *horizontalSpacer_10;
    QStackedWidget *stackedWidget;
    QWidget *videoHistory;
    QVBoxLayout *verticalLayout_4;
    QFrame *searchFrame;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *filterButton;
    QLineEdit *searchLine;
    QListWidget *historyListWidget;
    QWidget *playList;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *scheme;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *deleteAll;
    QSpacerItem *horizontalSpacer_13;
    QListWidget *ui_playlist;
    QWidget *personility;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *refreshButton;
    QSpacerItem *horizontalSpacer_14;
    QLineEdit *lineEdit;
    QListWidget *personilityList;
    QWidget *AI;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *AiLogo;
    QLabel *label;
    QFrame *frame_51;
    QGridLayout *gridLayout;
    QLabel *type;
    QLabel *titles;
    QPushButton *avatar;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_91;
    QPushButton *analyse_button;
    QPushButton *type_button;
    QStackedWidget *stackedWidget_2;
    QWidget *Analyse;
    QVBoxLayout *verticalLayout_71;
    QLabel *label_2;
    QPlainTextEdit *textEdit;
    QLabel *label_3;
    QTextEdit *result;
    QWidget *Type;
    QWidget *tags;
    QPushButton *ui_keywordLike;
    QPushButton *ui_keywordSearch;
    QPushButton *ui_keywordLike_2;
    QPushButton *ui_keywordSearch_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1432, 1086);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setMouseTracking(true);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setMouseTracking(true);
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"\n"
"color: rgb(0, 0, 0);"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        topBar = new QFrame(centralwidget);
        topBar->setObjectName(QString::fromUtf8("topBar"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(topBar->sizePolicy().hasHeightForWidth());
        topBar->setSizePolicy(sizePolicy2);
        topBar->setMinimumSize(QSize(0, 50));
        topBar->setMaximumSize(QSize(16777215, 50));
        topBar->setMouseTracking(true);
        topBar->setFocusPolicy(Qt::NoFocus);
        topBar->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"\n"
"color: rgb(0, 0, 0);"));
        topBar->setFrameShape(QFrame::StyledPanel);
        topBar->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(topBar);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        titleIcon = new QPushButton(topBar);
        titleIcon->setObjectName(QString::fromUtf8("titleIcon"));
        titleIcon->setMinimumSize(QSize(40, 50));
        titleIcon->setMaximumSize(QSize(50, 50));
        titleIcon->setFocusPolicy(Qt::NoFocus);
        titleIcon->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icons/no1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        titleIcon->setIcon(icon);
        titleIcon->setIconSize(QSize(60, 60));

        horizontalLayout_4->addWidget(titleIcon);

        settingFrame = new QFrame(topBar);
        settingFrame->setObjectName(QString::fromUtf8("settingFrame"));
        settingFrame->setMinimumSize(QSize(30, 0));
        settingFrame->setFrameShape(QFrame::StyledPanel);
        settingFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(settingFrame);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        selectedButton = new QPushButton(settingFrame);
        selectedButton->setObjectName(QString::fromUtf8("selectedButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(selectedButton->sizePolicy().hasHeightForWidth());
        selectedButton->setSizePolicy(sizePolicy3);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(11);
        selectedButton->setFont(font);
        selectedButton->setFocusPolicy(Qt::NoFocus);
        selectedButton->setLayoutDirection(Qt::RightToLeft);
        selectedButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"    background: transparent;     \n"
"	color: rgb(53, 134, 255); \n"
"	padding-left: 30px;   \n"
"    padding-right: 10px;      \n"
"    text-align: left;\n"
"    qproperty-iconSize: 18px 18px;              \n"
"            }\n"
"QPushButton::icon{\n"
"	margin-left: 20px;       \n"
"    margin-right: 10px;\n"
"	padding-top: 5px;      \n"
"    padding-bottom: 5px;                  \n"
"            }\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/down.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/down.svg"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/down.svg"), QSize(), QIcon::Disabled, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/down.svg"), QSize(), QIcon::Disabled, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/down.svg"), QSize(), QIcon::Active, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/down.svg"), QSize(), QIcon::Active, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/down.svg"), QSize(), QIcon::Selected, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/down.svg"), QSize(), QIcon::Selected, QIcon::On);
        selectedButton->setIcon(icon1);
        selectedButton->setIconSize(QSize(18, 18));
        selectedButton->setCheckable(false);

        horizontalLayout_5->addWidget(selectedButton);


        horizontalLayout_4->addWidget(settingFrame);

        horizontalSpacer_8 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        dayAndNight = new QPushButton(topBar);
        dayAndNight->setObjectName(QString::fromUtf8("dayAndNight"));
        dayAndNight->setMinimumSize(QSize(50, 0));
        dayAndNight->setMaximumSize(QSize(50, 16777215));
        dayAndNight->setFocusPolicy(Qt::NoFocus);
        dayAndNight->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icons/nights.svg"), QSize(), QIcon::Normal, QIcon::Off);
        dayAndNight->setIcon(icon2);
        dayAndNight->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(dayAndNight);

        min = new QPushButton(topBar);
        min->setObjectName(QString::fromUtf8("min"));
        min->setMinimumSize(QSize(50, 0));
        min->setMaximumSize(QSize(50, 16777215));
        min->setFocusPolicy(Qt::NoFocus);
        min->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/icons/min.svg"), QSize(), QIcon::Normal, QIcon::Off);
        min->setIcon(icon3);
        min->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(min);

        max = new QPushButton(topBar);
        max->setObjectName(QString::fromUtf8("max"));
        max->setMinimumSize(QSize(50, 0));
        max->setMaximumSize(QSize(50, 16777215));
        max->setFocusPolicy(Qt::NoFocus);
        max->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/icons/max.svg"), QSize(), QIcon::Normal, QIcon::Off);
        max->setIcon(icon4);
        max->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(max);

        close = new QPushButton(topBar);
        close->setObjectName(QString::fromUtf8("close"));
        close->setMinimumSize(QSize(50, 0));
        close->setMaximumSize(QSize(50, 16777215));
        close->setFocusPolicy(Qt::NoFocus);
        close->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: red;\n"
"}\n"
"\n"
"\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/icons/close.svg"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon5);
        close->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(close);


        verticalLayout_3->addWidget(topBar);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setMinimumSize(QSize(0, 0));
        frame_2->setMaximumSize(QSize(16777215, 16777215));
        frame_2->setMouseTracking(true);
        frame_2->setFocusPolicy(Qt::NoFocus);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy1.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy1);
        frame_3->setMouseTracking(true);
        frame_3->setFocusPolicy(Qt::NoFocus);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_3);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        videoPlay = new QFrame(frame_3);
        videoPlay->setObjectName(QString::fromUtf8("videoPlay"));
        videoPlay->setEnabled(true);
        sizePolicy1.setHeightForWidth(videoPlay->sizePolicy().hasHeightForWidth());
        videoPlay->setSizePolicy(sizePolicy1);
        videoPlay->setMinimumSize(QSize(100, 100));
        videoPlay->setMouseTracking(true);
        videoPlay->setFocusPolicy(Qt::NoFocus);
        videoPlay->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"\n"
"color: rgb(0, 0, 0);"));
        videoPlay->setFrameShape(QFrame::StyledPanel);
        videoPlay->setFrameShadow(QFrame::Raised);
        openBtn = new QPushButton(videoPlay);
        openBtn->setObjectName(QString::fromUtf8("openBtn"));
        openBtn->setGeometry(QRect(340, 190, 166, 100));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(openBtn->sizePolicy().hasHeightForWidth());
        openBtn->setSizePolicy(sizePolicy4);
        openBtn->setMinimumSize(QSize(0, 100));
        QFont font1;
        font1.setPointSize(14);
        openBtn->setFont(font1);
        openBtn->setMouseTracking(true);
        openBtn->setFocusPolicy(Qt::NoFocus);
        openBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/icons/open.svg"), QSize(), QIcon::Normal, QIcon::Off);
        openBtn->setIcon(icon6);
        openBtn->setIconSize(QSize(50, 50));
        listButton = new QPushButton(videoPlay);
        listButton->setObjectName(QString::fromUtf8("listButton"));
        listButton->setGeometry(QRect(580, 200, 30, 40));
        sizePolicy4.setHeightForWidth(listButton->sizePolicy().hasHeightForWidth());
        listButton->setSizePolicy(sizePolicy4);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setPointSize(14);
        listButton->setFont(font2);
        listButton->setMouseTracking(true);
        listButton->setFocusPolicy(Qt::NoFocus);
        listButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(64, 66, 68);\n"
"    border: none;\n"
"}\n"
""));
        backgroundlabel = new QLabel(videoPlay);
        backgroundlabel->setObjectName(QString::fromUtf8("backgroundlabel"));
        backgroundlabel->setGeometry(QRect(0, 0, 331, 391));
        sizePolicy1.setHeightForWidth(backgroundlabel->sizePolicy().hasHeightForWidth());
        backgroundlabel->setSizePolicy(sizePolicy1);
        backgroundlabel->setMouseTracking(true);
        backgroundlabel->setFocusPolicy(Qt::NoFocus);
        backgroundlabel->setScaledContents(true);
        playlabel = new QLabel(videoPlay);
        playlabel->setObjectName(QString::fromUtf8("playlabel"));
        playlabel->setGeometry(QRect(470, 80, 151, 91));
        playlabel->setMouseTracking(true);
        playlabel->setFocusPolicy(Qt::NoFocus);
        playlabel->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(videoPlay);

        funcBar = new QFrame(frame_3);
        funcBar->setObjectName(QString::fromUtf8("funcBar"));
        sizePolicy2.setHeightForWidth(funcBar->sizePolicy().hasHeightForWidth());
        funcBar->setSizePolicy(sizePolicy2);
        funcBar->setMaximumSize(QSize(16777215, 40));
        funcBar->setMouseTracking(false);
        funcBar->setFocusPolicy(Qt::NoFocus);
        funcBar->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"\n"
"color: rgb(0, 0, 0);"));
        funcBar->setFrameShape(QFrame::StyledPanel);
        funcBar->setFrameShadow(QFrame::Raised);
        funcBar->setLineWidth(0);
        horizontalLayout_2 = new QHBoxLayout(funcBar);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        BeginTime = new QLabel(funcBar);
        BeginTime->setObjectName(QString::fromUtf8("BeginTime"));
        BeginTime->setMouseTracking(false);
        BeginTime->setFocusPolicy(Qt::NoFocus);
        BeginTime->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  background-color: #ffffff;\n"
"\n"
"color: rgb(0, 0, 0);\n"
"}"));

        horizontalLayout_2->addWidget(BeginTime);

        slider = new QSlider(funcBar);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setEnabled(true);
        QFont font3;
        font3.setStyleStrategy(QFont::PreferDefault);
        slider->setFont(font3);
        slider->setMouseTracking(false);
        slider->setFocusPolicy(Qt::NoFocus);
        slider->setStyleSheet(QString::fromUtf8("QSlider{\n"
"        border-radius:6px; \n"
"background-color: #ffffff;\n"
"\n"
"color: rgb(0, 0, 0);   \n"
" };\n"
""));
        slider->setMaximum(100);
        slider->setOrientation(Qt::Horizontal);
        slider->setTickPosition(QSlider::NoTicks);

        horizontalLayout_2->addWidget(slider);

        EndTime = new QLabel(funcBar);
        EndTime->setObjectName(QString::fromUtf8("EndTime"));
        EndTime->setFocusPolicy(Qt::NoFocus);
        EndTime->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  background-color: #ffffff;\n"
"\n"
"color: rgb(0, 0, 0);\n"
"}"));

        horizontalLayout_2->addWidget(EndTime);


        verticalLayout->addWidget(funcBar);

        func = new QFrame(frame_3);
        func->setObjectName(QString::fromUtf8("func"));
        sizePolicy2.setHeightForWidth(func->sizePolicy().hasHeightForWidth());
        func->setSizePolicy(sizePolicy2);
        func->setMinimumSize(QSize(0, 50));
        func->setMaximumSize(QSize(16777215, 50));
        func->setMouseTracking(false);
        func->setFocusPolicy(Qt::NoFocus);
        func->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border: none;\n"
"background-color: #ffffff;\n"
"\n"
"color: rgb(0, 0, 0);\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(func);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        voiceIcon = new QPushButton(func);
        voiceIcon->setObjectName(QString::fromUtf8("voiceIcon"));
        voiceIcon->setMinimumSize(QSize(35, 35));
        voiceIcon->setMaximumSize(QSize(35, 35));
        voiceIcon->setMouseTracking(false);
        voiceIcon->setFocusPolicy(Qt::NoFocus);
        voiceIcon->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../../icons/voice-on.svg"), QSize(), QIcon::Normal, QIcon::Off);
        voiceIcon->setIcon(icon7);
        voiceIcon->setIconSize(QSize(35, 35));

        horizontalLayout->addWidget(voiceIcon);

        voiceSlider = new QSlider(func);
        voiceSlider->setObjectName(QString::fromUtf8("voiceSlider"));
        sizePolicy4.setHeightForWidth(voiceSlider->sizePolicy().hasHeightForWidth());
        voiceSlider->setSizePolicy(sizePolicy4);
        voiceSlider->setMinimumSize(QSize(160, 0));
        voiceSlider->setMaximumSize(QSize(160, 16777215));
        voiceSlider->setMouseTracking(false);
        voiceSlider->setFocusPolicy(Qt::NoFocus);
        voiceSlider->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"\n"
"color: rgb(0, 0, 0);"));
        voiceSlider->setMaximum(100);
        voiceSlider->setValue(100);
        voiceSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(voiceSlider);

        voice = new QLabel(func);
        voice->setObjectName(QString::fromUtf8("voice"));
        sizePolicy4.setHeightForWidth(voice->sizePolicy().hasHeightForWidth());
        voice->setSizePolicy(sizePolicy4);
        voice->setMinimumSize(QSize(60, 50));
        voice->setMaximumSize(QSize(60, 16777215));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font4.setPointSize(12);
        voice->setFont(font4);
        voice->setMouseTracking(false);
        voice->setFocusPolicy(Qt::NoFocus);
        voice->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  background-color: #ffffff;\n"
"\n"
"color: rgb(0, 0, 0);\n"
"}"));
        voice->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(voice);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        stopIcon = new QPushButton(func);
        stopIcon->setObjectName(QString::fromUtf8("stopIcon"));
        sizePolicy4.setHeightForWidth(stopIcon->sizePolicy().hasHeightForWidth());
        stopIcon->setSizePolicy(sizePolicy4);
        stopIcon->setMinimumSize(QSize(40, 40));
        stopIcon->setMouseTracking(false);
        stopIcon->setFocusPolicy(Qt::NoFocus);
        stopIcon->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../../icons/stop.svg"), QSize(), QIcon::Normal, QIcon::Off);
        stopIcon->setIcon(icon8);
        stopIcon->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(stopIcon);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lastIcon = new QPushButton(func);
        lastIcon->setObjectName(QString::fromUtf8("lastIcon"));
        sizePolicy4.setHeightForWidth(lastIcon->sizePolicy().hasHeightForWidth());
        lastIcon->setSizePolicy(sizePolicy4);
        lastIcon->setMinimumSize(QSize(40, 40));
        lastIcon->setMaximumSize(QSize(1000, 1000));
        lastIcon->setMouseTracking(false);
        lastIcon->setFocusPolicy(Qt::NoFocus);
        lastIcon->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("../../icons/last.svg"), QSize(), QIcon::Normal, QIcon::Off);
        lastIcon->setIcon(icon9);
        lastIcon->setIconSize(QSize(45, 45));

        horizontalLayout->addWidget(lastIcon);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        playIcon = new QPushButton(func);
        playIcon->setObjectName(QString::fromUtf8("playIcon"));
        playIcon->setEnabled(true);
        playIcon->setMinimumSize(QSize(50, 50));
        playIcon->setMouseTracking(false);
        playIcon->setFocusPolicy(Qt::NoFocus);
        playIcon->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"    qproperty-iconSize: 50px 50px;\n"
"}\n"
"\n"
""));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("../../icons/pause.svg"), QSize(), QIcon::Normal, QIcon::Off);
        playIcon->setIcon(icon10);
        playIcon->setIconSize(QSize(50, 50));
        playIcon->setCheckable(false);
        playIcon->setAutoDefault(false);

        horizontalLayout->addWidget(playIcon);

        horizontalSpacer_5 = new QSpacerItem(5, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        nextIcon = new QPushButton(func);
        nextIcon->setObjectName(QString::fromUtf8("nextIcon"));
        nextIcon->setMinimumSize(QSize(40, 40));
        nextIcon->setMaximumSize(QSize(10000, 1000));
        nextIcon->setMouseTracking(false);
        nextIcon->setFocusPolicy(Qt::NoFocus);
        nextIcon->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"	qproperty-iconSize: 45px 45px;\n"
"}\n"
""));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("../../icons/next.svg"), QSize(), QIcon::Normal, QIcon::Off);
        nextIcon->setIcon(icon11);
        nextIcon->setIconSize(QSize(45, 45));

        horizontalLayout->addWidget(nextIcon);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_4 = new QLabel(func);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy5);
        label_4->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(label_4);

        setting = new QPushButton(func);
        setting->setObjectName(QString::fromUtf8("setting"));
        sizePolicy4.setHeightForWidth(setting->sizePolicy().hasHeightForWidth());
        setting->setSizePolicy(sizePolicy4);
        setting->setMinimumSize(QSize(100, 40));
        setting->setMaximumSize(QSize(100, 16777215));
        setting->setFocusPolicy(Qt::NoFocus);
        setting->setLayoutDirection(Qt::LeftToRight);
        setting->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"\n"
"}\n"
""));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/icons/setting.svg"), QSize(), QIcon::Normal, QIcon::Off);
        setting->setIcon(icon12);
        setting->setIconSize(QSize(45, 45));

        horizontalLayout->addWidget(setting);

        allButton = new QPushButton(func);
        allButton->setObjectName(QString::fromUtf8("allButton"));
        sizePolicy4.setHeightForWidth(allButton->sizePolicy().hasHeightForWidth());
        allButton->setSizePolicy(sizePolicy4);
        allButton->setMinimumSize(QSize(35, 35));
        allButton->setMouseTracking(false);
        allButton->setFocusPolicy(Qt::NoFocus);
        allButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
""));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8("../../icons/\345\205\250\345\261\217 (1).svg"), QSize(), QIcon::Normal, QIcon::Off);
        allButton->setIcon(icon13);
        allButton->setIconSize(QSize(35, 35));

        horizontalLayout->addWidget(allButton);


        verticalLayout->addWidget(func);


        horizontalLayout_3->addWidget(frame_3);

        listView = new QFrame(frame_2);
        listView->setObjectName(QString::fromUtf8("listView"));
        sizePolicy5.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy5);
        listView->setMinimumSize(QSize(380, 0));
        listView->setMaximumSize(QSize(380, 16777215));
        listView->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: #404244;  /* \351\200\211\346\213\251\344\275\240\345\226\234\346\254\242\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));
        listView->setFrameShape(QFrame::StyledPanel);
        listView->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(listView);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(listView);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 60));
        frame->setStyleSheet(QString::fromUtf8("border:none;\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame);
        horizontalLayout_6->setSpacing(4);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(6, 6, 6, 6);
        playListBtn = new QPushButton(frame);
        playListBtn->setObjectName(QString::fromUtf8("playListBtn"));
        playListBtn->setMinimumSize(QSize(35, 35));
        playListBtn->setCursor(QCursor(Qt::PointingHandCursor));
        playListBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background:transparent;\n"
"	border:none;\n"
"}"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/icons/playList.svg"), QSize(), QIcon::Normal, QIcon::Off);
        playListBtn->setIcon(icon14);
        playListBtn->setIconSize(QSize(30, 30));

        horizontalLayout_6->addWidget(playListBtn);

        horizontalSpacer_9 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        personalityButton = new QPushButton(frame);
        personalityButton->setObjectName(QString::fromUtf8("personalityButton"));
        personalityButton->setMinimumSize(QSize(35, 35));
        personalityButton->setCursor(QCursor(Qt::PointingHandCursor));
        personalityButton->setFocusPolicy(Qt::NoFocus);
        personalityButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background:transparent;\n"
"	border:none;\n"
"}"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix1/icons/recommend.svg"), QSize(), QIcon::Normal, QIcon::Off);
        personalityButton->setIcon(icon15);
        personalityButton->setIconSize(QSize(30, 30));

        horizontalLayout_6->addWidget(personalityButton);

        horizontalSpacer_7 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        aiButton = new QPushButton(frame);
        aiButton->setObjectName(QString::fromUtf8("aiButton"));
        aiButton->setMinimumSize(QSize(35, 35));
        aiButton->setCursor(QCursor(Qt::PointingHandCursor));
        aiButton->setFocusPolicy(Qt::NoFocus);
        aiButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background:transparent;\n"
"	border:none;\n"
"}"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/new/prefix1/icons/aiIcon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        aiButton->setIcon(icon16);
        aiButton->setIconSize(QSize(30, 30));

        horizontalLayout_6->addWidget(aiButton);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        historyButton = new QPushButton(frame);
        historyButton->setObjectName(QString::fromUtf8("historyButton"));
        historyButton->setMinimumSize(QSize(35, 35));
        historyButton->setCursor(QCursor(Qt::PointingHandCursor));
        historyButton->setFocusPolicy(Qt::NoFocus);
        historyButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background:transparent;\n"
"	border:none;\n"
"}"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/new/prefix1/icons/historyRecord.svg"), QSize(), QIcon::Normal, QIcon::Off);
        historyButton->setIcon(icon17);
        historyButton->setIconSize(QSize(30, 30));

        horizontalLayout_6->addWidget(historyButton);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);


        verticalLayout_2->addWidget(frame);

        stackedWidget = new QStackedWidget(listView);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        sizePolicy5.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy5);
        stackedWidget->setMinimumSize(QSize(380, 0));
        videoHistory = new QWidget();
        videoHistory->setObjectName(QString::fromUtf8("videoHistory"));
        sizePolicy5.setHeightForWidth(videoHistory->sizePolicy().hasHeightForWidth());
        videoHistory->setSizePolicy(sizePolicy5);
        videoHistory->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"	background:white;\n"
"	border:none;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(videoHistory);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        searchFrame = new QFrame(videoHistory);
        searchFrame->setObjectName(QString::fromUtf8("searchFrame"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(searchFrame->sizePolicy().hasHeightForWidth());
        searchFrame->setSizePolicy(sizePolicy6);
        searchFrame->setMinimumSize(QSize(0, 55));
        searchFrame->setMaximumSize(QSize(16777215, 1666666));
        searchFrame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background:white;\n"
"	background-color: rgb(222, 222, 222);\n"
"}"));
        searchFrame->setFrameShape(QFrame::StyledPanel);
        searchFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(searchFrame);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        filterButton = new QPushButton(searchFrame);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));
        sizePolicy4.setHeightForWidth(filterButton->sizePolicy().hasHeightForWidth());
        filterButton->setSizePolicy(sizePolicy4);
        filterButton->setMinimumSize(QSize(100, 35));
        filterButton->setMaximumSize(QSize(16666, 35));
        filterButton->setCursor(QCursor(Qt::PointingHandCursor));
        filterButton->setLayoutDirection(Qt::LeftToRight);
        filterButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background:transparent;\n"
"	color: rgb(0, 0, 0);\n"
"	border:none;\n"
"	padding:0;\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
" QPushButton::menu-indicator {\n"
"            image: none;\n"
"        }\n"
"\n"
""));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/new/prefix1/icons/filter.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon18.addFile(QString::fromUtf8(":/new/prefix1/icons/filter1.svg"), QSize(), QIcon::Normal, QIcon::On);
        icon18.addFile(QString::fromUtf8(":/new/prefix1/icons/filter1.svg"), QSize(), QIcon::Disabled, QIcon::On);
        icon18.addFile(QString::fromUtf8(":/new/prefix1/icons/filter1.svg"), QSize(), QIcon::Active, QIcon::On);
        icon18.addFile(QString::fromUtf8(":/new/prefix1/icons/filter1.svg"), QSize(), QIcon::Selected, QIcon::On);
        filterButton->setIcon(icon18);
        filterButton->setIconSize(QSize(30, 30));

        horizontalLayout_8->addWidget(filterButton);

        searchLine = new QLineEdit(searchFrame);
        searchLine->setObjectName(QString::fromUtf8("searchLine"));
        searchLine->setMinimumSize(QSize(0, 30));
        searchLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	background:white;\n"
"	border:1px solid gray;\n"
"	border-radius:15px;\n"
"	padding-left: 2px;\n"
"\n"
"        }\n"
"QLineEdit:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QLineEdit:checked{\n"
"	\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        horizontalLayout_8->addWidget(searchLine);


        verticalLayout_4->addWidget(searchFrame);

        historyListWidget = new QListWidget(videoHistory);
        historyListWidget->setObjectName(QString::fromUtf8("historyListWidget"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(historyListWidget->sizePolicy().hasHeightForWidth());
        historyListWidget->setSizePolicy(sizePolicy7);
        historyListWidget->setMinimumSize(QSize(380, 0));
        historyListWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"      border: none;\n"
"	 background: white;\n"
"    }\n"
"    QScrollBar:vertical {\n"
"        border: none;\n"
"        background: white;\n"
"        width: 8px;  /* \346\216\247\345\210\266\346\273\232\345\212\250\346\235\241\347\232\204\345\256\275\345\272\246 */\n"
"        margin: 0px 0px 0px 0px;\n"
"    }\n"
"\n"
"    QScrollBar::handle:vertical {\n"
"        background: rgba(128, 128, 128, 150); /* \344\275\277\346\273\232\345\212\250\346\235\241\345\217\230\347\273\206 */\n"
"        min-height: 10px;\n"
"	    max-height: 10px;\n"
"        border-radius: 4px; /* \345\234\206\350\247\222\346\273\232\345\212\250\346\235\241 */\n"
"    }\n"
"    QScrollBar::handle:vertical:hover {\n"
"        background: rgba(100, 100, 100, 180); /* \346\202\254\346\265\256\346\227\266\345\212\240\346\267\261\351\242\234\350\211\262 */\n"
"    }\n"
"    QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"        border: none;\n"
"        background: none;\n"
"    }\n"
"    QScrollBar::"
                        "up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"        background: none;\n"
"    }\n"
"    QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"        background: none;\n"
"    }\n"
""));
        historyListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_4->addWidget(historyListWidget);

        stackedWidget->addWidget(videoHistory);
        playList = new QWidget();
        playList->setObjectName(QString::fromUtf8("playList"));
        playList->setCursor(QCursor(Qt::ArrowCursor));
        verticalLayout_7 = new QVBoxLayout(playList);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(playList);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        sizePolicy6.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy6);
        frame_5->setMinimumSize(QSize(0, 55));
        frame_5->setMaximumSize(QSize(16777215, 16666666));
        frame_5->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background:white;\n"
"	background-color: rgb(222, 222, 222);\n"
"}"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_9 = new QHBoxLayout(frame_5);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        scheme = new QPushButton(frame_5);
        scheme->setObjectName(QString::fromUtf8("scheme"));
        scheme->setMinimumSize(QSize(150, 30));
        scheme->setCursor(QCursor(Qt::PointingHandCursor));
        scheme->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(0, 0, 0);\n"
"	background:transparent;\n"
"	border:none;\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
" QPushButton::menu-indicator {\n"
"            image: none;\n"
"        }\n"
"\n"
""));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/new/prefix1/icons/playScheme.svg"), QSize(), QIcon::Normal, QIcon::Off);
        scheme->setIcon(icon19);
        scheme->setIconSize(QSize(30, 30));

        horizontalLayout_9->addWidget(scheme);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_11);

        deleteAll = new QPushButton(frame_5);
        deleteAll->setObjectName(QString::fromUtf8("deleteAll"));
        deleteAll->setMinimumSize(QSize(0, 30));
        deleteAll->setCursor(QCursor(Qt::PointingHandCursor));
        deleteAll->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background:transparent;\n"
"	border:none;\n"
"}\n"
"\n"
"\n"
""));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/new/prefix1/icons/delete.svg"), QSize(), QIcon::Normal, QIcon::Off);
        deleteAll->setIcon(icon20);
        deleteAll->setIconSize(QSize(30, 30));

        horizontalLayout_9->addWidget(deleteAll);

        horizontalSpacer_13 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_13);


        verticalLayout_7->addWidget(frame_5);

        ui_playlist = new QListWidget(playList);
        ui_playlist->setObjectName(QString::fromUtf8("ui_playlist"));
        ui_playlist->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"      border: none;\n"
"	 background: white;\n"
"    }\n"
"    QScrollBar:vertical {\n"
"        border: none;\n"
"        background: white;\n"
"        width: 8px;  /* \346\216\247\345\210\266\346\273\232\345\212\250\346\235\241\347\232\204\345\256\275\345\272\246 */\n"
"        margin: 0px 0px 0px 0px;\n"
"    }\n"
"\n"
"    QScrollBar::handle:vertical {\n"
"        background: rgba(128, 128, 128, 150); /* \344\275\277\346\273\232\345\212\250\346\235\241\345\217\230\347\273\206 */\n"
"        min-height: 10px;\n"
"	    max-height: 10px;\n"
"        border-radius: 4px; /* \345\234\206\350\247\222\346\273\232\345\212\250\346\235\241 */\n"
"    }\n"
"    QScrollBar::handle:vertical:hover {\n"
"        background: rgba(100, 100, 100, 180); /* \346\202\254\346\265\256\346\227\266\345\212\240\346\267\261\351\242\234\350\211\262 */\n"
"    }\n"
"    QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"        border: none;\n"
"        background: none;\n"
"    }\n"
"    QScrollBar::"
                        "up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"        background: none;\n"
"    }\n"
"    QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"        background: none;\n"
"    }\n"
""));

        verticalLayout_7->addWidget(ui_playlist);

        stackedWidget->addWidget(playList);
        personility = new QWidget();
        personility->setObjectName(QString::fromUtf8("personility"));
        personility->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"	background:white;\n"
"	border:none;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(personility);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_6 = new QFrame(personility);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        sizePolicy6.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy6);
        frame_6->setMinimumSize(QSize(0, 55));
        frame_6->setMaximumSize(QSize(16777215, 166668));
        frame_6->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background:white;\n"
"	background-color: rgb(222, 222, 222);\n"
"}"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(frame_6);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(20, 0, 0, 0);
        refreshButton = new QPushButton(frame_6);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));
        refreshButton->setMinimumSize(QSize(0, 35));
        refreshButton->setCursor(QCursor(Qt::PointingHandCursor));
        refreshButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background:transparent;\n"
"	border:none;\n"
"}"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/new/prefix1/icons/refresh.svg"), QSize(), QIcon::Normal, QIcon::Off);
        refreshButton->setIcon(icon21);
        refreshButton->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(refreshButton);

        horizontalSpacer_14 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_14);

        lineEdit = new QLineEdit(frame_6);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	background:white;\n"
"	border:1px solid gray;\n"
"	border-radius:15px;\n"
"	padding-left: 2px;\n"
"        }\n"
"QLineEdit:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QLineEdit:checked{\n"
"	\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        horizontalLayout_10->addWidget(lineEdit);


        verticalLayout_5->addWidget(frame_6);

        personilityList = new QListWidget(personility);
        personilityList->setObjectName(QString::fromUtf8("personilityList"));
        personilityList->setToolTipDuration(-1);
        personilityList->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"	background-color: rgb(237, 237, 237);\n"
"      border: none;\n"
"    }\n"
"     QScrollBar:vertical {\n"
"        border: none;\n"
"        background: white;\n"
"        width: 8px;  /* \346\216\247\345\210\266\346\273\232\345\212\250\346\235\241\347\232\204\345\256\275\345\272\246 */\n"
"        margin: 0px 0px 0px 0px;\n"
"    }\n"
"\n"
"    QScrollBar::handle:vertical {\n"
"        background: rgba(128, 128, 128, 150); /* \344\275\277\346\273\232\345\212\250\346\235\241\345\217\230\347\273\206 */\n"
"        min-height: 10px;\n"
"	    max-height: 10px;\n"
"        border-radius: 4px; /* \345\234\206\350\247\222\346\273\232\345\212\250\346\235\241 */\n"
"    }\n"
"    QScrollBar::handle:vertical:hover {\n"
"        background: rgba(100, 100, 100, 180); /* \346\202\254\346\265\256\346\227\266\345\212\240\346\267\261\351\242\234\350\211\262 */\n"
"    }\n"
"    QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"        border: none;\n"
"        background: none;\n"
"    }\n"
""
                        "    QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"        background: none;\n"
"    }\n"
"    QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"        background: none;\n"
"    }\n"
""));
        personilityList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_5->addWidget(personilityList);

        stackedWidget->addWidget(personility);
        AI = new QWidget();
        AI->setObjectName(QString::fromUtf8("AI"));
        AI->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 33, 57);"));
        verticalLayout_6 = new QVBoxLayout(AI);
        verticalLayout_6->setSpacing(19);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(10, 16, 10, 8);
        frame_4 = new QFrame(AI);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(0, 140));
        frame_4->setMaximumSize(QSize(16777215, 16777215));
        frame_4->setStyleSheet(QString::fromUtf8("     font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(0, 33, 57);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_4);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        AiLogo = new QLabel(frame_4);
        AiLogo->setObjectName(QString::fromUtf8("AiLogo"));
        AiLogo->setMinimumSize(QSize(140, 0));
        AiLogo->setMaximumSize(QSize(140, 110));
        AiLogo->setMouseTracking(true);
        AiLogo->setAutoFillBackground(false);
        AiLogo->setStyleSheet(QString::fromUtf8(""));
        AiLogo->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icons/ai.gif")));
        AiLogo->setScaledContents(true);
        AiLogo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(AiLogo);

        label = new QLabel(frame_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 0));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        label->setFont(font5);
        label->setStyleSheet(QString::fromUtf8("color: rgb(245, 244, 241);"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        horizontalLayout_7->addWidget(label);


        verticalLayout_6->addWidget(frame_4);

        frame_51 = new QFrame(AI);
        frame_51->setObjectName(QString::fromUtf8("frame_51"));
        frame_51->setMinimumSize(QSize(0, 130));
        frame_51->setMaximumSize(QSize(16777215, 16777215));
        frame_51->setContextMenuPolicy(Qt::DefaultContextMenu);
        frame_51->setLayoutDirection(Qt::LeftToRight);
        frame_51->setStyleSheet(QString::fromUtf8("QFrame#frame_5{\n"
"    border: 1.3px dashed #FFFFFF;\n"
"}"));
        frame_51->setFrameShape(QFrame::StyledPanel);
        frame_51->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_51);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 9, -1, -1);
        type = new QLabel(frame_51);
        type->setObjectName(QString::fromUtf8("type"));
        type->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(type, 1, 1, 1, 1);

        titles = new QLabel(frame_51);
        titles->setObjectName(QString::fromUtf8("titles"));
        titles->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(titles, 0, 1, 1, 1);

        avatar = new QPushButton(frame_51);
        avatar->setObjectName(QString::fromUtf8("avatar"));
        avatar->setMinimumSize(QSize(0, 105));
        avatar->setAutoFillBackground(false);
        avatar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
""));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/new/prefix1/icons/default.png"), QSize(), QIcon::Normal, QIcon::Off);
        avatar->setIcon(icon22);
        avatar->setIconSize(QSize(167, 105));
        avatar->setCheckable(false);

        gridLayout->addWidget(avatar, 0, 0, 2, 1);


        verticalLayout_6->addWidget(frame_51);

        frame_8 = new QFrame(AI);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setMinimumSize(QSize(0, 100));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_8);
        verticalLayout_8->setSpacing(4);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(2, -1, 2, 0);
        frame_7 = new QFrame(frame_8);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setMinimumSize(QSize(0, 0));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_91 = new QHBoxLayout(frame_7);
        horizontalLayout_91->setObjectName(QString::fromUtf8("horizontalLayout_91"));
        horizontalLayout_91->setContentsMargins(8, 2, 8, 2);
        analyse_button = new QPushButton(frame_7);
        analyse_button->setObjectName(QString::fromUtf8("analyse_button"));
        analyse_button->setMinimumSize(QSize(0, 30));
        QFont font6;
        font6.setPointSize(10);
        analyse_button->setFont(font6);
        analyse_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #4682B4, stop:1 #1E90FF); /* \346\270\220\345\217\230\357\274\232\344\270\255\350\223\235\345\210\260\351\262\234\350\223\235 */\n"
"    color: #FFFFFF; /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    border: 1px solid #87CEEB; /* \346\265\205\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 6px;\n"
"    padding: 2px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #6495ED, stop:1 #4169E1); /* \346\202\254\345\201\234\346\227\266\357\274\232\346\233\264\344\272\256\347\232\204\346\270\220\345\217\230 */\n"
"    border: 1px solid #B0E0E6; /* \344\272\256\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    color: #F0FFFF; /* \346\226\207\345\255\227\345\217\230\344\270\272\346\265\205\351\235\222\350\211\262 */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #104E8B; /* \346\214\211\344\270\213\346\227\266\357\274\232"
                        "\345\215\225\344\270\200\346\267\261\350\223\235\350\211\262 */\n"
"    border: 1px solid #483D8B; /* \346\267\261\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    color: #E0FFFF; /* \346\265\205\351\235\222\350\211\262\346\226\207\345\255\227 */\n"
"}"));

        horizontalLayout_91->addWidget(analyse_button);

        type_button = new QPushButton(frame_7);
        type_button->setObjectName(QString::fromUtf8("type_button"));
        type_button->setMinimumSize(QSize(0, 30));
        type_button->setFont(font6);
        type_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #4682B4, stop:1 #1E90FF); /* \346\270\220\345\217\230\357\274\232\344\270\255\350\223\235\345\210\260\351\262\234\350\223\235 */\n"
"    color: #FFFFFF; /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    border: 1px solid #87CEEB; /* \346\265\205\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 6px;\n"
"    padding: 2px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #6495ED, stop:1 #4169E1); /* \346\202\254\345\201\234\346\227\266\357\274\232\346\233\264\344\272\256\347\232\204\346\270\220\345\217\230 */\n"
"    border: 1px solid #B0E0E6; /* \344\272\256\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    color: #F0FFFF; /* \346\226\207\345\255\227\345\217\230\344\270\272\346\265\205\351\235\222\350\211\262 */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #104E8B; /* \346\214\211\344\270\213\346\227\266\357\274\232"
                        "\345\215\225\344\270\200\346\267\261\350\223\235\350\211\262 */\n"
"    border: 1px solid #483D8B; /* \346\267\261\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    color: #E0FFFF; /* \346\265\205\351\235\222\350\211\262\346\226\207\345\255\227 */\n"
"}"));

        horizontalLayout_91->addWidget(type_button);


        verticalLayout_8->addWidget(frame_7);

        stackedWidget_2 = new QStackedWidget(frame_8);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        Analyse = new QWidget();
        Analyse->setObjectName(QString::fromUtf8("Analyse"));
        verticalLayout_71 = new QVBoxLayout(Analyse);
        verticalLayout_71->setSpacing(17);
        verticalLayout_71->setObjectName(QString::fromUtf8("verticalLayout_71"));
        verticalLayout_71->setContentsMargins(0, 8, 0, 9);
        label_2 = new QLabel(Analyse);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_71->addWidget(label_2);

        textEdit = new QPlainTextEdit(Analyse);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(0, 240));
        textEdit->setFocusPolicy(Qt::NoFocus);
        textEdit->setStyleSheet(QString::fromUtf8("QPlainTextEdit{\n"
"\n"
"     background-color: rgba(150, 150, 150, 0.5);\n"
"     font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"     padding:10px;\n"
"	color: rgb(245, 244, 241);\n"
"     border:none;\n"
"border-radius:16px;\n"
"}"));
        textEdit->setLineWidth(0);
        textEdit->setCursorWidth(1);

        verticalLayout_71->addWidget(textEdit);

        label_3 = new QLabel(Analyse);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_71->addWidget(label_3);

        result = new QTextEdit(Analyse);
        result->setObjectName(QString::fromUtf8("result"));
        result->setMinimumSize(QSize(0, 240));
        result->setFocusPolicy(Qt::NoFocus);
        result->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"     background-color: rgba(150, 150, 150, 0.5);\n"
"     font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(245, 244, 241);\n"
"     padding:10px;\n"
"     border:none;\n"
"border-radius:16px;\n"
"}"));
        result->setLineWidth(0);

        verticalLayout_71->addWidget(result);

        stackedWidget_2->addWidget(Analyse);
        Type = new QWidget();
        Type->setObjectName(QString::fromUtf8("Type"));
        tags = new QWidget(Type);
        tags->setObjectName(QString::fromUtf8("tags"));
        tags->setGeometry(QRect(0, 40, 351, 281));
        tags->setStyleSheet(QString::fromUtf8(""));
        ui_keywordLike = new QPushButton(Type);
        ui_keywordLike->setObjectName(QString::fromUtf8("ui_keywordLike"));
        ui_keywordLike->setGeometry(QRect(40, 360, 121, 28));
        ui_keywordLike->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #A4B0FF, stop:1 #8fd1be); /* \346\270\220\345\217\230\357\274\232\346\267\261\350\223\235\347\264\253\345\210\260\346\233\264\346\267\261\350\223\235 */\n"
"    color: #FFFFFF; /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    border: 1px solid #5A6799; /* \346\267\261\350\223\235\347\264\253\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 6px;\n"
"    padding: 2px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #4B5A8C, stop:1 #2F407F); /* \346\202\254\345\201\234\346\227\266\357\274\232\347\250\215\344\272\256\347\232\204\350\223\235\347\264\253\346\270\220\345\217\230 */\n"
"    border: 1px solid #7A89B5; /* \344\272\256\350\223\235\347\264\253\350\276\271\346\241\206 */\n"
"    color: #F0F0FF; /* \345\270\246\347\264\253\350\260\203\347\232\204\346\265\205\350\211\262\346\226\207\345\255\227 */\n"
"}\n"
"QPushButton:pressed {\n"
"    backg"
                        "round-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #0F1A3F, stop:1 #1A2F5F); /* \346\214\211\344\270\213\346\227\266\357\274\232\346\236\201\346\267\261\350\223\235\347\264\253\346\270\220\345\217\230 */\n"
"    border: 1px solid #3C4A7F; /* \346\267\261\347\264\253\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    color: #E6E6FF; /* \346\265\205\347\264\253\347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"}"));
        ui_keywordSearch = new QPushButton(Type);
        ui_keywordSearch->setObjectName(QString::fromUtf8("ui_keywordSearch"));
        ui_keywordSearch->setGeometry(QRect(40, 410, 261, 41));
        ui_keywordSearch->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #A4B0FF, stop:1 #8fd1be); /* \346\270\220\345\217\230\357\274\232\346\267\261\350\223\235\347\264\253\345\210\260\346\233\264\346\267\261\350\223\235 */\n"
"    color: #FFFFFF; /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    border: 1px solid #5A6799; /* \346\267\261\350\223\235\347\264\253\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 6px;\n"
"    padding: 2px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #4B5A8C, stop:1 #2F407F); /* \346\202\254\345\201\234\346\227\266\357\274\232\347\250\215\344\272\256\347\232\204\350\223\235\347\264\253\346\270\220\345\217\230 */\n"
"    border: 1px solid #7A89B5; /* \344\272\256\350\223\235\347\264\253\350\276\271\346\241\206 */\n"
"    color: #F0F0FF; /* \345\270\246\347\264\253\350\260\203\347\232\204\346\265\205\350\211\262\346\226\207\345\255\227 */\n"
"}\n"
"QPushButton:pressed {\n"
"    backg"
                        "round-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #0F1A3F, stop:1 #1A2F5F); /* \346\214\211\344\270\213\346\227\266\357\274\232\346\236\201\346\267\261\350\223\235\347\264\253\346\270\220\345\217\230 */\n"
"    border: 1px solid #3C4A7F; /* \346\267\261\347\264\253\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    color: #E6E6FF; /* \346\265\205\347\264\253\347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"}"));
        ui_keywordLike_2 = new QPushButton(Type);
        ui_keywordLike_2->setObjectName(QString::fromUtf8("ui_keywordLike_2"));
        ui_keywordLike_2->setGeometry(QRect(182, 360, 121, 28));
        ui_keywordLike_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #94B0F0, stop:1 #8fd1be); /* \346\270\220\345\217\230\357\274\232\346\267\261\350\223\235\347\264\253\345\210\260\346\233\264\346\267\261\350\223\235 */\n"
"    color: #FFFFFF; /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    border: 1px solid #5A6799; /* \346\267\261\350\223\235\347\264\253\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 6px;\n"
"    padding: 2px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #4B5A8C, stop:1 #2F407F); /* \346\202\254\345\201\234\346\227\266\357\274\232\347\250\215\344\272\256\347\232\204\350\223\235\347\264\253\346\270\220\345\217\230 */\n"
"    border: 1px solid #7A89B5; /* \344\272\256\350\223\235\347\264\253\350\276\271\346\241\206 */\n"
"    color: #F0F0FF; /* \345\270\246\347\264\253\350\260\203\347\232\204\346\265\205\350\211\262\346\226\207\345\255\227 */\n"
"}\n"
"QPushButton:pressed {\n"
"    backg"
                        "round-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #0F1A3F, stop:1 #1A2F5F); /* \346\214\211\344\270\213\346\227\266\357\274\232\346\236\201\346\267\261\350\223\235\347\264\253\346\270\220\345\217\230 */\n"
"    border: 1px solid #3C4A7F; /* \346\267\261\347\264\253\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    color: #E6E6FF; /* \346\265\205\347\264\253\347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"}"));
        ui_keywordSearch_2 = new QPushButton(Type);
        ui_keywordSearch_2->setObjectName(QString::fromUtf8("ui_keywordSearch_2"));
        ui_keywordSearch_2->setGeometry(QRect(270, 530, 81, 51));
        ui_keywordSearch_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #E4B0FF, stop:1 #8fd1be); /* \346\270\220\345\217\230\357\274\232\346\267\261\350\223\235\347\264\253\345\210\260\346\233\264\346\267\261\350\223\235 */\n"
"    color: #FFFFAF; /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    border: 1px solid #5A6799; /* \346\267\261\350\223\235\347\264\253\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 6px;\n"
"    padding: 2px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #4B5A8C, stop:1 #2F407F); /* \346\202\254\345\201\234\346\227\266\357\274\232\347\250\215\344\272\256\347\232\204\350\223\235\347\264\253\346\270\220\345\217\230 */\n"
"    border: 1px solid #7A89B5; /* \344\272\256\350\223\235\347\264\253\350\276\271\346\241\206 */\n"
"    color: #F0F0FF; /* \345\270\246\347\264\253\350\260\203\347\232\204\346\265\205\350\211\262\346\226\207\345\255\227 */\n"
"}\n"
"QPushButton:pressed {\n"
"    backg"
                        "round-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #0F1A3F, stop:1 #1A2F5F); /* \346\214\211\344\270\213\346\227\266\357\274\232\346\236\201\346\267\261\350\223\235\347\264\253\346\270\220\345\217\230 */\n"
"    border: 1px solid #3C4A7F; /* \346\267\261\347\264\253\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    color: #E6E6FF; /* \346\265\205\347\264\253\347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"}"));
        stackedWidget_2->addWidget(Type);

        verticalLayout_8->addWidget(stackedWidget_2);


        verticalLayout_6->addWidget(frame_8);

        stackedWidget->addWidget(AI);

        verticalLayout_2->addWidget(stackedWidget);


        horizontalLayout_3->addWidget(listView);


        verticalLayout_3->addWidget(frame_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);
        stackedWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Video Player", nullptr));
        titleIcon->setText(QString());
        selectedButton->setText(QCoreApplication::translate("MainWindow", "Lumos Player", nullptr));
        dayAndNight->setText(QString());
        min->setText(QString());
        max->setText(QString());
        close->setText(QString());
        openBtn->setText(QString());
        listButton->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        backgroundlabel->setText(QString());
        playlabel->setText(QString());
        BeginTime->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\346\227\266\351\225\277", nullptr));
        EndTime->setText(QCoreApplication::translate("MainWindow", "\346\200\273\346\227\266\351\225\277", nullptr));
        voiceIcon->setText(QString());
        voice->setText(QCoreApplication::translate("MainWindow", "100%", nullptr));
        stopIcon->setText(QString());
        lastIcon->setText(QString());
        playIcon->setText(QString());
        nextIcon->setText(QString());
        label_4->setText(QString());
        setting->setText(QString());
        allButton->setText(QString());
        playListBtn->setText(QString());
        personalityButton->setText(QString());
        aiButton->setText(QString());
        historyButton->setText(QString());
        filterButton->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\203\250", nullptr));
        scheme->setText(QCoreApplication::translate("MainWindow", "\351\241\272\345\272\217\346\222\255\346\224\276", nullptr));
        deleteAll->setText(QString());
        refreshButton->setText(QString());
        AiLogo->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250Lumos\346\203\205\346\204\237\345\210\206\346\236\220\345\212\251\346\211\213\357\274\201", nullptr));
        type->setText(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\346\240\207\347\255\276", nullptr));
        titles->setText(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\346\240\207\351\242\230", nullptr));
        avatar->setText(QString());
        analyse_button->setText(QCoreApplication::translate("MainWindow", "\346\203\205\346\204\237\345\210\206\346\236\220", nullptr));
        type_button->setText(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\347\224\273\345\203\217", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\257\246\347\273\206\345\210\206\346\236\220", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\203\205\346\204\237\345\210\206\345\270\203", nullptr));
        ui_keywordLike->setText(QCoreApplication::translate("MainWindow", "\342\230\205\346\224\266\350\227\217", nullptr));
        ui_keywordSearch->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        ui_keywordLike_2->setText(QCoreApplication::translate("MainWindow", "\345\261\217\350\224\275", nullptr));
        ui_keywordSearch_2->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\347\224\273\345\203\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
