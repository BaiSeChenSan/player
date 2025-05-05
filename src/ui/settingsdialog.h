#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
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
#include <QStyledItemDelegate>


namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog {
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();


signals:
    void buttonClicked(QString str,int index);  // 声明一个信号
    void speedChanged(double speed);
    void sizeChanged(int length,int width);
    void rotateView(int choice);
    //2025-3-2-subtitle
    void call_addSrt(QString );
private slots:
    void on_close_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();



    void on_horizontalSlider_valueChanged(int value);


    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_comboBox_3_currentTextChanged(const QString &arg1);

    void on_colorComboBox_currentTextChanged(const QString &arg1);

    //2025-3-2-subtitle
    void on_pushButton_clicked();


    void on_horizontalSlider_6_valueChanged(int value);

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

private:
    Ui::SettingsDialog *ui;


    QSettings settings;  // 使用应用程序名称和组织名称
    QSettings settings2;  // 使用应用程序名称和组织名称


};


#endif // SETTINGSDIALOG_H

