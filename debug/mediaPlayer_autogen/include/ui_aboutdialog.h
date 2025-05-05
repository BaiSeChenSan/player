/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_aboutDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QLabel *label;
    QPushButton *pushButton;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QDialog *aboutDialog)
    {
        if (aboutDialog->objectName().isEmpty())
            aboutDialog->setObjectName(QString::fromUtf8("aboutDialog"));
        aboutDialog->resize(579, 405);
        aboutDialog->setStyleSheet(QString::fromUtf8("QDialog{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 3px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(aboutDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, 0, -1);
        frame = new QFrame(aboutDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	border:none;\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius:3px;\n"
"}\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 0, 0);
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(50, 50));
        pushButton_3->setMaximumSize(QSize(50, 50));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icons/logo.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(40, 50));

        horizontalLayout->addWidget(pushButton_3);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Microsoft YaHei UI\";"));

        horizontalLayout->addWidget(label);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(38, 38));
        pushButton->setMaximumSize(QSize(40, 40));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none;\n"
"    background: transparent;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/close.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addWidget(frame);

        frame_3 = new QFrame(aboutDialog);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(0, 35));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(250, 250, 250);\n"
"	border:none;\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, 0, -1);
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 50));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font: 25 12pt \"Microsoft YaHei UI\";\n"
"	padding-left:20px;\n"
"}\n"
""));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 50));
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font: 25 12pt \"Microsoft YaHei UI\";\n"
"	padding-left:20px;\n"
"}\n"
""));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 50));
        label_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font: 25 12pt \"Microsoft YaHei UI\";\n"
"	padding-left:20px;\n"
"}\n"
""));

        verticalLayout_2->addWidget(label_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(frame_3);

        frame_2 = new QFrame(aboutDialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	border:none;\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius:3px;\n"
"}\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(40, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(14);
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


        verticalLayout->addWidget(frame_2);


        retranslateUi(aboutDialog);

        QMetaObject::connectSlotsByName(aboutDialog);
    } // setupUi

    void retranslateUi(QDialog *aboutDialog)
    {
        aboutDialog->setWindowTitle(QCoreApplication::translate("aboutDialog", "Dialog", nullptr));
        pushButton_3->setText(QString());
        label->setText(QCoreApplication::translate("aboutDialog", "\345\205\263\344\272\216Lumos Player", nullptr));
        pushButton->setText(QString());
        label_2->setText(QCoreApplication::translate("aboutDialog", "Lumos Player 1.2", nullptr));
        label_3->setText(QCoreApplication::translate("aboutDialog", "\346\202\246\351\211\264\350\247\206\347\225\214 \347\211\210\346\235\203\346\211\200\346\234\211", nullptr));
        label_4->setText(QCoreApplication::translate("aboutDialog", "Copyright \302\251 2025  Dorm 342. All Rights Reserved.", nullptr));
        pushButton_2->setText(QCoreApplication::translate("aboutDialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aboutDialog: public Ui_aboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
