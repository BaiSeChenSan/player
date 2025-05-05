/********************************************************************************
** Form generated from reading UI file 'systemdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMDIALOG_H
#define UI_SYSTEMDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemDialog
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_4;
    QLabel *label;
    QListWidget *listWidget;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *exitAreaFrame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *exitButton;
    QStackedWidget *stackedWidget;
    QWidget *systempage;
    QVBoxLayout *verticalLayout_5;
    QLabel *minlabel;
    QCheckBox *iconcheck;
    QCheckBox *stopcheck;
    QSpacerItem *verticalSpacer_2;
    QLabel *runlabel;
    QCheckBox *checkBox_3;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QSpacerItem *verticalSpacer;
    QWidget *playpage;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_6;
    QGridLayout *gridLayout;
    QLabel *playLabel;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_3;
    QSpacerItem *verticalSpacer_4;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_3;
    QCheckBox *checkBox_7;
    QFrame *frame_7;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QLabel *label_8;
    QWidget *picturepage;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QRadioButton *toCopyButton;
    QRadioButton *toFileButton;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton;
    QComboBox *photoTypecomboBox;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QSpacerItem *verticalSpacer_8;
    QCheckBox *sameViewsizeCheck;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_12;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *num4radioButton;
    QRadioButton *num9radioButton;
    QRadioButton *num16radioButton;
    QSpacerItem *verticalSpacer_6;
    QWidget *subtitlepage;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QCheckBox *sameNameSubtitle;
    QCheckBox *otherSubtitle;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *openFileButton;
    QLabel *label_15;
    QFrame *frame_9;
    QGridLayout *gridLayout_5;
    QPushButton *italicButton;
    QSpacerItem *verticalSpacer_10;
    QLabel *label_16;
    QPushButton *boldButton;
    QLabel *label_17;
    QPushButton *underLineButton;
    QLabel *label_19;
    QComboBox *fontSizeCombox;
    QLabel *label_18;
    QComboBox *colorComboBox;
    QComboBox *fontComboBox;
    QSlider *transparencySlider;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_9;
    QWidget *voicepage;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLabel *label_20;
    QComboBox *voiceOutputBox;
    QSpacerItem *verticalSpacer_11;
    QWidget *mousepage;
    QGridLayout *gridLayout_6;
    QLineEdit *startEdit;
    QLabel *label_26;
    QSpacerItem *verticalSpacer_16;
    QLabel *label_24;
    QSpacerItem *verticalSpacer_15;
    QLineEdit *exitEdit;
    QSpacerItem *verticalSpacer_13;
    QSpacerItem *verticalSpacer_14;
    QSpacerItem *verticalSpacer_18;
    QSpacerItem *verticalSpacer_12;
    QLineEdit *backingEdit;
    QLineEdit *voiceDownEdit;
    QLineEdit *speedingEdit;
    QLabel *label_21;
    QLabel *label_7;
    QLineEdit *voiceUpEdit;
    QSpacerItem *verticalSpacer_17;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_25;
    QSpacerItem *verticalSpacer_19;
    QFrame *buttonAreaFrame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *SystemDialog)
    {
        if (SystemDialog->objectName().isEmpty())
            SystemDialog->setObjectName(QString::fromUtf8("SystemDialog"));
        SystemDialog->resize(850, 603);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SystemDialog->sizePolicy().hasHeightForWidth());
        SystemDialog->setSizePolicy(sizePolicy);
        SystemDialog->setMaximumSize(QSize(850, 16777215));
        SystemDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout_2 = new QGridLayout(SystemDialog);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(SystemDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMaximumSize(QSize(250, 16777215));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 241, 241);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_11 = new QFrame(frame);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setStyleSheet(QString::fromUtf8("border:none;"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushButton_4 = new QPushButton(frame_11);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(true);
        pushButton_4->setMinimumSize(QSize(40, 40));
        pushButton_4->setMaximumSize(QSize(50, 50));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none;\n"
"	background:transparent;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icons/logo.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(40, 40));

        horizontalLayout_7->addWidget(pushButton_4);

        label = new QLabel(frame_11);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Microsoft YaHei UI\";\n"
""));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label);


        verticalLayout->addWidget(frame_11);

        listWidget = new QListWidget(frame);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(14);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem->setFont(font);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem1->setFont(font);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem2->setFont(font);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem3->setFont(font);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget);
        __qlistwidgetitem4->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem4->setFont(font);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listWidget);
        __qlistwidgetitem5->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem5->setFont(font);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QFont font1;
        font1.setPointSize(14);
        listWidget->setFont(font1);
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"	border:none;\n"
"	text-align: center;\n"
"}\n"
"QListWidget::item {\n"
"	text-align: center;\n"
"     height: 60px;\n"
" }\n"
" QListWidget::item:selected {\n"
"     background-color: #3586ff;\n"
"       \n"
"}"));

        verticalLayout->addWidget(listWidget);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        frame_2 = new QFrame(SystemDialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        exitAreaFrame = new QFrame(frame_2);
        exitAreaFrame->setObjectName(QString::fromUtf8("exitAreaFrame"));
        exitAreaFrame->setLayoutDirection(Qt::LeftToRight);
        exitAreaFrame->setFrameShape(QFrame::StyledPanel);
        exitAreaFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(exitAreaFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        exitButton = new QPushButton(exitAreaFrame);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setMinimumSize(QSize(38, 38));
        exitButton->setMaximumSize(QSize(30, 16777215));
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none;\n"
"    background: transparent;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/close.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/close.svg"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/close.svg"), QSize(), QIcon::Disabled, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/close.svg"), QSize(), QIcon::Disabled, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/close.svg"), QSize(), QIcon::Active, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/close.svg"), QSize(), QIcon::Active, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/close.svg"), QSize(), QIcon::Selected, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/close.svg"), QSize(), QIcon::Selected, QIcon::On);
        exitButton->setIcon(icon1);
        exitButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(exitButton);


        verticalLayout_2->addWidget(exitAreaFrame);

        stackedWidget = new QStackedWidget(frame_2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        systempage = new QWidget();
        systempage->setObjectName(QString::fromUtf8("systempage"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(systempage->sizePolicy().hasHeightForWidth());
        systempage->setSizePolicy(sizePolicy2);
        systempage->setMaximumSize(QSize(16777215, 1666677));
        systempage->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 250, 250);"));
        verticalLayout_5 = new QVBoxLayout(systempage);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(12, -1, -1, -1);
        minlabel = new QLabel(systempage);
        minlabel->setObjectName(QString::fromUtf8("minlabel"));
        minlabel->setMinimumSize(QSize(0, 41));
        minlabel->setMaximumSize(QSize(16777215, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font2.setPointSize(12);
        minlabel->setFont(font2);

        verticalLayout_5->addWidget(minlabel);

        iconcheck = new QCheckBox(systempage);
        iconcheck->setObjectName(QString::fromUtf8("iconcheck"));
        iconcheck->setMinimumSize(QSize(0, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(3);
        iconcheck->setFont(font3);
        iconcheck->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	padding: 1px;\n"
"        }\n"
"QCheckBox::indicator{\n"
"	  width:14px;\n"
"	  height:14px;\n"
"      border: 2px solid gray;\n"
"      border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/new/prefix1/icons/check.svg);\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        verticalLayout_5->addWidget(iconcheck);

        stopcheck = new QCheckBox(systempage);
        stopcheck->setObjectName(QString::fromUtf8("stopcheck"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(stopcheck->sizePolicy().hasHeightForWidth());
        stopcheck->setSizePolicy(sizePolicy3);
        stopcheck->setMinimumSize(QSize(0, 30));
        stopcheck->setFont(font3);
        stopcheck->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	padding: 1px;\n"
"        }\n"
"QCheckBox::indicator{\n"
"	  width:14px;\n"
"	  height:14px;\n"
"      border: 2px solid gray;\n"
"      border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/new/prefix1/icons/check.svg);\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        verticalLayout_5->addWidget(stopcheck);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_2);

        runlabel = new QLabel(systempage);
        runlabel->setObjectName(QString::fromUtf8("runlabel"));
        runlabel->setMinimumSize(QSize(0, 40));
        runlabel->setMaximumSize(QSize(16777215, 50));
        runlabel->setFont(font2);

        verticalLayout_5->addWidget(runlabel);

        checkBox_3 = new QCheckBox(systempage);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setMinimumSize(QSize(0, 30));
        checkBox_3->setFont(font3);
        checkBox_3->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	padding: 1px;\n"
"        }\n"
"QCheckBox::indicator{\n"
"	  width:14px;\n"
"	  height:14px;\n"
"      border: 2px solid gray;\n"
"      border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/new/prefix1/icons/check.svg);\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        verticalLayout_5->addWidget(checkBox_3);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_3);

        label_2 = new QLabel(systempage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 40));
        label_2->setFont(font2);

        verticalLayout_5->addWidget(label_2);

        frame_5 = new QFrame(systempage);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	border:none;\n"
"	}"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_5);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(frame_5);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setMinimumSize(QSize(0, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(3);
        radioButton->setFont(font4);
        radioButton->setStyleSheet(QString::fromUtf8("font: 25 12pt \"Microsoft YaHei UI\";"));

        horizontalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(frame_5);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setMinimumSize(QSize(0, 30));
        radioButton_2->setFont(font4);
        radioButton_2->setStyleSheet(QString::fromUtf8("font: 25 12pt \"Microsoft YaHei UI\";"));

        horizontalLayout_3->addWidget(radioButton_2);


        verticalLayout_5->addWidget(frame_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        stackedWidget->addWidget(systempage);
        playpage = new QWidget();
        playpage->setObjectName(QString::fromUtf8("playpage"));
        playpage->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 250, 250);"));
        verticalLayout_3 = new QVBoxLayout(playpage);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(7, 4, 6, 6);
        scrollArea = new QScrollArea(playpage);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy2.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy2);
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea{\n"
"	border:none;\n"
"}\n"
"QScrollBar:vertical {\n"
"        border: none;\n"
"        background: #f0f0f0;\n"
"        width: 8px;\n"
"        margin: 0px;\n"
"        border-radius: 4px;\n"
"    }\n"
"    QScrollBar::handle:vertical {\n"
"        background: #d5d5d5;\n"
"        border-radius: 4px;\n"
"    }\n"
"    QScrollBar::handle:vertical:hover {\n"
"        background: #c7c7c7;\n"
"    }\n"
"    QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"        border: none;\n"
"        background: none;\n"
"        width: 0px;\n"
"        height: 0px;\n"
"}"));
        scrollArea->setLineWidth(1);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 312, 600));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 600));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(6, 6, 6, 6);
        frame_6 = new QFrame(scrollAreaWidgetContents);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setMinimumSize(QSize(0, 129));
        frame_6->setMaximumSize(QSize(16777215, 130));
        frame_6->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	border:none;\n"
"\n"
"	}"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_6);
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        playLabel = new QLabel(frame_6);
        playLabel->setObjectName(QString::fromUtf8("playLabel"));
        playLabel->setMinimumSize(QSize(0, 41));
        playLabel->setMaximumSize(QSize(16777215, 41));
        playLabel->setFont(font2);

        gridLayout->addWidget(playLabel, 0, 0, 1, 1);

        radioButton_6 = new QRadioButton(frame_6);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setMinimumSize(QSize(0, 40));
        radioButton_6->setFont(font3);
        radioButton_6->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(radioButton_6, 2, 0, 1, 1);

        radioButton_4 = new QRadioButton(frame_6);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setMinimumSize(QSize(0, 50));
        radioButton_4->setFont(font3);
        radioButton_4->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(radioButton_4, 1, 1, 1, 1);

        radioButton_5 = new QRadioButton(frame_6);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setMinimumSize(QSize(0, 40));
        radioButton_5->setFont(font3);
        radioButton_5->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(radioButton_5, 2, 1, 1, 1);

        radioButton_3 = new QRadioButton(frame_6);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setMinimumSize(QSize(0, 50));
        radioButton_3->setFont(font3);
        radioButton_3->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(radioButton_3, 1, 0, 1, 1);


        verticalLayout_4->addWidget(frame_6);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_4);

        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setMinimumSize(QSize(0, 30));
        checkBox->setFont(font3);
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	padding: 1px;\n"
"        }\n"
"QCheckBox::indicator{\n"
"	  width:14px;\n"
"	  height:14px;\n"
"      border: 2px solid gray;\n"
"      border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/new/prefix1/icons/check.svg);\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        verticalLayout_4->addWidget(checkBox);

        checkBox_2 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setMinimumSize(QSize(0, 30));
        checkBox_2->setFont(font3);
        checkBox_2->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	padding: 1px;\n"
"        }\n"
"QCheckBox::indicator{\n"
"	  width:14px;\n"
"	  height:14px;\n"
"      border: 2px solid gray;\n"
"      border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/new/prefix1/icons/check.svg);\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        verticalLayout_4->addWidget(checkBox_2);

        checkBox_4 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setMinimumSize(QSize(0, 30));
        checkBox_4->setFont(font3);
        checkBox_4->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	padding: 1px;\n"
"        }\n"
"QCheckBox::indicator{\n"
"	  width:14px;\n"
"	  height:14px;\n"
"      border: 2px solid gray;\n"
"      border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/new/prefix1/icons/check.svg);\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        verticalLayout_4->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setMinimumSize(QSize(0, 30));
        checkBox_5->setFont(font3);
        checkBox_5->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	padding: 1px;\n"
"        }\n"
"QCheckBox::indicator{\n"
"	  width:14px;\n"
"	  height:14px;\n"
"      border: 2px solid gray;\n"
"      border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/new/prefix1/icons/check.svg);\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        verticalLayout_4->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setMinimumSize(QSize(0, 30));
        checkBox_6->setFont(font3);
        checkBox_6->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	padding: 1px;\n"
"        }\n"
"QCheckBox::indicator{\n"
"	  width:14px;\n"
"	  height:14px;\n"
"      border: 2px solid gray;\n"
"      border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/new/prefix1/icons/check.svg);\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        verticalLayout_4->addWidget(checkBox_6);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_5);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 41));
        label_3->setMaximumSize(QSize(16777215, 41));
        label_3->setFont(font2);

        verticalLayout_4->addWidget(label_3);

        checkBox_7 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setMinimumSize(QSize(0, 30));
        checkBox_7->setFont(font3);
        checkBox_7->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	padding: 1px;\n"
"        }\n"
"QCheckBox::indicator{\n"
"	  width:14px;\n"
"	  height:14px;\n"
"      border: 2px solid gray;\n"
"      border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/new/prefix1/icons/check.svg);\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        verticalLayout_4->addWidget(checkBox_7);

        frame_7 = new QFrame(scrollAreaWidgetContents);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setEnabled(false);
        frame_7->setMinimumSize(QSize(0, 80));
        frame_7->setMaximumSize(QSize(16777215, 100));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_7);
        gridLayout_3->setSpacing(4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        checkBox_10 = new QCheckBox(frame_7);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setMinimumSize(QSize(0, 30));
        checkBox_10->setFont(font3);
        checkBox_10->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	padding: 1px;\n"
"        }\n"
"QCheckBox::indicator{\n"
"	  width:14px;\n"
"	  height:14px;\n"
"      border: 2px solid gray;\n"
"      border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/new/prefix1/icons/check.svg);\n"
"    border-color: #3586FF;\n"
"\n"
"}"));
        checkBox_10->setCheckable(true);

        gridLayout_3->addWidget(checkBox_10, 2, 3, 1, 1);

        checkBox_8 = new QCheckBox(frame_7);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setMinimumSize(QSize(0, 30));
        checkBox_8->setFont(font3);
        checkBox_8->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	padding: 1px;\n"
"        }\n"
"QCheckBox::indicator{\n"
"	  width:14px;\n"
"	  height:14px;\n"
"      border: 2px solid gray;\n"
"      border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/new/prefix1/icons/check.svg);\n"
"    border-color: #3586FF;\n"
"\n"
"}"));
        checkBox_8->setCheckable(true);

        gridLayout_3->addWidget(checkBox_8, 2, 0, 1, 1);

        checkBox_9 = new QCheckBox(frame_7);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setMinimumSize(QSize(0, 30));
        checkBox_9->setFont(font3);
        checkBox_9->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	padding: 1px;\n"
"        }\n"
"QCheckBox::indicator{\n"
"	  width:14px;\n"
"	  height:14px;\n"
"      border: 2px solid gray;\n"
"      border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/new/prefix1/icons/check.svg);\n"
"    border-color: #3586FF;\n"
"\n"
"}"));
        checkBox_9->setCheckable(true);

        gridLayout_3->addWidget(checkBox_9, 2, 2, 1, 1);

        label_8 = new QLabel(frame_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 41));
        label_8->setMaximumSize(QSize(16777215, 41));
        label_8->setFont(font2);

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);


        verticalLayout_4->addWidget(frame_7);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        stackedWidget->addWidget(playpage);
        picturepage = new QWidget();
        picturepage->setObjectName(QString::fromUtf8("picturepage"));
        picturepage->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 250, 250);"));
        verticalLayout_6 = new QVBoxLayout(picturepage);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(12, -1, -1, -1);
        label_4 = new QLabel(picturepage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 41));
        label_4->setMaximumSize(QSize(16777215, 41));
        label_4->setFont(font2);

        verticalLayout_6->addWidget(label_4);

        toCopyButton = new QRadioButton(picturepage);
        toCopyButton->setObjectName(QString::fromUtf8("toCopyButton"));
        toCopyButton->setFont(font3);
        toCopyButton->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        verticalLayout_6->addWidget(toCopyButton);

        toFileButton = new QRadioButton(picturepage);
        toFileButton->setObjectName(QString::fromUtf8("toFileButton"));
        toFileButton->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        verticalLayout_6->addWidget(toFileButton);

        frame_3 = new QFrame(picturepage);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	border:none;\n"
"	}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_3);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(100, 30));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 70px;\n"
"    height: 22px;\n"
"    background-color: rgb(239, 239, 239);\n"
"    border-radius: 5px;\n"
"    border: 2px ;  /* \347\241\256\344\277\235 border \346\230\257\344\270\200\344\270\252\346\234\211\346\225\210\347\232\204\350\276\271\346\241\206\346\240\267\345\274\217 */\n"
"    padding: 2px 8px;  /* \345\234\250\346\214\211\351\222\256\345\206\205\345\212\240\345\205\245\344\270\200\347\202\271\345\206\205\350\276\271\350\267\235 */\n"
"    text-align: center; \n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(223, 223, 223);\n"
"}"));

        gridLayout_4->addWidget(pushButton, 0, 2, 1, 1);

        photoTypecomboBox = new QComboBox(frame_3);
        photoTypecomboBox->addItem(QString());
        photoTypecomboBox->addItem(QString());
        photoTypecomboBox->setObjectName(QString::fromUtf8("photoTypecomboBox"));
        photoTypecomboBox->setMaximumSize(QSize(100, 30));
        photoTypecomboBox->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"        border: 1px solid #5f5f5f;\n"
"        border-radius: 3px;\n"
"        padding: 2px;\n"
"        background-color: white;\n"
"	   font: 10pt \"Microsoft YaHei UI\";\n"
"    }\n"
"\n"
"    QComboBox:hover {\n"
"        border: 1px solid #0078d7; /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"        background-color: #e5f0fe; /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    }\n"
"\n"
"    QComboBox::editable {\n"
"        background-color: #f0f0f0;\n"
"    }"));

        gridLayout_4->addWidget(photoTypecomboBox, 2, 1, 1, 1);

        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(100, 0));
        label_9->setMaximumSize(QSize(100, 16777215));
        label_9->setFont(font3);
        label_9->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_9, 0, 0, 1, 1);

        label_10 = new QLabel(frame_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 26));
        label_10->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_10, 2, 0, 1, 1);

        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(280, 0));
        label_11->setMaximumSize(QSize(16777215, 30));
        label_11->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid black;\n"
"	border-radius:3px;\n"
"	border-color: rgb(173, 173, 173);\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"}"));

        gridLayout_4->addWidget(label_11, 0, 1, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_8, 1, 1, 1, 1);


        verticalLayout_6->addWidget(frame_3);

        sameViewsizeCheck = new QCheckBox(picturepage);
        sameViewsizeCheck->setObjectName(QString::fromUtf8("sameViewsizeCheck"));
        sameViewsizeCheck->setMinimumSize(QSize(0, 30));
        sameViewsizeCheck->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	padding: 1px;\n"
"        }\n"
"QCheckBox::indicator{\n"
"	  width:14px;\n"
"	  height:14px;\n"
"      border: 2px solid gray;\n"
"      border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/new/prefix1/icons/check.svg);\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        verticalLayout_6->addWidget(sameViewsizeCheck);

        verticalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_7);

        label_12 = new QLabel(picturepage);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(0, 41));
        label_12->setMaximumSize(QSize(16777215, 41));
        label_12->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));

        verticalLayout_6->addWidget(label_12);

        frame_4 = new QFrame(picturepage);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	border:none;\n"
"}"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        num4radioButton = new QRadioButton(frame_4);
        num4radioButton->setObjectName(QString::fromUtf8("num4radioButton"));
        num4radioButton->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        horizontalLayout_4->addWidget(num4radioButton);

        num9radioButton = new QRadioButton(frame_4);
        num9radioButton->setObjectName(QString::fromUtf8("num9radioButton"));
        num9radioButton->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        horizontalLayout_4->addWidget(num9radioButton);

        num16radioButton = new QRadioButton(frame_4);
        num16radioButton->setObjectName(QString::fromUtf8("num16radioButton"));
        num16radioButton->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        horizontalLayout_4->addWidget(num16radioButton);


        verticalLayout_6->addWidget(frame_4);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_6);

        stackedWidget->addWidget(picturepage);
        subtitlepage = new QWidget();
        subtitlepage->setObjectName(QString::fromUtf8("subtitlepage"));
        sizePolicy2.setHeightForWidth(subtitlepage->sizePolicy().hasHeightForWidth());
        subtitlepage->setSizePolicy(sizePolicy2);
        subtitlepage->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 250, 250);"));
        verticalLayout_7 = new QVBoxLayout(subtitlepage);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(12, -1, -1, -1);
        label_5 = new QLabel(subtitlepage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 41));
        label_5->setMaximumSize(QSize(16777215, 41));
        label_5->setFont(font2);

        verticalLayout_7->addWidget(label_5);

        sameNameSubtitle = new QCheckBox(subtitlepage);
        sameNameSubtitle->setObjectName(QString::fromUtf8("sameNameSubtitle"));
        sameNameSubtitle->setMinimumSize(QSize(0, 30));
        sameNameSubtitle->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	padding: 1px;\n"
"        }\n"
"QCheckBox::indicator{\n"
"	  width:14px;\n"
"	  height:14px;\n"
"      border: 2px solid gray;\n"
"      border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/new/prefix1/icons/check.svg);\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        verticalLayout_7->addWidget(sameNameSubtitle);

        otherSubtitle = new QCheckBox(subtitlepage);
        otherSubtitle->setObjectName(QString::fromUtf8("otherSubtitle"));
        otherSubtitle->setMinimumSize(QSize(0, 30));
        otherSubtitle->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	padding: 1px;\n"
"        }\n"
"QCheckBox::indicator{\n"
"	  width:14px;\n"
"	  height:14px;\n"
"      border: 2px solid gray;\n"
"      border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/new/prefix1/icons/check.svg);\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        verticalLayout_7->addWidget(otherSubtitle);

        frame_8 = new QFrame(subtitlepage);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	border:none;\n"
"}"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_8);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, -1, -1, -1);
        label_13 = new QLabel(frame_8);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(0, 30));
        label_13->setMaximumSize(QSize(150, 100));
        label_13->setFont(font3);
        label_13->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_13);

        label_14 = new QLabel(frame_8);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(300, 16777215));
        label_14->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid black;\n"
"	border-radius:3px;\n"
"	border-color: rgb(173, 173, 173);\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"}"));

        horizontalLayout_5->addWidget(label_14);

        openFileButton = new QPushButton(frame_8);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));
        openFileButton->setMinimumSize(QSize(0, 30));
        openFileButton->setMaximumSize(QSize(100, 16777215));
        openFileButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 70px;\n"
"    height: 22px;\n"
"    background-color: rgb(239, 239, 239);\n"
"    border-radius: 5px;\n"
"    border: 2px ;  /* \347\241\256\344\277\235 border \346\230\257\344\270\200\344\270\252\346\234\211\346\225\210\347\232\204\350\276\271\346\241\206\346\240\267\345\274\217 */\n"
"    padding: 2px 8px;  /* \345\234\250\346\214\211\351\222\256\345\206\205\345\212\240\345\205\245\344\270\200\347\202\271\345\206\205\350\276\271\350\267\235 */\n"
"    text-align: center; \n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(223, 223, 223);\n"
"}"));

        horizontalLayout_5->addWidget(openFileButton);


        verticalLayout_7->addWidget(frame_8);

        label_15 = new QLabel(subtitlepage);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(0, 41));
        label_15->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));

        verticalLayout_7->addWidget(label_15);

        frame_9 = new QFrame(subtitlepage);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setEnabled(false);
        frame_9->setMinimumSize(QSize(80, 0));
        frame_9->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	border:none;\n"
"	}"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_9);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, -1, -1, -1);
        italicButton = new QPushButton(frame_9);
        italicButton->setObjectName(QString::fromUtf8("italicButton"));
        italicButton->setMinimumSize(QSize(30, 26));
        italicButton->setMaximumSize(QSize(30, 30));
        italicButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid gray;\n"
"	border-radius:3px;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(223, 223, 223);\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icons/italic.svg"), QSize(), QIcon::Normal, QIcon::Off);
        italicButton->setIcon(icon2);
        italicButton->setIconSize(QSize(18, 18));

        gridLayout_5->addWidget(italicButton, 0, 6, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_5->addItem(verticalSpacer_10, 1, 4, 1, 1);

        label_16 = new QLabel(frame_9);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(0, 30));
        label_16->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        gridLayout_5->addWidget(label_16, 0, 0, 1, 1);

        boldButton = new QPushButton(frame_9);
        boldButton->setObjectName(QString::fromUtf8("boldButton"));
        boldButton->setMinimumSize(QSize(30, 30));
        boldButton->setMaximumSize(QSize(30, 30));
        boldButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid gray;\n"
"	border-radius:3px;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(223, 223, 223);\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/icons/bold.svg"), QSize(), QIcon::Normal, QIcon::Off);
        boldButton->setIcon(icon3);
        boldButton->setIconSize(QSize(18, 18));

        gridLayout_5->addWidget(boldButton, 0, 5, 1, 1);

        label_17 = new QLabel(frame_9);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(0, 30));
        label_17->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        gridLayout_5->addWidget(label_17, 2, 0, 1, 1);

        underLineButton = new QPushButton(frame_9);
        underLineButton->setObjectName(QString::fromUtf8("underLineButton"));
        underLineButton->setMinimumSize(QSize(30, 30));
        underLineButton->setMaximumSize(QSize(30, 30));
        underLineButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid gray;\n"
"	border-radius:3px;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(223, 223, 223);\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/icons/underline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        underLineButton->setIcon(icon4);
        underLineButton->setIconSize(QSize(18, 18));

        gridLayout_5->addWidget(underLineButton, 0, 7, 1, 1);

        label_19 = new QLabel(frame_9);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        gridLayout_5->addWidget(label_19, 2, 3, 1, 1);

        fontSizeCombox = new QComboBox(frame_9);
        fontSizeCombox->setObjectName(QString::fromUtf8("fontSizeCombox"));
        fontSizeCombox->setMinimumSize(QSize(80, 26));
        fontSizeCombox->setMaximumSize(QSize(60, 16777215));
        fontSizeCombox->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"        border: 1px solid #5f5f5f;\n"
"        border-radius: 3px;\n"
"        padding: 2px;\n"
"        background-color: white;\n"
"	   font: 10pt \"Microsoft YaHei UI\";\n"
"    }\n"
"\n"
"    QComboBox:hover {\n"
"        border: 1px solid #0078d7; /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"        background-color: #e5f0fe; /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    }\n"
"\n"
"    QComboBox::editable {\n"
"        background-color: #f0f0f0;\n"
"    }"));

        gridLayout_5->addWidget(fontSizeCombox, 0, 4, 1, 1);

        label_18 = new QLabel(frame_9);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy2.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy2);
        label_18->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        gridLayout_5->addWidget(label_18, 0, 3, 1, 1);

        colorComboBox = new QComboBox(frame_9);
        colorComboBox->setObjectName(QString::fromUtf8("colorComboBox"));
        colorComboBox->setMinimumSize(QSize(200, 30));
        colorComboBox->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"        border: 1px solid #5f5f5f;\n"
"        border-radius: 3px;\n"
"        padding: 2px;\n"
"        background-color: white;\n"
"	   font: 10pt \"Microsoft YaHei UI\";\n"
"    }\n"
"\n"
"    QComboBox:hover {\n"
"        border: 1px solid #0078d7; /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"        background-color: #e5f0fe; /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    }\n"
"\n"
"    QComboBox::editable {\n"
"        background-color: #f0f0f0;\n"
"    }"));

        gridLayout_5->addWidget(colorComboBox, 2, 1, 1, 1);

        fontComboBox = new QComboBox(frame_9);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setMinimumSize(QSize(200, 30));
        fontComboBox->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"        border: 1px solid #5f5f5f;\n"
"        border-radius: 3px;\n"
"        padding: 2px;\n"
"        background-color: white;\n"
"	   font: 10pt \"Microsoft YaHei UI\";\n"
"    }\n"
"\n"
"    QComboBox:hover {\n"
"        border: 1px solid #0078d7; /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"        background-color: #e5f0fe; /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    }\n"
"\n"
"    QComboBox::editable {\n"
"        background-color: #f0f0f0;\n"
"    }"));

        gridLayout_5->addWidget(fontComboBox, 0, 1, 1, 1);

        transparencySlider = new QSlider(frame_9);
        transparencySlider->setObjectName(QString::fromUtf8("transparencySlider"));
        transparencySlider->setMinimumSize(QSize(200, 0));
        transparencySlider->setMaximumSize(QSize(300, 16777215));
        transparencySlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(transparencySlider, 2, 4, 1, 3);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 2, 2, 1, 1);


        verticalLayout_7->addWidget(frame_9);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_9);

        stackedWidget->addWidget(subtitlepage);
        voicepage = new QWidget();
        voicepage->setObjectName(QString::fromUtf8("voicepage"));
        voicepage->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 250, 250);"));
        verticalLayout_8 = new QVBoxLayout(voicepage);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(12, -1, -1, -1);
        frame_10 = new QFrame(voicepage);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	border:none;\n"
"}"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_10);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, -1, -1);
        label_6 = new QLabel(frame_10);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 41));
        label_6->setMaximumSize(QSize(150, 41));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));

        horizontalLayout_6->addWidget(label_6);

        label_20 = new QLabel(frame_10);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setStyleSheet(QString::fromUtf8("font: 25 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(53, 134, 255); "));

        horizontalLayout_6->addWidget(label_20);


        verticalLayout_8->addWidget(frame_10);

        voiceOutputBox = new QComboBox(voicepage);
        voiceOutputBox->addItem(QString());
        voiceOutputBox->addItem(QString());
        voiceOutputBox->addItem(QString());
        voiceOutputBox->addItem(QString());
        voiceOutputBox->setObjectName(QString::fromUtf8("voiceOutputBox"));
        voiceOutputBox->setMinimumSize(QSize(400, 26));
        voiceOutputBox->setMaximumSize(QSize(400, 16777215));
        voiceOutputBox->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"        border: 1px solid #5f5f5f;\n"
"        border-radius: 3px;\n"
"        padding: 2px;\n"
"        background-color: white;\n"
"	   font: 10pt \"Microsoft YaHei UI\";\n"
"    }\n"
"\n"
"    QComboBox:hover {\n"
"        border: 1px solid #0078d7; /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"        background-color: #e5f0fe; /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    }\n"
"\n"
"    QComboBox::editable {\n"
"        background-color: #f0f0f0;\n"
"    }"));

        verticalLayout_8->addWidget(voiceOutputBox);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_11);

        stackedWidget->addWidget(voicepage);
        mousepage = new QWidget();
        mousepage->setObjectName(QString::fromUtf8("mousepage"));
        mousepage->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 250, 250);"));
        gridLayout_6 = new QGridLayout(mousepage);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(12, -1, -1, -1);
        startEdit = new QLineEdit(mousepage);
        startEdit->setObjectName(QString::fromUtf8("startEdit"));
        startEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	border:1px solid gray;\n"
"	border-radius:3px;\n"
"	padding: 1px;\n"
"        }\n"
"QLineEdit:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QLineEdit:checked{\n"
"	\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        gridLayout_6->addWidget(startEdit, 6, 1, 1, 1);

        label_26 = new QLabel(mousepage);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        gridLayout_6->addWidget(label_26, 14, 0, 1, 1);

        verticalSpacer_16 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_6->addItem(verticalSpacer_16, 11, 1, 1, 1);

        label_24 = new QLabel(mousepage);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        gridLayout_6->addWidget(label_24, 10, 0, 1, 1);

        verticalSpacer_15 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(verticalSpacer_15, 9, 1, 1, 1);

        exitEdit = new QLineEdit(mousepage);
        exitEdit->setObjectName(QString::fromUtf8("exitEdit"));
        exitEdit->setEnabled(true);
        exitEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	border:1px solid gray;\n"
"	border-radius:3px;\n"
"	padding: 1px;\n"
"        }\n"
"QLineEdit:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QLineEdit:checked{\n"
"	\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        gridLayout_6->addWidget(exitEdit, 3, 1, 1, 1);

        verticalSpacer_13 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_6->addItem(verticalSpacer_13, 4, 1, 1, 1);

        verticalSpacer_14 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_6->addItem(verticalSpacer_14, 7, 1, 1, 1);

        verticalSpacer_18 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(verticalSpacer_18, 2, 0, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_12, 15, 1, 1, 1);

        backingEdit = new QLineEdit(mousepage);
        backingEdit->setObjectName(QString::fromUtf8("backingEdit"));
        backingEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	border:1px solid gray;\n"
"	border-radius:3px;\n"
"	padding: 1px;\n"
"        }\n"
"QLineEdit:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QLineEdit:checked{\n"
"	\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        gridLayout_6->addWidget(backingEdit, 10, 1, 1, 1);

        voiceDownEdit = new QLineEdit(mousepage);
        voiceDownEdit->setObjectName(QString::fromUtf8("voiceDownEdit"));
        voiceDownEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	border:1px solid gray;\n"
"	border-radius:3px;\n"
"	padding: 1px;\n"
"        }\n"
"QLineEdit:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QLineEdit:checked{\n"
"	\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        gridLayout_6->addWidget(voiceDownEdit, 14, 1, 1, 1);

        speedingEdit = new QLineEdit(mousepage);
        speedingEdit->setObjectName(QString::fromUtf8("speedingEdit"));
        speedingEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	border:1px solid gray;\n"
"	border-radius:3px;\n"
"	padding: 1px;\n"
"        }\n"
"QLineEdit:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QLineEdit:checked{\n"
"	\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        gridLayout_6->addWidget(speedingEdit, 8, 1, 1, 1);

        label_21 = new QLabel(mousepage);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        gridLayout_6->addWidget(label_21, 3, 0, 1, 1);

        label_7 = new QLabel(mousepage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));

        gridLayout_6->addWidget(label_7, 1, 0, 1, 1);

        voiceUpEdit = new QLineEdit(mousepage);
        voiceUpEdit->setObjectName(QString::fromUtf8("voiceUpEdit"));
        voiceUpEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 25 10pt \"Microsoft YaHei UI\";\n"
"	border:1px solid gray;\n"
"	border-radius:3px;\n"
"	padding: 1px;\n"
"        }\n"
"QLineEdit:hover{\n"
"       border-color:rgb(53, 134, 255);\n"
"}\n"
"QLineEdit:checked{\n"
"	\n"
"    border-color: #3586FF;\n"
"\n"
"}"));

        gridLayout_6->addWidget(voiceUpEdit, 12, 1, 1, 1);

        verticalSpacer_17 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_6->addItem(verticalSpacer_17, 13, 1, 1, 1);

        label_22 = new QLabel(mousepage);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        gridLayout_6->addWidget(label_22, 6, 0, 1, 1);

        label_23 = new QLabel(mousepage);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        gridLayout_6->addWidget(label_23, 8, 0, 1, 1);

        label_25 = new QLabel(mousepage);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setStyleSheet(QString::fromUtf8("font: 25 10pt \"Microsoft YaHei UI\";"));

        gridLayout_6->addWidget(label_25, 12, 0, 1, 1);

        verticalSpacer_19 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_6->addItem(verticalSpacer_19, 0, 0, 1, 1);

        stackedWidget->addWidget(mousepage);

        verticalLayout_2->addWidget(stackedWidget);

        buttonAreaFrame = new QFrame(frame_2);
        buttonAreaFrame->setObjectName(QString::fromUtf8("buttonAreaFrame"));
        buttonAreaFrame->setFrameShape(QFrame::StyledPanel);
        buttonAreaFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(buttonAreaFrame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(buttonAreaFrame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(30);
        sizePolicy4.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy4);
        pushButton_2->setMinimumSize(QSize(40, 40));
        pushButton_2->setMaximumSize(QSize(16777215, 166666));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 70px;\n"
"    height: 40px;\n"
"    background-color: rgb(239, 239, 239);\n"
"    border-radius: 5px;\n"
"    border: 2px ;  /* \347\241\256\344\277\235 border \346\230\257\344\270\200\344\270\252\346\234\211\346\225\210\347\232\204\350\276\271\346\241\206\346\240\267\345\274\217 */\n"
"    padding: 2px 8px;  /* \345\234\250\346\214\211\351\222\256\345\206\205\345\212\240\345\205\245\344\270\200\347\202\271\345\206\205\350\276\271\350\267\235 */\n"
"    text-align: center; \n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(223, 223, 223);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(buttonAreaFrame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);
        pushButton_3->setMinimumSize(QSize(40, 40));
        pushButton_3->setMaximumSize(QSize(16777215, 166667));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	width: 70px;\n"
"    height: 40px;\n"
"    background-color: rgb(239, 239, 239);\n"
"    border-radius: 5px;\n"
"    border: 2px ;  /* \347\241\256\344\277\235 border \346\230\257\344\270\200\344\270\252\346\234\211\346\225\210\347\232\204\350\276\271\346\241\206\346\240\267\345\274\217 */\n"
"    padding: 2px 8px;  /* \345\234\250\346\214\211\351\222\256\345\206\205\345\212\240\345\205\245\344\270\200\347\202\271\345\206\205\350\276\271\350\267\235 */\n"
"    text-align: center; \n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(223, 223, 223);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(pushButton_3);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(buttonAreaFrame);


        gridLayout_2->addWidget(frame_2, 0, 1, 1, 1);


        retranslateUi(SystemDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SystemDialog);
    } // setupUi

    void retranslateUi(QDialog *SystemDialog)
    {
        SystemDialog->setWindowTitle(QCoreApplication::translate("SystemDialog", "Dialog", nullptr));
        pushButton_4->setText(QString());
        label->setText(QCoreApplication::translate("SystemDialog", "\346\222\255\346\224\276\345\231\250\350\256\276\347\275\256", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("SystemDialog", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("SystemDialog", "\346\222\255\346\224\276\350\256\276\347\275\256", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("SystemDialog", "\345\233\276\347\211\207\350\256\276\347\275\256", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("SystemDialog", "\345\255\227\345\271\225\350\256\276\347\275\256", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("SystemDialog", "\345\243\260\351\237\263\350\256\276\347\275\256", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("SystemDialog", "\351\274\240\346\240\207\347\203\255\351\224\256", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        exitButton->setText(QString());
        minlabel->setText(QCoreApplication::translate("SystemDialog", "\347\252\227\345\217\243\346\234\200\345\260\217\345\214\226", nullptr));
        iconcheck->setText(QCoreApplication::translate("SystemDialog", "\346\234\200\345\260\217\345\214\226\345\210\260\347\263\273\347\273\237\346\211\230\347\233\230\345\233\276\346\240\207", nullptr));
        stopcheck->setText(QCoreApplication::translate("SystemDialog", "\346\234\200\345\260\217\345\214\226\346\227\266\346\232\202\345\201\234\350\247\206\351\242\221\346\222\255\346\224\276", nullptr));
        runlabel->setText(QCoreApplication::translate("SystemDialog", "\345\244\232\351\207\215\350\277\220\350\241\214", nullptr));
        checkBox_3->setText(QCoreApplication::translate("SystemDialog", "\345\205\201\350\256\270\345\220\214\346\227\266\350\277\220\350\241\214\345\244\232\344\270\252UOS\346\222\255\346\224\276\345\231\250", nullptr));
        label_2->setText(QCoreApplication::translate("SystemDialog", "\345\205\263\351\227\255\344\270\273\351\235\242\346\235\277", nullptr));
        radioButton->setText(QCoreApplication::translate("SystemDialog", "\346\234\200\345\260\217\345\214\226\345\210\260\347\263\273\347\273\237\346\211\230\347\233\230", nullptr));
        radioButton_2->setText(QCoreApplication::translate("SystemDialog", "\351\200\200\345\207\272\346\222\255\346\224\276\345\231\250", nullptr));
        playLabel->setText(QCoreApplication::translate("SystemDialog", "\346\231\256\351\200\232\346\250\241\345\274\217\344\270\213\350\247\206\351\242\221\346\226\207\344\273\266\346\211\223\345\274\200\346\227\266", nullptr));
        radioButton_6->setText(QCoreApplication::translate("SystemDialog", "\345\272\224\347\224\250\345\205\263\351\227\255\346\227\266\345\260\272\345\257\270\344\275\215\347\275\256", nullptr));
        radioButton_4->setText(QCoreApplication::translate("SystemDialog", "\350\207\252\345\212\250\345\205\250\345\261\217", nullptr));
        radioButton_5->setText(QCoreApplication::translate("SystemDialog", "\347\252\227\345\217\243\351\200\202\345\272\224\350\247\206\351\242\221", nullptr));
        radioButton_3->setText(QCoreApplication::translate("SystemDialog", "\350\247\206\351\242\221\351\200\202\345\272\224\347\252\227\345\217\243", nullptr));
        checkBox->setText(QCoreApplication::translate("SystemDialog", "\346\211\223\345\274\200\346\226\260\346\226\207\344\273\266\346\227\266\346\270\205\347\251\272\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        checkBox_2->setText(QCoreApplication::translate("SystemDialog", "\350\256\260\345\277\206\344\270\212\346\254\241\345\205\263\351\227\255\346\222\255\346\224\276\345\231\250\346\227\266\347\232\204\346\226\207\344\273\266\346\222\255\346\224\276\344\275\215\347\275\256", nullptr));
        checkBox_4->setText(QCoreApplication::translate("SystemDialog", "\346\222\255\346\224\276\350\277\236\347\273\255\345\211\247\346\227\266\350\207\252\345\212\250\345\234\250\346\226\207\344\273\266\345\244\271\344\270\255\346\237\245\346\211\276\345\205\263\350\201\224\346\226\207\344\273\266\346\222\255\346\224\276", nullptr));
        checkBox_5->setText(QCoreApplication::translate("SystemDialog", "\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\350\277\233\345\272\246\346\235\241\344\270\212\346\230\276\347\244\272\351\242\204\350\247\210\345\233\276", nullptr));
        checkBox_6->setText(QCoreApplication::translate("SystemDialog", "\345\274\200\345\220\257\351\253\230\346\270\205\345\212\240\351\200\237\346\250\241\345\274\217", nullptr));
        label_3->setText(QCoreApplication::translate("SystemDialog", "\346\222\255\346\224\276\344\277\241\346\201\257\346\230\276\347\244\272", nullptr));
        checkBox_7->setText(QCoreApplication::translate("SystemDialog", "\345\205\250\345\261\217\344\270\213\345\234\250\346\222\255\346\224\276\345\214\272\346\230\276\347\244\272\345\222\214\346\222\255\346\224\276\344\277\241\346\201\257", nullptr));
        checkBox_10->setText(QCoreApplication::translate("SystemDialog", "\345\211\251\344\275\231\347\224\265\351\207\217", nullptr));
        checkBox_8->setText(QCoreApplication::translate("SystemDialog", "\347\263\273\347\273\237\346\227\266\351\227\264", nullptr));
        checkBox_9->setText(QCoreApplication::translate("SystemDialog", "\346\222\255\346\224\276\350\277\233\345\272\246", nullptr));
        label_8->setText(QCoreApplication::translate("SystemDialog", "\346\230\276\347\244\272\345\206\205\345\256\271", nullptr));
        label_4->setText(QCoreApplication::translate("SystemDialog", "\346\210\252\345\233\276", nullptr));
        toCopyButton->setText(QCoreApplication::translate("SystemDialog", "\344\273\205\344\277\235\345\255\230\345\210\260\345\211\252\350\264\264\346\235\277", nullptr));
        toFileButton->setText(QCoreApplication::translate("SystemDialog", "\344\277\235\345\255\230\346\210\220\346\226\207\344\273\266", nullptr));
        pushButton->setText(QCoreApplication::translate("SystemDialog", "\346\265\217\350\247\210", nullptr));
        photoTypecomboBox->setItemText(0, QCoreApplication::translate("SystemDialog", "PNG", nullptr));
        photoTypecomboBox->setItemText(1, QCoreApplication::translate("SystemDialog", "JPG", nullptr));

        label_9->setText(QCoreApplication::translate("SystemDialog", "\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        label_10->setText(QCoreApplication::translate("SystemDialog", "\344\277\235\345\255\230\347\261\273\345\236\213", nullptr));
        label_11->setText(QString());
        sameViewsizeCheck->setText(QCoreApplication::translate("SystemDialog", "\346\214\211\345\275\223\345\211\215\346\230\276\347\244\272\347\232\204\347\224\273\351\235\242\345\260\272\345\257\270\346\210\252\345\233\276", nullptr));
        label_12->setText(QCoreApplication::translate("SystemDialog", "\350\277\236\346\213\215\345\274\240\346\225\260", nullptr));
        num4radioButton->setText(QCoreApplication::translate("SystemDialog", "4\345\274\240", nullptr));
        num9radioButton->setText(QCoreApplication::translate("SystemDialog", "9\345\274\240", nullptr));
        num16radioButton->setText(QCoreApplication::translate("SystemDialog", "16\345\274\240", nullptr));
        label_5->setText(QCoreApplication::translate("SystemDialog", "\345\255\227\345\271\225\345\257\274\345\205\245", nullptr));
        sameNameSubtitle->setText(QCoreApplication::translate("SystemDialog", "\350\207\252\345\212\250\350\275\275\345\205\245\345\220\214\345\220\215\345\255\227\345\271\225", nullptr));
        otherSubtitle->setText(QCoreApplication::translate("SystemDialog", "\350\207\252\345\212\250\350\275\275\345\205\245\345\220\214\346\226\207\344\273\266\345\244\271\344\270\213\345\205\266\344\273\226\345\255\227\345\271\225", nullptr));
        label_13->setText(QCoreApplication::translate("SystemDialog", "\346\214\207\345\256\232\344\275\215\347\275\256\346\220\234\347\264\242", nullptr));
        label_14->setText(QString());
        openFileButton->setText(QCoreApplication::translate("SystemDialog", "\346\265\217\350\247\210", nullptr));
        label_15->setText(QCoreApplication::translate("SystemDialog", "\345\255\227\344\275\223\346\240\267\345\274\217", nullptr));
        italicButton->setText(QString());
        label_16->setText(QCoreApplication::translate("SystemDialog", "\345\255\227\344\275\223", nullptr));
        boldButton->setText(QString());
        label_17->setText(QCoreApplication::translate("SystemDialog", "\351\242\234\350\211\262", nullptr));
        underLineButton->setText(QString());
        label_19->setText(QCoreApplication::translate("SystemDialog", "\351\200\217\346\230\216\345\272\246", nullptr));
        label_18->setText(QCoreApplication::translate("SystemDialog", "\345\255\227\345\217\267", nullptr));
        label_6->setText(QCoreApplication::translate("SystemDialog", "\345\243\260\345\215\241\351\200\211\346\213\251", nullptr));
        label_20->setText(QCoreApplication::translate("SystemDialog", "\346\263\250\357\274\232\350\257\245\350\256\276\347\275\256\344\270\213\346\254\241\346\222\255\346\224\276\346\227\266\347\224\237\346\225\210", nullptr));
        voiceOutputBox->setItemText(0, QCoreApplication::translate("SystemDialog", "\350\276\223\345\207\272\345\210\260\351\273\230\350\256\244\350\276\223\345\207\272\350\256\276\345\244\207", nullptr));
        voiceOutputBox->setItemText(1, QCoreApplication::translate("SystemDialog", "\344\270\273\345\243\260\351\237\263\351\251\261\345\212\250\347\250\213\345\272\217", nullptr));
        voiceOutputBox->setItemText(2, QCoreApplication::translate("SystemDialog", "\350\200\263\346\234\272\357\274\210Realtek(R) Audio\357\274\211", nullptr));
        voiceOutputBox->setItemText(3, QCoreApplication::translate("SystemDialog", "\346\211\254\345\243\260\345\231\250\357\274\210Realtek(R) Audio\357\274\211", nullptr));

        startEdit->setText(QCoreApplication::translate("SystemDialog", "Space", nullptr));
        label_26->setText(QCoreApplication::translate("SystemDialog", "\351\231\215\344\275\216\351\237\263\351\207\217", nullptr));
        label_24->setText(QCoreApplication::translate("SystemDialog", "\345\277\253\351\200\200", nullptr));
        exitEdit->setText(QCoreApplication::translate("SystemDialog", "ESC", nullptr));
        backingEdit->setText(QCoreApplication::translate("SystemDialog", "Left", nullptr));
        voiceDownEdit->setText(QCoreApplication::translate("SystemDialog", "Down", nullptr));
        speedingEdit->setText(QCoreApplication::translate("SystemDialog", "Right", nullptr));
        label_21->setText(QCoreApplication::translate("SystemDialog", "\351\200\200\345\207\272", nullptr));
        label_7->setText(QCoreApplication::translate("SystemDialog", "\345\270\270\347\224\250\347\203\255\351\224\256", nullptr));
        voiceUpEdit->setText(QCoreApplication::translate("SystemDialog", "Up", nullptr));
        label_22->setText(QCoreApplication::translate("SystemDialog", "\346\232\202\345\201\234/\345\274\200\345\247\213", nullptr));
        label_23->setText(QCoreApplication::translate("SystemDialog", "\345\277\253\350\277\233", nullptr));
        label_25->setText(QCoreApplication::translate("SystemDialog", "\345\215\207\351\253\230\351\237\263\351\207\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SystemDialog", "\347\241\256\350\256\244", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SystemDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemDialog: public Ui_SystemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMDIALOG_H
