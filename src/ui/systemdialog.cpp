#include "systemdialog.h"
#include "ui_systemdialog.h"

SystemDialog::SystemDialog(int initnum , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SystemDialog),
    settings("MyApp", "Settings")
{
    qApp->installEventFilter(this);
    setWindowFlag(Qt::FramelessWindowHint);  // 去掉标题栏和边框
    ui->setupUi(this);
              //创建播放器相关的配置文件
    initSettingInfor();
    initlistArea(initnum);
    initSystem();
    initPlay();
    initPicture();
    initSubtitle();
    initMouse();
    ui->voiceOutputBox->setCurrentIndex(settings.value("voiceOutputDevice", "0").toInt());
    ui->pushButton_2->setEnabled(false);
}

SystemDialog::~SystemDialog()
{
    delete ui;
}
//初始化系统list界面
void SystemDialog:: initlistArea(int num){

    //这种为系统自带的信号与槽函数，如果想要自定义信号与槽，此时可以方便实现前后端分离，其中信号函数为抽象函数，只有声明没有具有的实现，但需要通过emit 来调用信号函数目的在于可以触发信号，然后实现信号与槽进行关联的机制

    // 连接信号与槽
    connect(ui->listWidget, &QListWidget::currentRowChanged, ui->stackedWidget, &QStackedWidget::setCurrentIndex);
    //设置当前的选中的选项
    ui->listWidget->setCurrentRow(num);


}

void SystemDialog::mousePressEvent(QMouseEvent *event) {
    // 检查点击的区域是否在 QLineEdit 上
    QWidget* widget = QApplication::widgetAt(event->globalPos()); // 获取鼠标下的控件
       if (widget == nullptr || qobject_cast<QLineEdit*>(widget) == nullptr) {
           // 如果鼠标点击的地方不是 QLineEdit，则清除所有 QLineEdit 的焦点
           ui->exitEdit->clearFocus();
           ui->startEdit->clearFocus();
           ui->speedingEdit->clearFocus();
           ui->backingEdit->clearFocus();
           ui->voiceUpEdit->clearFocus();
           ui->voiceDownEdit->clearFocus();
       }
       QWidget::mousePressEvent(event);
}

void SystemDialog::on_exitButton_clicked()
{
    this->close();
}

void SystemDialog::on_pushButton_3_clicked()
{
    this->close();
}

void SystemDialog::initSettingInfor(){
    //系统设置界面
    iswindowMinToBar = settings.value("windowMinToBar", false).toBool();
    isminStopVideo   = settings.value("minStopVideo",false).toBool();
    ismultiPlayerRun = settings.value("multiPlayerRun", false).toBool();
    closeMainFrame = settings.value("closeMainFrame", "exit").toString();

    //播放设置界面
    videoOpen = settings.value("videoOpen","videoFitFrame").toString();
    isnewFileClearList = settings.value("newFileClearList", false).toBool();
    islastFilePosition = settings.value("lastFilePosition",false).toBool();
    isshowPreview = settings.value("showPreview",false).toBool();
    ishighspeedMode = settings.value("high-speedMode",false).toBool();
    isfullScreenInfor = settings.value("fullScreenInfor",false).toBool();
    issystemTime = settings.value("systemTime",false).toBool();
    isplayProgress = settings.value("playProgress",false).toBool();
    iscurrentPower = settings.value("currentPower",false).toBool();

    //截图界面
    photoNum = settings.value("photoNum","9").toString();
    photoSaveWays = settings.value("photoSaveWays","saveToCopy").toString();
    savePhotoPath = settings.value("savePhotoPath","").toString();
    photoType = settings.value("photoType", "PNG").toString();
    isscreenshotSameAsView = settings.value("screenshotSameAsView",false).toBool();

    //处理字幕部分
    issameNameSubtitle = settings.value("sameNameSubtitle", false).toBool();
    isotherNameSubtitle = settings.value("otherNameSubtitle", false).toBool();
    subtitlePath = settings.value("subtitlePath","").toString();
    issubtitleFontBold = settings.value("subtitleFontBold",false).toBool();
    issubtitleFontItalic = settings.value("subtitleFontItalic",false).toBool();
    issubtitleFontUnderline = settings.value("subtitleFontUnderline", false).toBool();
    subtitleFont = settings.value("subtitleFont","微软雅黑").toString();
    subtitleColor = settings.value("subtitleColor", "black").toString();
    subtitleFontSize = settings.value("subtitleFontSize", "12").toString();
    subtitleTransparency = settings.value("subtitleTransparency", "0").toInt();

    //处理声音输出设备
    voiceOutputDevice = settings.value("voiceOutputDevice","0").toInt();

    //处理热键部分
    exitEdit = settings.value("exitEdit","Esc").toString();
    startEdit = settings.value("startEdit","Space").toString();
    speedingEdit = settings.value("speedingEdit","Right").toString();
    backingEdit = settings.value("backingEdit", "Left").toString();
    voiceUpEdit = settings.value("voiceUpEdit","Up").toString();
    voiceDownEdit = settings.value("voiceDownEdit","Down").toString();



}
//最小化到系统托盘处
void SystemDialog::on_iconcheck_stateChanged(int arg1)
{
    if(!arg1){      
        //settings.setValue("windowMinToBar", false);
        iswindowMinToBar = false;
    }else{
        //settings.setValue("windowMinToBar", true);
        iswindowMinToBar = true;
    }
    ui->pushButton_2->setEnabled(true);
}
//当最小化之后暂停时评播放
void SystemDialog::on_stopcheck_stateChanged(int arg1)
{
    if(!arg1){
        isminStopVideo = false;
    }else{
        isminStopVideo = true;
        //settings.setValue("minStopVideo", true);
    }
    ui->pushButton_2->setEnabled(true);
}
//允许运行多个uos播放器
void SystemDialog::on_checkBox_3_stateChanged(int arg1)
{
    if(!arg1){
        ismultiPlayerRun = false;
    }else{
        ismultiPlayerRun = true;
         //settings.setValue("multiPlayerRun", true);
    }
    ui->pushButton_2->setEnabled(true);
}

//系统设置初始化，将radiobutton进行绑定使得互斥执行
void SystemDialog::initSystem(){
     QButtonGroup* group = new QButtonGroup(this);
     group->addButton(ui->radioButton);
     group->addButton(ui->radioButton_2);
     connect(group,SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onRadioButtonClicked1(QAbstractButton*)));

     //根据.ini文件来对系统设置界面进行选项的初始化
     if(settings.value("windowMinToBar", true).toBool()){
         ui->iconcheck->setChecked(true);
     }else{
         ui->iconcheck->setChecked(false);
     }

     if(settings.value("minStopVideo", true).toBool()){
         ui->stopcheck->setChecked(true);
     }else{
         ui->stopcheck->setChecked(false);
     }

     if(settings.value("multiPlayerRun", true).toBool()){
         ui->checkBox_3->setChecked(true);
     }else{
         ui->checkBox_3->setChecked(false);
     }
     //默认作退出处理
     if(settings.value("closeMainFrame", "exit").toString() == "exit"){
         ui->radioButton_2->setChecked(true);
     }else{
         ui->radioButton->setChecked(true);
     }

}

//处理radiobutton的槽函数
void SystemDialog::onRadioButtonClicked1(QAbstractButton *button){
    QString choices = "";
    if(button->text() == "最小化到系统托盘"){
        choices = "minToBar";
    }else{
        choices = "exit";
    }

    closeMainFrame = choices;
    ui->pushButton_2->setEnabled(true);
}


void SystemDialog::initPlay(){
    QButtonGroup* group = new QButtonGroup(this);
    group->addButton(ui->radioButton_3);
    group->addButton(ui->radioButton_4);
    group->addButton(ui->radioButton_5);
    group->addButton(ui->radioButton_6);
    connect(group,SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onRadioButtonClicked(QAbstractButton*)));

    if(settings.value("videoOpen", "视频适应窗口").toString() == "videoFitFrame"){
        ui->radioButton_3->setChecked(true);
    }else if(settings.value("videoOpen", "自动全屏").toString() == "autoWholeScreen"){
        ui->radioButton_4->setChecked(true);
    }else if(settings.value("videoOpen", "应用关闭时尺寸位置").toString() == "useLastSize"){
        ui->radioButton_6->setChecked(true);
    }else{
        ui->radioButton_5->setChecked(true);
    }

    if(settings.value("newFileClearList", false).toBool()){
        ui->checkBox->setChecked(true);
    }else{
        ui->checkBox->setChecked(false);
    }

    if(settings.value("lastFilePosition", false).toBool()){
        ui->checkBox_2->setChecked(true);
    }else{
         ui->checkBox_2->setChecked(false);
    }

    if(settings.value("showPreview", false).toBool()){
        ui->checkBox_5->setChecked(true);
    }else{
         ui->checkBox_5->setChecked(false);
    }

    if(settings.value("highspeedMode", false).toBool()){
        ui->checkBox_6->setChecked(true);
    }else{
         ui->checkBox_6->setChecked(false);
    }

    if(settings.value("fullScreenInfor", false).toBool()){
        ui->checkBox_7->setChecked(true);
        ui->frame_7->setEnabled(true);
    }else{
         ui->checkBox_7->setChecked(false);
         ui->frame_7->setEnabled(false);
    }

    if(settings.value("systemTime", false).toBool()){
        ui->checkBox_8->setChecked(true);
    }else{
         ui->checkBox_8->setChecked(false);
    }

    if(settings.value("playProgress", false).toBool()){
        ui->checkBox_9->setChecked(true);
    }else{
         ui->checkBox_9->setChecked(false);
    }

    if(settings.value("currentPower", false).toBool()){
        ui->checkBox_10->setChecked(true);
    }else{
         ui->checkBox_10->setChecked(false);
    }
}

//处理radiobutton的槽函数
void SystemDialog::onRadioButtonClicked(QAbstractButton *button){
    QString choices = "";
    if(button->text() == "视频适应窗口"){
        choices = "videoFitFrame";
    }else if(button->text() == "自动全屏"){
        choices = "autoWholeScreen";
    }else if(button->text() == "应用关闭时尺寸位置"){
        //此时可能需要额外一个数据来记录上一次的尺寸大小
        choices = "useLastSize";
    }else{
        choices = "fameFitVideo";
    }
    videoOpen = choices;
    //settings.setValue("videoOpen", videoOpen);
     ui->pushButton_2->setEnabled(true);

}


//播放界面的槽函数部分

//打开新文件时清空播放列表
void SystemDialog::on_checkBox_stateChanged(int arg1)
{
    if(!arg1){
        isnewFileClearList = false;
        //settings.setValue("newFileClearList", isnewFileClearList);
    }else{
        //当此选项被勾选之后
        isnewFileClearList = true;
        //settings.setValue("newFileClearList", true);
    }
     ui->pushButton_2->setEnabled(true);
}
//记忆上次关闭播放器时的文件播放位置
void SystemDialog::on_checkBox_2_stateChanged(int arg1)
{
    if(!arg1){
        //
        islastFilePosition = false;

    }else{
        //当此选项被勾选之后
        //当此选项被打开后，需要一个单独的变量存放是一个存发的位置
        //settings.setValue("lastFilePosition", true);
        islastFilePosition = true;
    }
     ui->pushButton_2->setEnabled(true);
}

//感觉这个实用性不高，不建议添加
//播放连续剧时自动在文件夹中查找关联文件播放
void SystemDialog::on_checkBox_4_stateChanged(int arg1)
{
    if(!arg1){
        qDebug()<<"此选项未被勾选了！";
    }else{
        //当此选项被勾选之后
        qDebug()<<"此选项被勾选了！播放连续剧时自动在文件夹中查找关联文件播放";
    }
     ui->pushButton_2->setEnabled(true);
}

//鼠标悬停时进度条上显示预览图
void SystemDialog::on_checkBox_5_stateChanged(int arg1)
{
    if(!arg1){
        isshowPreview = false;

    }else{
        //当此选项被勾选之后
        isshowPreview = true;
        //settings.setValue("showPreview", true);
    }
     ui->pushButton_2->setEnabled(true);
}
//开启高清加速模式
void SystemDialog::on_checkBox_6_stateChanged(int arg1)
{
    if(!arg1){
        ishighspeedMode = false;
        //settings.setValue("highspeedMode", ishighspeedMode);
    }else{
        //当此选项被勾选之后
        ishighspeedMode = true;
        //settings.setValue("highspeedMode", true);
    }
     ui->pushButton_2->setEnabled(true);
}

//播放信息显示，决定其在全屏模式下可以查看的信息有哪些
void SystemDialog::on_checkBox_7_stateChanged(int arg1)
{
    if(!arg1){
        //settings.setValue("fullScreenInfor", isfullScreenInfor);
        isfullScreenInfor = false;
        ui->frame_7->setEnabled(false);
    }else{
        //当此选项被勾选之后才能下面的选项开始选择
        ui->frame_7->setEnabled(true);
        //settings.setValue("fullScreenInfor", true);
        isfullScreenInfor = true;
    }
     ui->pushButton_2->setEnabled(true);
}

//显示播放进度选项
void SystemDialog::on_checkBox_9_stateChanged(int arg1)
{
    if(!arg1){
        isplayProgress = false;
        //settings.setValue("playProgress", isplayProgress);
    }else{
        //当此选项被勾选之后
        isplayProgress = true;
        //settings.setValue("playProgress", true);
    }
     ui->pushButton_2->setEnabled(true);
}
//显示具体系统时间选项
void SystemDialog::on_checkBox_8_stateChanged(int arg1)
{
    if(!arg1){
        //qDebug()<<"此选项未被勾选了！";
        issystemTime = false;
        //settings.setValue("systemTime", issystemTime);
    }else{
        //当此选项被勾选之后
        issystemTime = true;
       // settings.setValue("systemTime", true);
        //qDebug()<<"此选项被勾选了！系统时间";
    }
     ui->pushButton_2->setEnabled(true);
}
//显示剩余电量选项
void SystemDialog::on_checkBox_10_stateChanged(int arg1)
{
    if(!arg1){
       //qDebug()<<"此选项未被勾选了！";
        iscurrentPower = false;

    }else{
        //当此选项被勾选之后
        //qDebug()<<"此选项被勾选了！剩余电量";
        //settings.setValue("currentPower", true);
        iscurrentPower = true;
    }
     ui->pushButton_2->setEnabled(true);
}


//对截图部分的槽函数
void SystemDialog::initPicture(){
    QButtonGroup* group = new QButtonGroup(this);
    QButtonGroup* group2 = new QButtonGroup(this);
    group->addButton(ui->toCopyButton);
    group->addButton(ui->toFileButton);
    group2->addButton(ui->num4radioButton);
    group2->addButton(ui->num9radioButton);
    group2->addButton(ui->num16radioButton);
    connect(group2,SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onRadioButtonClicked3(QAbstractButton*)));
    connect(group,SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onRadioButtonClicked2(QAbstractButton*)));

    if(settings.value("photoNum", "9").toString() == "4"){
        ui->num4radioButton->setChecked(true);
    }else if(settings.value("photoNum", "9").toString() == "9"){
        ui->num9radioButton->setChecked(true);
    }else{
        ui->num16radioButton->setChecked(true);
    }

    if(settings.value("photoSaveWays","saveToCopy").toString() == "saveToCopy"){
        ui->toCopyButton->setChecked(true);
    }else{
        ui->toFileButton->setChecked(true);
    }

    //设定文件保存路径
    ui->label_11->setText(settings.value("savePhotoPath", "").toString());

    ui->photoTypecomboBox->setCurrentText(settings.value("photoType","PNG").toString());
    if(settings.value("screenshotSameAsView", true).toBool()){
        ui->sameViewsizeCheck->setChecked(true);
    }else{
        ui->sameViewsizeCheck->setChecked(false);
    }
}

//处理radiobutton的槽函数
void SystemDialog::onRadioButtonClicked3(QAbstractButton *button){
    QString choices = "";
    if(button->text() == "4张"){
        choices = "4" ;
    }else if(button->text() == "9张"){
        choices = "9";
    }else{
        choices = "16";
    }
    qDebug() << choices;
    photoNum = choices;

    ui->pushButton_2->setEnabled(true);

}
//处理radiobutton的槽函数
void SystemDialog::onRadioButtonClicked2(QAbstractButton *button){
    QString choices = "";
    if(button->text() == "仅保存到剪贴板"){
        choices = "saveToCopy";
    }else{
        choices = "saveAsFile";
    }
    photoSaveWays = choices;

     ui->pushButton_2->setEnabled(true);
}

//处理截图类型的槽函数
void SystemDialog::on_photoTypecomboBox_activated(const QString &arg1)
{
    photoType = arg1;
    ui->pushButton_2->setEnabled(true);
}

//截图的画面大小是否和界面大小一致
void SystemDialog::on_sameViewsizeCheck_stateChanged(int arg1)
{
    if(!arg1){
        //qDebug()<<"此选项未被勾选了！";
        isscreenshotSameAsView = false;

    }else{
        //当此选项被勾选之后
        isscreenshotSameAsView = true;

    }
     ui->pushButton_2->setEnabled(true);
}
//选择保存文件的路径
void SystemDialog::on_pushButton_clicked()
{

    QString folderPath = QFileDialog::getExistingDirectory(
            this,                      // 父窗口
            "请选择UOSPlayer图片保存目录",               // 对话框标题
            QDir::homePath(),           // 默认路径（用户的主目录）
            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks // 只显示文件夹，不解析符号链接
        );

    if (!folderPath.isEmpty()) {
        // 用户选择了文件，将选择的路径添加到
        ui->label_11->setText(folderPath);
        //设置默认的路径
        savePhotoPath = folderPath;

    }
     ui->pushButton_2->setEnabled(true);
}


//字幕设置部分的槽函数，当有字幕导入之后才能进行对字幕字体之类的设置，所以一开始设定为不可选中状态

void SystemDialog::initSubtitle(){
    //设定导入字母的路径
    ui->label_14->setText(settings.value("subtitlePath", "").toString());

    if(settings.value("sameNameSubtitle", true).toBool()){
        ui->sameNameSubtitle->setChecked(true);
    }else{
        ui->sameNameSubtitle->setChecked(false);
    }

    if(settings.value("otherNameSubtitle", true).toBool()){
        ui->otherSubtitle->setChecked(true);
    }else{
        ui->otherSubtitle->setChecked(false);
    }


    //只有当导入字幕文件之后才会使得其可以设定字幕的样式，设置默认为false
    ui->frame_9->setEnabled(true);
    if(settings.value("subtitleFontBold", false).toBool()){
        ui->boldButton->setStyleSheet("QPushButton{background-color:rgb(53, 134, 255);border: 1px solid gray;border-radius:3px;} QPushButton:hover{ background-color: rgb(223, 223, 223);}");
    }else{
        ui->boldButton->setStyleSheet("QPushButton{background-color:transparent;border: 1px solid gray;border-radius:3px;} QPushButton:hover{ background-color: rgb(223, 223, 223);}");
    }

    if(settings.value("subtitleFontItalic", false).toBool()){
        ui->italicButton->setStyleSheet("QPushButton{background-color:rgb(53, 134, 255);border: 1px solid gray;border-radius:3px;} QPushButton:hover{ background-color: rgb(223, 223, 223);}");
    }else{
        ui->italicButton->setStyleSheet("QPushButton{background-color:transparent;border: 1px solid gray;border-radius:3px;} QPushButton:hover{ background-color: rgb(223, 223, 223);}");
    }

    if(settings.value("subtitleFontUnderline", false).toBool()){
        ui->underLineButton->setStyleSheet("QPushButton{background-color:rgb(53, 134, 255);border: 1px solid gray;border-radius:3px;} QPushButton:hover{ background-color: rgb(223, 223, 223);}");
    }else{
        ui->underLineButton->setStyleSheet("QPushButton{background-color:transparent;border: 1px solid gray;border-radius:3px;} QPushButton:hover{ background-color: rgb(223, 223, 223);}");
    }


    // 添加系统所有字体到 QComboBox
    QFontDatabase fontDatabase;
    QStringList fontFamilies = fontDatabase.families();
    ui->fontComboBox->addItems(fontFamilies);

    // 添加常见字体大小
    QList<int> standardSizes = QFontDatabase::standardSizes();
    for (int size : standardSizes) {
        ui->fontSizeCombox->addItem(QString::number(size));
    }

    // 添加常见颜色
    QStringList colorNames = QColor::colorNames();
    for (const QString &colorName : colorNames) {
       QColor color(colorName);
       ui->colorComboBox->addItem(colorName, color); // 绑定颜色数据
       // 设置选项的前景色
       ui->colorComboBox->setItemData(ui->colorComboBox->count() - 1, color, Qt::DecorationRole);
    }

    ui->fontComboBox->setCurrentText(settings.value("subtitleFont","微软雅黑").toString());
    ui->fontSizeCombox->setCurrentText(settings.value("subtitleFontSize", "12").toString());
    ui->colorComboBox->setCurrentText(settings.value("subtitleColor","black").toString());
    ui->transparencySlider->setValue(settings.value("subtitleTransparency", "0").toInt());

}
//打开文件对话框，选择导入字幕文件的位置
void SystemDialog::on_openFileButton_clicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(
            this,                      // 父窗口
            "请选择指定文件路径",               // 对话框标题
            QDir::homePath(),           // 默认路径（用户的主目录）
            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks // 只显示文件夹，不解析符号链接
        );

    if (!folderPath.isEmpty()) {
        // 用户选择了文件，将选择的路径添加到
        ui->label_14->setText(folderPath);
        settings.setValue("subtitlePath", folderPath);
    }
     ui->pushButton_2->setEnabled(true);
}
//对字幕加粗选项
void SystemDialog::on_boldButton_clicked()
{
    issubtitleFontBold = !issubtitleFontBold;
        if(issubtitleFontBold){
            ui->boldButton->setStyleSheet("QPushButton{background-color:rgb(53, 134, 255);border: 1px solid gray;border-radius:3px;} QPushButton:hover{ background-color: rgb(223, 223, 223);}");
        }else{
            ui->boldButton->setStyleSheet("QPushButton{background-color:transparent;border: 1px solid gray;border-radius:3px;} QPushButton:hover{ background-color: rgb(223, 223, 223);}");
        }
    ui->pushButton_2->setEnabled(true);

}
//将字幕字体改为斜体
void SystemDialog::on_italicButton_clicked()
{
    //qDebug()<<"字幕斜体选项打开了";
    issubtitleFontItalic = !issubtitleFontItalic;
        if(issubtitleFontItalic){
            ui->italicButton->setStyleSheet("QPushButton{background-color:rgb(53, 134, 255);border: 1px solid gray;border-radius:3px;} QPushButton:hover{ background-color: rgb(223, 223, 223);}");
        }else{
            ui->italicButton->setStyleSheet("QPushButton{background-color:transparent;border: 1px solid gray;border-radius:3px;} QPushButton:hover{ background-color: rgb(223, 223, 223);}");
        }
    ui->pushButton_2->setEnabled(true);
}
//对字幕字体添加下划线
void SystemDialog::on_underLineButton_clicked()
{
    issubtitleFontUnderline = !issubtitleFontUnderline;
        if(issubtitleFontUnderline){
            ui->underLineButton->setStyleSheet("QPushButton{background-color:rgb(53, 134, 255);border: 1px solid gray;border-radius:3px;} QPushButton:hover{ background-color: rgb(223, 223, 223);}");
        }else{
            ui->underLineButton->setStyleSheet("QPushButton{background-color:transparent;border: 1px solid gray;border-radius:3px;} QPushButton:hover{ background-color: rgb(223, 223, 223);}");
        }

    ui->pushButton_2->setEnabled(true);
}

void SystemDialog::on_fontComboBox_activated(const QString &arg1)
{
    // qDebug()<<"当前字幕的字体是："<<arg1;
    subtitleFont = arg1;

     ui->pushButton_2->setEnabled(true);
}

//设置字体颜色
void SystemDialog::on_colorComboBox_activated(const QString &arg1)
{
    subtitleColor = arg1;

    ui->pushButton_2->setEnabled(true);
}

//设置字幕字体大小
void SystemDialog::on_fontSizeCombox_activated(const QString &arg1)
{
    subtitleFontSize = arg1;

    ui->pushButton_2->setEnabled(true);
}

//设置字幕的背景透明度
void SystemDialog::on_transparencySlider_valueChanged(int value)
{
    //qDebug()<<"当前字幕的透明度是："<<value;
    subtitleTransparency = value;
    ui->pushButton_2->setEnabled(true);
}

//选择载入同名字幕
void SystemDialog::on_sameNameSubtitle_stateChanged(int arg1)
{
    if(!arg1){
        //qDebug()<<"此选项未被勾选了！";
        issameNameSubtitle = false;
        //settings.setValue("sameNameSubtitle", false);
    }else{
        //当此选项被勾选之后
        issameNameSubtitle = true;
        //settings.setValue("sameNameSubtitle", true);
        //qDebug()<<"此选项被勾选了！，选择载入同名字幕";
    }
     ui->pushButton_2->setEnabled(true);
}
//选择载入同文件夹下的其他名字的字幕
void SystemDialog::on_otherSubtitle_stateChanged(int arg1)
{
    if(!arg1){
        isotherNameSubtitle = false;
        //settings.setValue("otherNameSubtitle", false);
        //qDebug()<<"此选项未被勾选了！";
    }else{
        //当此选项被勾选之后
        isotherNameSubtitle = true;
        //settings.setValue("otherNameSubtitle", true);
        //qDebug()<<"此选项被勾选了！，载入同文件夹下的其他名字的字幕";
    }
     ui->pushButton_2->setEnabled(true);
}

//声音设置部分需要实现的槽函数
void SystemDialog::on_voiceOutputBox_currentIndexChanged(int index)
{
    //设置声音输出设备的默认选项
    voiceOutputDevice = index;
     //qDebug()<<"当前的选项是"<<index;
      ui->pushButton_2->setEnabled(true);

}

//鼠标热键部分需要执行的槽函数
void SystemDialog::initMouse(){
    ui->exitEdit->setText(settings.value("exitEdit", "Esc").toString());
    ui->startEdit->setText(settings.value("startEdit", "Space").toString());
    ui->speedingEdit->setText(settings.value("speedingEdit", "Right").toString());
    ui->backingEdit->setText(settings.value("backingEdit", "Left").toString());
    ui->voiceUpEdit->setText(settings.value("voiceUpEdit", "Up").toString());
    ui->voiceDownEdit->setText(settings.value("voiceDownEdit", "Down").toString());
}

//退出键的热键修改
void SystemDialog::on_exitEdit_editingFinished()
{
     exitEdit = ui->exitEdit->text();

     ui->pushButton_2->setEnabled(true);
   // qDebug()<<"退出键已经被修改";

}
//停止或开始热键修改
void SystemDialog::on_startEdit_editingFinished()
{
    startEdit = ui->startEdit->text();

    //qDebug()<<"停止或开始键已经被修改";
     ui->pushButton_2->setEnabled(true);
}
//快进热键修改
void SystemDialog::on_speedingEdit_editingFinished()
{
    speedingEdit = ui->speedingEdit->text();

    //qDebug()<<"快进键已经被修改";
     ui->pushButton_2->setEnabled(true);
}
//快退热键修改
void SystemDialog::on_backingEdit_editingFinished()
{
    backingEdit = ui->backingEdit->text();

    //qDebug()<<"快退键已经被修改";
     ui->pushButton_2->setEnabled(true);
}
//声音变大热键修改
void SystemDialog::on_voiceUpEdit_editingFinished()
{
    voiceUpEdit = ui->voiceUpEdit->text();

    //qDebug()<<"增大音量键已经被修改";
     ui->pushButton_2->setEnabled(true);
}
//声音减小热键修改
void SystemDialog::on_voiceDownEdit_editingFinished()
{
    voiceDownEdit = ui->voiceDownEdit->text();

   // qDebug()<<"减小音量键已经被修改";
     ui->pushButton_2->setEnabled(true);
}

void SystemDialog::keyPressEvent(QKeyEvent* event) {

    int key = event->key();
    QString keyText;

    // 处理常见按键名称
    switch (key) {
        case Qt::Key_Escape: keyText = "Esc"; break;
        case Qt::Key_Space: keyText = "Space"; break;
        case Qt::Key_Right: keyText = "Right"; break;
        case Qt::Key_Left: keyText = "Left"; break;
        case Qt::Key_Up: keyText = "Up"; break;
        case Qt::Key_Down: keyText = "Down"; break;
        case Qt::Key_Control: keyText = "Control"; break;
        case Qt::Key_Enter: keyText = "Enter"; break;
        case Qt::Key_End: keyText = "End"; break;
        case Qt::Key_Alt: keyText = "Alt"; break;
        default:
        // 允许普通字符（如字母、数字、符号）正常输入
        event->ignore();
        return;
    }

    event->accept(); // 标记事件为已处理
    //判断此时鼠标的焦点位置
    QWidget *widget = QApplication::focusWidget();
    if (widget) {
        if(widget->objectName() == "exitEdit"){
            ui->exitEdit->setText(keyText);
            exitEdit = ui->exitEdit->text();
        }else if(widget->objectName() == "startEdit"){
            ui->startEdit->setText(keyText);
           startEdit = ui->startEdit->text();
        }else if(widget->objectName() == "speedingEdit"){
            ui->speedingEdit->setText(keyText);
            speedingEdit = ui->speedingEdit->text();
        }else if(widget->objectName() == "backingEdit"){
            ui->backingEdit->setText(keyText);
             backingEdit = ui->backingEdit->text();
        }else if(widget->objectName() == "voiceUpEdit"){
            ui->voiceUpEdit->setText(keyText);
             voiceUpEdit = ui->voiceUpEdit->text();
        }else{
            ui->voiceDownEdit->setText(keyText);
            voiceDownEdit = ui->voiceDownEdit->text();
        }
        //qDebug() << "当前鼠标选中的组件：" << widget->objectName();
    }


}


void SystemDialog::on_pushButton_2_clicked()
{
    settings.setValue("windowMinToBar", iswindowMinToBar);
    settings.setValue("minStopVideo", isminStopVideo);
    settings.setValue("multiPlayerRun", ismultiPlayerRun);
    settings.setValue("closeMainFrame", closeMainFrame);

    settings.setValue("videoOpen", videoOpen);
    settings.setValue("newFileClearList", isnewFileClearList);
    settings.setValue("lastFilePosition", islastFilePosition);
    settings.setValue("showPreview", isshowPreview);
    settings.setValue("highspeedMode", ishighspeedMode);
    settings.setValue("fullScreenInfor", isfullScreenInfor);
    settings.setValue("playProgress", isplayProgress);
    settings.setValue("currentPower", iscurrentPower);
    settings.setValue("systemTime", issystemTime);

    settings.setValue("photoNum", photoNum);
    settings.setValue("photoSaveWays", photoSaveWays);
    settings.setValue("savePhotoPath", savePhotoPath);
    settings.setValue("photoType", photoType);
    settings.setValue("screenshotSameAsView",  isscreenshotSameAsView);

    settings.setValue("sameNameSubtitle", issameNameSubtitle);
    settings.setValue("otherNameSubtitle", isotherNameSubtitle);
    settings.setValue("subtitlePath",subtitlePath);
    settings.setValue("subtitleFontBold",issubtitleFontBold);
    settings.setValue("subtitleFontItalic",issubtitleFontItalic);
    settings.setValue("subtitleFontUnderline",issubtitleFontUnderline);
    settings.setValue("subtitleFont", subtitleFont);
    settings.setValue("subtitleFontSize", subtitleFontSize);
    settings.setValue("subtitleColor",subtitleColor);
    settings.setValue("subtitleTransparency",  subtitleTransparency);

    settings.setValue("voiceOutputDevice", voiceOutputDevice);

    settings.setValue("exitEdit",exitEdit);
    settings.setValue("startEdit",startEdit);
    settings.setValue("speedingEdit", speedingEdit);
    settings.setValue("backingEdit",backingEdit );
    settings.setValue("voiceUpEdit",voiceUpEdit);
    settings.setValue("voiceDownEdit",voiceDownEdit);

    settings.sync();
    //2025-3-3-subtitle
    emit call_apply_setting_Srt();
    ui->pushButton_2->setEnabled(false);
}

// 事件过滤器，确保所有按键事件都能被捕获
bool SystemDialog::eventFilter(QObject* obj, QEvent* event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        int key = keyEvent->key();

        // 检查是否为需要处理的特殊按键
        switch (key) {
        case Qt::Key_Escape:
        case Qt::Key_Space:
        case Qt::Key_Right:
        case Qt::Key_Left:
        case Qt::Key_Up:
        case Qt::Key_Down:
        case Qt::Key_Control:
        case Qt::Key_Enter:
        case Qt::Key_End:
        case Qt::Key_Alt:
            keyPressEvent(keyEvent);
            return keyEvent->isAccepted(); // 根据事件是否被接受决定是否拦截
        default:
            return false; // 允许其他按键事件传递
        }
    }
    return QDialog::eventFilter(obj, event);
}
void SystemDialog::setRow(int selectednum){
    ui->listWidget->setCurrentRow(selectednum);
}

