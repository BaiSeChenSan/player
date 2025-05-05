// settingsdialog.cpp
#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include <QSettings>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{

    setWindowFlag(Qt::FramelessWindowHint);  // 去掉标题栏和边框
    ui->setupUi(this);

    // 创建 QSettings 实例
    QSettings settings("MyApp", "Settings");
    QSettings settings2("MyApp", "Settings2");


    // 加载并设置默认选中的按钮
    int selectedOption = settings.value("selectedOption", 1).toInt();  //快进/快退
    int viewOption = settings2.value("viewOption", 1).toInt();  // 默认选中 Option 1
    if (selectedOption == 1) {
        ui->radioButton->setChecked(true);
    } else if (selectedOption == 2) {
        ui->radioButton_2->setChecked(true);
    } else if (selectedOption == 3) {
        ui->radioButton_3->setChecked(true);
    }

    if (viewOption == 1) {
        ui->radioButton_4->setChecked(true);
    } else if (viewOption == 2) {
        ui->radioButton_5->setChecked(true);
    }


    //打开设置后，默认选择第一项
    ui->stackedWidget->setCurrentWidget(ui->page_1);
    ui->pushButton_4->setChecked(true);
    ui->pushButton_5->setChecked(false);
    ui->pushButton_6->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_2->setChecked(false);


    // 在MainWindow构造函数中
    ui->colorComboBox->setItemDelegate(new QStyledItemDelegate (this));


    // 连接多个按钮的 clicked 信号到同一个槽函数
    connect(ui->close_4, &QPushButton::clicked, this, &SettingsDialog::on_close_clicked);
}

SettingsDialog::~SettingsDialog() {
    delete ui;
}

void SettingsDialog::on_close_clicked() {
//    // 保存设置，在窗口关闭时保存选中的按钮
//    QSettings settings("MyApp", "Settings");     //确保在每次读取和写入配置时，都创建一个 QSettings 实例。
//    QSettings settings2("MyApp", "Settings2");
//    if (ui->radioButton->isChecked()) {
//        settings.setValue("selectedOption", 1);
//    } else if (ui->radioButton_2->isChecked()) {
//        settings.setValue("selectedOption", 2);
//    } else if (ui->radioButton_3->isChecked()) {
//        settings.setValue("selectedOption", 3);
//    }

//    if (ui->radioButton_4->isChecked()) {
//        settings2.setValue("viewOption", 1);
//    } else if (ui->radioButton_5->isChecked()) {
//        settings2.setValue("viewOption", 2);
//    } else if (ui->radioButton_6->isChecked()) {
//        settings2.setValue("viewOption", 3);
//    }
    // 关闭窗口
    this->close();
}


//窗口左侧五个选项的选中与取消
void SettingsDialog::on_pushButton_4_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->page_1);
    ui->pushButton_4->setChecked(true);
    ui->pushButton_5->setChecked(false);
    ui->pushButton_6->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_2->setChecked(false);

}

void SettingsDialog::on_pushButton_3_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    ui->pushButton_3->setChecked(true);
    ui->pushButton_5->setChecked(false);
    ui->pushButton_6->setChecked(false);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_2->setChecked(false);
}

void SettingsDialog::on_pushButton_5_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    ui->pushButton_5->setChecked(true);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_6->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_2->setChecked(false);

}

void SettingsDialog::on_pushButton_6_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->page_4);
    ui->pushButton_6->setChecked(true);
    ui->pushButton_5->setChecked(false);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_2->setChecked(false);

}

void SettingsDialog::on_pushButton_2_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->page_5);
    ui->pushButton_2->setChecked(true);
    ui->pushButton_6->setChecked(false);
    ui->pushButton_5->setChecked(false);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_3->setChecked(false);

}

void SettingsDialog::on_radioButton_clicked() {
    // 已经自动设置为选中，只需要保存状态
    QSettings settings("MyApp", "Settings");    //确保在每次读取和写入配置时，都创建一个 QSettings 实例。
    settings.setValue("selectedOption", 1);
    emit buttonClicked("selectedOption",1);          //快进单位变为5s
}

void SettingsDialog::on_radioButton_2_clicked() {
    // 已经自动设置为选中，只需要保存状态
    QSettings settings("MyApp", "Settings");
    settings.setValue("selectedOption", 2);
    emit buttonClicked("selectedOption",2);          //快进单位变为10s

}

void SettingsDialog::on_radioButton_3_clicked() {
    // 已经自动设置为选中，只需要保存状态
    QSettings settings("MyApp", "Settings");
    settings.setValue("selectedOption", 3);
    emit buttonClicked("selectedOption",3);          //快进单位变为20s

}


//调整画面比例
void SettingsDialog::on_radioButton_4_clicked()
{
    qDebug()<<"默认";
    emit sizeChanged(16,9);          //画面比例设置为默认

}

void SettingsDialog::on_radioButton_5_clicked()
{
    qDebug()<<"4:3";
    emit sizeChanged(4,3);          //画面比例设置为4：3

}

void SettingsDialog::on_radioButton_6_clicked()
{
    qDebug()<<"16：9";
    emit sizeChanged(16,9);         //画面比例设置为16：9

}



//播放倍速的调整
void SettingsDialog::on_horizontalSlider_valueChanged(int value)
{
    if(value==0)
    {
        emit speedChanged(0.5);
    }
    else if(value==1)
    {
        emit speedChanged(1.0);
    }
    else if(value==2)
    {
        emit speedChanged(1.5);
    }
    else if(value==3)
    {
        emit speedChanged(2.0);
    }
    qDebug()<<value;
}


//四种旋转，暂定
void SettingsDialog::on_pushButton_8_clicked()
{
    emit rotateView(1);
}

void SettingsDialog::on_pushButton_9_clicked()
{
    emit rotateView(2);
}

void SettingsDialog::on_pushButton_10_clicked()
{
    emit rotateView(3);
}

void SettingsDialog::on_pushButton_11_clicked()
{
    emit rotateView(4);
}



//字幕样式中字体的选择
void SettingsDialog::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    ui->comboBox_2->setCurrentText(arg1);
    qDebug()<<"字体："<<arg1;
}



//字幕样式中字体大小的选择
void SettingsDialog::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    ui->comboBox_3->setCurrentText(arg1);
    qDebug()<<"字体大小："<<arg1;
}


//字幕样式中字体颜色的选择
void SettingsDialog::on_colorComboBox_currentTextChanged(const QString &arg1)
{
    ui->colorComboBox->setCurrentText(arg1);
    qDebug()<<"字体颜色："<<arg1;
}

void SettingsDialog::on_pushButton_clicked()
{
    QString srtfile = QFileDialog::getOpenFileName(this, tr("Select Srt File"), "", tr("Srt Files (*.srt)"));
    emit call_addSrt(srtfile);
}


//字幕字体的透明度滑动条
void SettingsDialog::on_horizontalSlider_6_valueChanged(int value)
{
    qDebug()<<"字体透明度："<<value;
}


//字幕字体加粗
void SettingsDialog::on_pushButton_12_clicked()
{
     qDebug()<<"字幕字体加粗";
}


//字幕字体倾斜
void SettingsDialog::on_pushButton_14_clicked()
{
     qDebug()<<"字幕字体倾斜";
}


//字幕下划线
void SettingsDialog::on_pushButton_15_clicked()
{
    qDebug()<<"字幕下划线";

}
