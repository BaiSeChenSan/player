/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *analyse;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *textEdit;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label;
    QLabel *gifLabel;
    QListView *listView;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(1024, 768);
        Dialog->setWindowOpacity(8.000000000000000);
        Dialog->setStyleSheet(QString::fromUtf8("background-color: qconicalgradient(\n"
"        cx: 0.5, cy: 0.5, angle: 0,\n"
"        stop: 0.0 rgba(230, 245, 255, 255),   /* \346\265\205\350\223\235\347\231\275 */\n"
"        stop: 0.3 rgba(200, 230, 255, 255),   /* \346\265\205\350\223\235 */\n"
"        stop: 0.6 rgba(180, 210, 255, 255),   /* \344\272\256\350\223\235 */\n"
"        stop: 0.9 rgba(220, 240, 255, 255),   /* \346\267\241\350\223\235\347\231\275 */\n"
"        stop: 1.0 rgba(230, 245, 255, 255)    /* \346\265\205\350\223\235\347\231\275 */\n"
"    );\n"
"font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        horizontalLayout = new QHBoxLayout(Dialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(8, -1, 6, -1);
        analyse = new QFrame(Dialog);
        analyse->setObjectName(QString::fromUtf8("analyse"));
        analyse->setMaximumSize(QSize(16777215, 16777215));
        analyse->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: transparent;\n"
"    border-radius: 16px;  /* \345\244\215\345\220\210\345\234\206\350\247\222\347\263\273\347\273\237 */\n"
"    font-family: 'Segoe UI Variable';\n"
"    font-size: 14px;\n"
"    color: #1a1a1a;\n"
"    \n"
"}"));
        analyse->setFrameShape(QFrame::StyledPanel);
        analyse->setFrameShadow(QFrame::Raised);
        analyse->setLineWidth(0);
        verticalLayout = new QVBoxLayout(analyse);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QPlainTextEdit(analyse);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(0, 0));
        textEdit->setStyleSheet(QString::fromUtf8("QPlainTextEdit{\n"
"background-color: rgba(150, 150, 150, 0.5);\n"
"     font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(64, 66, 68);\n"
"     padding:10px;\n"
"}"));
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit->setFrameShadow(QFrame::Raised);
        textEdit->setLineWidth(0);
        textEdit->setReadOnly(true);
        textEdit->setOverwriteMode(false);
        textEdit->setTabStopWidth(80);
        textEdit->setCursorWidth(3);
        textEdit->setMaximumBlockCount(0);

        verticalLayout->addWidget(textEdit);

        frame = new QFrame(analyse);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 200));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(150, 150, 150, 0.5);\n"
"border-radius:16px;\n"
"color: rgb(64, 66, 68);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(1);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 21, -1, 7);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(41, 42, 45,0.5);\n"
"    width: 50px;\n"
"    height: 50px;\n"
"    color:#1d1c1c;\n"
"border-radius: 15px;\n"
"}\n"
""));

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(16777215, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background:transparent;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icons/LOGO.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(90, 90));

        verticalLayout_2->addWidget(pushButton_2);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background:transparent;\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background:transparent;\n"
"}"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);


        verticalLayout->addWidget(frame);


        horizontalLayout->addWidget(analyse);

        gifLabel = new QLabel(Dialog);
        gifLabel->setObjectName(QString::fromUtf8("gifLabel"));

        horizontalLayout->addWidget(gifLabel);

        listView = new QListView(Dialog);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setMinimumSize(QSize(320, 0));
        listView->setMaximumSize(QSize(246, 16777215));
        listView->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-image: url(:/new/prefix1/icons/list3.png);\n"
"\\background-color: rgba(150, 150, 150, 0.5);\n"
""));

        horizontalLayout->addWidget(listView);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Lumos\350\247\206\351\242\221\345\210\206\346\236\220\345\212\251\346\211\213", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "test.mp4", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "\346\210\221\346\230\257Lumos\357\274\214\345\276\210\351\253\230\345\205\264\344\270\272\344\275\240\346\234\215\345\212\241\357\274\201", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\344\275\234\344\270\272Lumos\346\203\205\346\204\237\345\210\206\346\236\220\345\212\251\346\211\213\357\274\214\346\210\221\345\217\257\344\273\245\345\270\256\344\275\240\350\277\233\350\241\214\350\247\206\351\242\221\346\203\205\346\204\237\346\210\220\345\210\206\344\273\245\345\217\212\350\247\206\351\242\221\351\243\216\346\240\274\345\210\206\346\236\220\343\200\202", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\347\202\271\345\207\273\345\217\263\344\276\247\350\247\206\351\242\221\345\210\227\350\241\250\351\200\211\346\213\251\350\247\206\351\242\221\357\274\214\346\210\221\345\217\257\344\273\245\345\210\206\346\236\220\346\211\200\351\200\211\346\213\251\350\247\206\351\242\221\344\270\255\347\232\204\346\203\205\346\204\237\346\210\220\345\210\206\345\222\214\351\243\216\346\240\274\347\211\271\347\202\271\357\274\214\345\260\275\346\203\205\344\275\277\347\224\250\345\220\247\357\274\201", nullptr));
        gifLabel->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
