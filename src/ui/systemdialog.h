#ifndef SYSTEMDIALOG_H
#define SYSTEMDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QButtonGroup>
#include<QFileDialog>
#include <QSettings>
#include<QKeyEvent>
#include<QFontDatabase>
#include <QColor>


namespace Ui {
class SystemDialog;
}

class SystemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SystemDialog(int initnum ,QWidget *parent = nullptr);
    ~SystemDialog();
signals:
    void call_apply_setting_Srt();


//槽函数
private slots:
    void on_exitButton_clicked();

    void on_pushButton_3_clicked();
    void on_iconcheck_stateChanged(int arg1);

    void on_stopcheck_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);
     void onRadioButtonClicked(QAbstractButton *button);
    void onRadioButtonClicked1(QAbstractButton *button);
    void onRadioButtonClicked2(QAbstractButton *button);
    void onRadioButtonClicked3(QAbstractButton *button);


    void on_checkBox_7_stateChanged(int arg1);
    void mousePressEvent(QMouseEvent *event);
    void on_exitEdit_editingFinished();

    void on_startEdit_editingFinished();

    void on_speedingEdit_editingFinished();

    void on_backingEdit_editingFinished();

    void on_voiceUpEdit_editingFinished();

    void on_voiceDownEdit_editingFinished();

    void on_voiceOutputBox_currentIndexChanged(int index);

    void on_openFileButton_clicked();

    void on_boldButton_clicked();

    void on_italicButton_clicked();

    void on_underLineButton_clicked();

    void on_transparencySlider_valueChanged(int value);

    void on_sameNameSubtitle_stateChanged(int arg1);

    void on_otherSubtitle_stateChanged(int arg1);

    void on_sameViewsizeCheck_stateChanged(int arg1);

    void on_pushButton_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_4_stateChanged(int arg1);

    void on_checkBox_5_stateChanged(int arg1);

    void on_checkBox_6_stateChanged(int arg1);

    void on_checkBox_9_stateChanged(int arg1);

    void on_checkBox_8_stateChanged(int arg1);

    void on_checkBox_10_stateChanged(int arg1);

    void keyPressEvent(QKeyEvent *event);

    void on_pushButton_2_clicked();

    void on_fontComboBox_activated(const QString &arg1);

    void on_fontSizeCombox_activated(const QString &arg1);

    void on_colorComboBox_activated(const QString &arg1);

    void on_photoTypecomboBox_activated(const QString &arg1);

private:
    //先初始化那个列表选择区域
    void initlistArea(int num);
    void initSettingInfor();
    void initSystem();
    void initPlay();
    void initPicture();
    void initSubtitle();
    void initMouse();
    bool eventFilter(QObject* obj, QEvent* event);

private:
    Ui::SystemDialog *ui;
    bool iswindowMinToBar;
    bool isminStopVideo;
    bool ismultiPlayerRun;
    QString closeMainFrame;
    QString videoOpen;
    bool isnewFileClearList;
    bool islastFilePosition;
    bool isshowPreview ;
    bool ishighspeedMode;
    bool isfullScreenInfor;
    bool issystemTime;
    bool isplayProgress;
    bool iscurrentPower;
    QString photoNum;
    QString photoSaveWays;
    QString photoType;
    bool isscreenshotSameAsView;
    QString savePhotoPath;
    bool issameNameSubtitle;
    bool isotherNameSubtitle;
    QString subtitlePath;
    bool issubtitleFontBold ;
    bool issubtitleFontItalic;
    bool issubtitleFontUnderline;
    QString subtitleFont;
    QString subtitleColor;
    QString subtitleFontSize;
    int subtitleTransparency;
    int voiceOutputDevice;
    QString  exitEdit;
    QString startEdit;
    QString speedingEdit;
    QString backingEdit;
    QString voiceUpEdit;
    QString voiceDownEdit;


public:
    QSettings settings;
    void setRow(int);

};

#endif // SYSTEMDIALOG_H
