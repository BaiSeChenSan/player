/********************************************************************************
** Form generated from reading UI file 'summary.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUMMARY_H
#define UI_SUMMARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Summary
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *first;
    QPushButton *second;
    QPushButton *third;
    QStackedWidget *stackedWidget;
    QWidget *firstPage;
    QGridLayout *gridLayout_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QTextEdit *textEdit;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QWidget *secondPage;
    QWidget *thirdPage;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_9;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QCheckBox *checkBox1;
    QCheckBox *checkBox2;
    QCheckBox *checkBox3;
    QLabel *label_6;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_10;
    QGridLayout *gridLayout_4;
    QTextEdit *addLike;
    QLabel *label_7;
    QListWidget *like;
    QPushButton *addButton_2;
    QFrame *frame_11;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QPushButton *addButton_3;
    QTextEdit *addDislike;
    QListWidget *dislike;
    QLabel *label_9;
    QPushButton *addButton;
    QFrame *table;
    QTableWidget *tableWidget;

    void setupUi(QDialog *Summary)
    {
        if (Summary->objectName().isEmpty())
            Summary->setObjectName(QString::fromUtf8("Summary"));
        Summary->resize(1000, 800);
        verticalLayout = new QVBoxLayout(Summary);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(Summary);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 40));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(0);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(12, 0, 12, 0);
        first = new QPushButton(frame_2);
        first->setObjectName(QString::fromUtf8("first"));
        first->setMinimumSize(QSize(0, 35));
        QFont font;
        font.setPointSize(10);
        first->setFont(font);

        horizontalLayout_2->addWidget(first);

        second = new QPushButton(frame_2);
        second->setObjectName(QString::fromUtf8("second"));
        second->setMinimumSize(QSize(0, 35));
        second->setFont(font);

        horizontalLayout_2->addWidget(second);

        third = new QPushButton(frame_2);
        third->setObjectName(QString::fromUtf8("third"));
        third->setMinimumSize(QSize(0, 35));
        third->setFont(font);

        horizontalLayout_2->addWidget(third);


        verticalLayout->addWidget(frame_2);

        stackedWidget = new QStackedWidget(Summary);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        firstPage = new QWidget();
        firstPage->setObjectName(QString::fromUtf8("firstPage"));
        gridLayout_2 = new QGridLayout(firstPage);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(12, -1, 12, 57);
        frame_3 = new QFrame(firstPage);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(350, 16777215));
        QFont font1;
        font1.setPointSize(11);
        label_2->setFont(font1);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2->setOpenExternalLinks(false);

        horizontalLayout_3->addWidget(label_2);

        comboBox = new QComboBox(frame_3);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMaximumSize(QSize(100, 16777215));
        comboBox->setFont(font1);

        horizontalLayout_3->addWidget(comboBox);

        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);


        gridLayout_2->addWidget(frame_3, 1, 0, 1, 1);

        frame_4 = new QFrame(firstPage);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(100, 0, 100, 0);
        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_4->addWidget(label_4);

        textEdit = new QTextEdit(frame_4);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_4->addWidget(textEdit);


        gridLayout_2->addWidget(frame_4, 2, 0, 1, 1);

        frame_5 = new QFrame(firstPage);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setMinimumSize(QSize(0, 550));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton = new QPushButton(frame_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(50, 16777215));
        QFont font2;
        font2.setPointSize(23);
        pushButton->setFont(font2);

        horizontalLayout_5->addWidget(pushButton);

        label = new QLabel(frame_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);"));

        horizontalLayout_5->addWidget(label);

        pushButton_2 = new QPushButton(frame_5);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(50, 16777215));
        pushButton_2->setFont(font2);

        horizontalLayout_5->addWidget(pushButton_2);


        gridLayout_2->addWidget(frame_5, 0, 0, 1, 1);

        stackedWidget->addWidget(firstPage);
        secondPage = new QWidget();
        secondPage->setObjectName(QString::fromUtf8("secondPage"));
        stackedWidget->addWidget(secondPage);
        thirdPage = new QWidget();
        thirdPage->setObjectName(QString::fromUtf8("thirdPage"));
        verticalLayout_2 = new QVBoxLayout(thirdPage);
        verticalLayout_2->setSpacing(9);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(16, -1, 16, -1);
        frame_9 = new QFrame(thirdPage);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setMaximumSize(QSize(16777215, 66));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_9);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(frame_9);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        label_5->setFont(font3);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        checkBox1 = new QCheckBox(frame_9);
        checkBox1->setObjectName(QString::fromUtf8("checkBox1"));
        checkBox1->setFont(font1);

        gridLayout->addWidget(checkBox1, 1, 0, 1, 1);

        checkBox2 = new QCheckBox(frame_9);
        checkBox2->setObjectName(QString::fromUtf8("checkBox2"));
        checkBox2->setFont(font1);

        gridLayout->addWidget(checkBox2, 1, 1, 1, 1);

        checkBox3 = new QCheckBox(frame_9);
        checkBox3->setObjectName(QString::fromUtf8("checkBox3"));
        checkBox3->setFont(font1);

        gridLayout->addWidget(checkBox3, 1, 2, 1, 1);


        verticalLayout_2->addWidget(frame_9);

        label_6 = new QLabel(thirdPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(16777215, 40));
        label_6->setFont(font3);

        verticalLayout_2->addWidget(label_6);

        frame = new QFrame(thirdPage);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(16777215, 320));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame_10 = new QFrame(frame);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"background-color: rgb(212, 234, 247);"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_10);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        addLike = new QTextEdit(frame_10);
        addLike->setObjectName(QString::fromUtf8("addLike"));
        addLike->setMaximumSize(QSize(16777215, 50));
        QFont font4;
        font4.setPointSize(15);
        addLike->setFont(font4);
        addLike->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 244, 241);\n"
"border-radius:15px;"));
        addLike->setAcceptRichText(true);

        gridLayout_4->addWidget(addLike, 2, 0, 1, 1);

        label_7 = new QLabel(frame_10);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setLayoutDirection(Qt::LeftToRight);

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        like = new QListWidget(frame_10);
        like->setObjectName(QString::fromUtf8("like"));
        like->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 244, 241);\n"
"border-radius:15px;"));

        gridLayout_4->addWidget(like, 1, 0, 1, 3);

        addButton_2 = new QPushButton(frame_10);
        addButton_2->setObjectName(QString::fromUtf8("addButton_2"));
        addButton_2->setMinimumSize(QSize(50, 50));
        addButton_2->setMaximumSize(QSize(50, 16777215));
        QFont font5;
        font5.setPointSize(25);
        addButton_2->setFont(font5);

        gridLayout_4->addWidget(addButton_2, 2, 1, 1, 1);


        horizontalLayout->addWidget(frame_10);

        frame_11 = new QFrame(frame);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 170, 127, 0.7);\n"
"border-radius:15px;"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_8 = new QLabel(frame_11);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("background:transparent;"));

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        addButton_3 = new QPushButton(frame_11);
        addButton_3->setObjectName(QString::fromUtf8("addButton_3"));
        addButton_3->setMinimumSize(QSize(50, 50));
        addButton_3->setMaximumSize(QSize(50, 16777215));
        addButton_3->setFont(font5);

        gridLayout_3->addWidget(addButton_3, 2, 1, 1, 1);

        addDislike = new QTextEdit(frame_11);
        addDislike->setObjectName(QString::fromUtf8("addDislike"));
        addDislike->setMaximumSize(QSize(16777215, 50));
        addDislike->setFont(font4);
        addDislike->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 221, 221);"));

        gridLayout_3->addWidget(addDislike, 2, 0, 1, 1);

        dislike = new QListWidget(frame_11);
        dislike->setObjectName(QString::fromUtf8("dislike"));
        dislike->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 221, 221);"));

        gridLayout_3->addWidget(dislike, 1, 0, 1, 2);


        horizontalLayout->addWidget(frame_11);


        verticalLayout_2->addWidget(frame);

        label_9 = new QLabel(thirdPage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(16777215, 40));
        label_9->setFont(font3);

        verticalLayout_2->addWidget(label_9);

        addButton = new QPushButton(thirdPage);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout_2->addWidget(addButton);

        table = new QFrame(thirdPage);
        table->setObjectName(QString::fromUtf8("table"));
        table->setFrameShape(QFrame::StyledPanel);
        table->setFrameShadow(QFrame::Raised);
        tableWidget = new QTableWidget(table);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 951, 221));
        tableWidget->setAutoFillBackground(false);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(317);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout_2->addWidget(table);

        stackedWidget->addWidget(thirdPage);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(Summary);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Summary);
    } // setupUi

    void retranslateUi(QDialog *Summary)
    {
        Summary->setWindowTitle(QCoreApplication::translate("Summary", "Dialog", nullptr));
        first->setText(QCoreApplication::translate("Summary", " \347\224\273\345\203\217", nullptr));
        second->setText(QCoreApplication::translate("Summary", "\346\200\273\347\273\223", nullptr));
        third->setText(QCoreApplication::translate("Summary", "\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("Summary", "\350\277\221", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Summary", "7\345\244\251", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Summary", "15\345\244\251", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Summary", "\344\270\200\344\270\252\346\234\210", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Summary", "\344\270\211\344\270\252\346\234\210", nullptr));

        label_3->setText(QCoreApplication::translate("Summary", "\345\205\263\351\224\256\350\257\215\347\273\237\350\256\241\344\272\221\345\233\276", nullptr));
        label_4->setText(QCoreApplication::translate("Summary", "\346\202\250\346\234\200\345\226\234\346\254\242\347\232\204\345\205\263\351\224\256\350\257\215", nullptr));
        pushButton->setText(QCoreApplication::translate("Summary", "<", nullptr));
        label->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("Summary", ">", nullptr));
        label_5->setText(QCoreApplication::translate("Summary", "\350\257\204\344\274\260\345\201\217\351\207\215", nullptr));
        checkBox1->setText(QCoreApplication::translate("Summary", "\345\206\205\345\256\271\344\274\230\345\205\210", nullptr));
        checkBox2->setText(QCoreApplication::translate("Summary", "\346\203\205\346\204\237\344\274\230\345\205\210", nullptr));
        checkBox3->setText(QCoreApplication::translate("Summary", "\345\235\207\350\241\241\346\250\241\345\274\217", nullptr));
        label_6->setText(QCoreApplication::translate("Summary", "\345\226\234\345\245\275/\345\261\217\350\224\275\350\256\276\347\275\256", nullptr));
        label_7->setText(QCoreApplication::translate("Summary", "\345\226\234\345\245\275\345\205\263\351\224\256\350\257\215", nullptr));
        addButton_2->setText(QCoreApplication::translate("Summary", "+", nullptr));
        label_8->setText(QCoreApplication::translate("Summary", "\345\261\217\350\224\275\345\205\263\351\224\256\350\257\215", nullptr));
        addButton_3->setText(QCoreApplication::translate("Summary", "+", nullptr));
        label_9->setText(QCoreApplication::translate("Summary", "\344\270\252\346\200\247\346\216\250\351\200\201", nullptr));
        addButton->setText(QCoreApplication::translate("Summary", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Summary: public Ui_Summary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMMARY_H
