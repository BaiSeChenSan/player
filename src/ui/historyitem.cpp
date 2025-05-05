#include "historyitem.h"

HistoryItem::HistoryItem(int type,const QString &fileName, const QString &duration,  QListWidget *parentList, QListWidgetItem *listItem,QString Path,bool isliked,bool isUnliked)
    : QWidget(parentList), m_type(type),m_duration(duration),isLiked(isliked), isUnliked(isUnliked),listWidget(parentList), item(listItem),filePath(Path),fileName(fileName) {


    QLabel *imageLabel = new QLabel();
    QPixmap pixmap;

    qDebug()<<Path;
    if(type==2){
        if(Path[0]=='.'){
            QString path = Path;
            qDebug()<<"syxsyxsyx\n\n\n\n\n\n";
            int dotIndex = path.lastIndexOf('.');
            if (dotIndex != -1) {
                QString newpath = path.left(dotIndex) + ".jpg";
                qDebug()<<newpath;
                pixmap.load(newpath);
            }
            else{
                qDebug()<<"syxsyxsyx\n\n\n\n\n\n";
                pixmap.load(":/new/prefix1/icons/default.png");
            }
        }
        else pixmap.load(":/new/prefix1/icons/default.png");
    }
    else{
        QString path_jpg=Path+fileName+".jpg";
        QDir pa=QDir(path_jpg);
        QString srtFile =  pa.absolutePath();
        bool check_load =  pixmap.load(path_jpg);
        if(!check_load) pixmap.load(":/new/prefix1/icons/default.png");
    }

//    if(duration=="本地视频")
//    {
//        pixmap.load(":/new/prefix1/icons/default.png");
//    }else{
//        QString path_jpg=Path+fileName+".jpg";
//        QDir pa=QDir(path_jpg);
//        QString srtFile =  pa.absolutePath();
//        qDebug()<<"abspath:"<<srtFile;
//        pixmap.load(path_jpg);
//    }


    int imgWidth = (listWidget->width())/20 * 9;
    int imgHeight = 100;
    //对图片进行截图四角
    QPixmap roundedPixmap = createRoundedPixmap(pixmap.scaled(imgWidth, imgHeight, Qt::KeepAspectRatioByExpanding), 10);

    imageLabel->setPixmap(roundedPixmap);
    imageLabel->setFixedSize(imgWidth, imgHeight);
    imageLabel->setStyleSheet("QLabel{border-radius:26px; background:transparent;}");
    imageLabel->setScaledContents(true);
    // 右侧文字部分
    QString fn=fileName;
    QFileInfo fi=QFileInfo(fn);
    if(m_type==0){fn=fi.fileName();}
    fileLabel  = new QLabel(fn, this);
    durationLabel = new QLabel(duration, this);
    durationLabel->setWordWrap(true);

    fileLabel->setAlignment(Qt::AlignLeft);  // 文字靠左对齐
    fileLabel->setWordWrap(true); // 允许换行
    fileLabel->setMinimumWidth(180);
    fileLabel->setFixedHeight(58);
    fileLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    // 样式表调整
    fileLabel->setStyleSheet(
        "QLabel {"
        "background: transparent;"
        "margin-top: 12px;"
        "font-size: 20px;"
        "color: black;"
        "qproperty-alignment: AlignLeft;"   // 左对齐
        "}"
    );


    durationLabel->setStyleSheet("QLabel {"
                                 "   background: transparent;"    // 透明背景
                                 "   color: #888888;"         // 灰色文字
                                 "   margin-top: 3px;"
                                 "margin-left:2px;"
                                 "}");


    //这个地方初始化应该从后端取数据来渲染，对于histryitem的构造函数需要一定的改动
    //isLiked = false;
    //isUnliked = false;
    isDownLoad = false;
    isAdd = false;

    qDebug()<<"in historyitem init() , islike = "<<isLiked;
    if(isLiked){
        likeIcon.load(":/new/prefix1/icons/like.svg");
    }else{
        likeIcon.load(":/new/prefix1/icons/initLike.svg");
    }
    if(isUnliked){
        unlikeIcon.load(":/new/prefix1/icons/unlike.svg");
    }else{
         unlikeIcon.load(":/new/prefix1/icons/initUnlike.svg");
    }
    if(isDownLoad){
       downLoadIcon.load(":/new/prefix1/icons/finish.svg");
    }else{
        downLoadIcon.load(":/new/prefix1/icons/downLoad.svg");
    }
    if(isAdd ){
       addIcon.load(":/new/prefix1/icons/add.svg");
    }else{
        addIcon.load(":/new/prefix1/icons/initAdd.svg");
    }
    aiIcon.load(":/new/prefix1/icons/ai.svg");
    aiButton = new QPushButton("", this);
    aiButton->setIcon(aiIcon);
    aiButton->setFixedSize(26,26);
    aiButton->setVisible(false); // 默认隐藏
    aiButton->setStyleSheet("QPushButton {border:none; background: transparent;margin-bottom:3px;}");

    closeIcon.load(":/new/prefix1/icons/close.svg");
    closeButton = new QPushButton("", this);
    closeButton->setIcon(closeIcon);
    closeButton->setFixedSize(26, 26);
    closeButton->setVisible(false); // 默认隐藏
    closeButton->setStyleSheet("QPushButton {border:none; background: transparent;margin-bottom:3px;}");

    likeButton = new QPushButton("", this);
    likeButton ->setIcon(likeIcon);
    likeButton ->setFixedSize(26, 26);
    likeButton ->setVisible(false); // 默认隐藏
    likeButton ->setStyleSheet("QPushButton {border:none; background: transparent;margin-bottom:3px;}");

    unlikeButton = new QPushButton("", this);
    unlikeButton->setIcon(unlikeIcon);
    unlikeButton->setFixedSize(26, 26);
    unlikeButton->setVisible(false); // 默认隐藏
    unlikeButton->setStyleSheet("QPushButton {border:none; background: transparent;margin-bottom:3px;}");

    addButton = new QPushButton("", this);
    addButton->setIcon(addIcon);
    addButton->setFixedSize(26, 26);
    addButton->setVisible(false); // 默认隐藏
    addButton->setStyleSheet("QPushButton {border:none; background: transparent;margin-bottom:3px;}");

    downLoadButton = new QPushButton("", this);
    downLoadButton->setIcon(downLoadIcon);
    downLoadButton->setFixedSize(26, 26);
    downLoadButton->setVisible(false); // 默认隐藏
    downLoadButton->setStyleSheet("QPushButton {border:none; background: transparent;margin-bottom:3px;}");
    // 文字布局

    QVBoxLayout *textLayout = new QVBoxLayout();
    textLayout->addWidget(fileLabel, 0, Qt::AlignLeft | Qt::AlignTop); // 左上对齐
    textLayout->addWidget(durationLabel, 0, Qt::AlignLeft | Qt::AlignTop); // 固定在下方
    textLayout->setSpacing(5);           // 调整间距

    textLayout->addStretch();
    downLoadButton->setToolTip("下载");
    likeButton->setToolTip("点赞");
    unlikeButton->setToolTip("踩");
    aiButton->setToolTip("AI");
    closeButton->setToolTip("删除");
    addButton->setToolTip("添加到播放队列");

    downLoadButton->setCursor(Qt::PointingHandCursor);
    likeButton->setCursor(Qt::PointingHandCursor);
    unlikeButton->setCursor(Qt::PointingHandCursor);
    aiButton->setCursor(Qt::PointingHandCursor);
    closeButton->setCursor(Qt::PointingHandCursor);
    addButton->setCursor(Qt::PointingHandCursor);

    // 创建水平布局，使 aiButton 和 closeButton 在同一行

    //m_type 值分别为0、1、2依次代表播放列表，推荐列表、历史记录
    //对于播放列表中item只需要删除和ai按钮即可
    //对于播放历史记录中只需要有删除和ai
    //对于个性推荐中有点赞、踩、下载、添加播放、ai

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    if(m_type==0){
        buttonLayout->addWidget(aiButton, 5, Qt::AlignRight);
        buttonLayout->addWidget(closeButton, 1, Qt::AlignRight);
        buttonLayout->setContentsMargins(0, 0, 0, 0);
    }else if(m_type==1){
        qDebug()<<"item type:"<<m_type;

        buttonLayout->addWidget(likeButton, 1, Qt::AlignCenter);
        buttonLayout->addWidget(unlikeButton, 1, Qt::AlignCenter);
        buttonLayout->addWidget(downLoadButton, 1, Qt::AlignCenter);
        buttonLayout->addWidget(aiButton, 1, Qt::AlignCenter);
        buttonLayout->addWidget(addButton, 1, Qt::AlignCenter);
        buttonLayout->setContentsMargins(0, 0, 0, 0);

    }else{

        buttonLayout->addWidget(aiButton, 17, Qt::AlignRight);
        //buttonLayout->addWidget(addButton, 5, Qt::AlignRight);
        buttonLayout->addWidget(closeButton, 1, Qt::AlignRight);
        buttonLayout->setContentsMargins(0, 0, 0, 0);
    }

     // 右侧整体布局（文字 + 按钮）
    QVBoxLayout *rightLayout = new QVBoxLayout();
    rightLayout->addLayout(textLayout);
    rightLayout->addLayout(buttonLayout);

    // 总体横向布局
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(imageLabel);
    mainLayout->addLayout(rightLayout);
    mainLayout->setSpacing(10); // 调整间距
    mainLayout->setContentsMargins(10, 10, 10, 5);

    setLayout(mainLayout);
    listItem->setSizeHint(QSize(listWidget->width(),140));

    setStyleSheet(
            "HistoryItem {"
            "   background: #282828; border-radius: 10px; padding: 5px;"
            "   color: white; font-size: 14px;"
            "}"
            "HistoryItem:hover { background: #3a3a3a; }"
        );

    // 绑定删除按钮事件
    connect(closeButton, &QPushButton::clicked, this, &HistoryItem::removeItem);
    //绑定ai按钮事件
    connect(aiButton, &QPushButton::clicked, this, &HistoryItem::changeToAi);
    //绑定点赞事件
    connect(likeButton, &QPushButton::clicked, this, &HistoryItem::like);
    //绑定踩的事件
    connect(unlikeButton, &QPushButton::clicked, this, &HistoryItem::unlike);
    //绑定下载事件
    connect(downLoadButton, &QPushButton::clicked, this, &HistoryItem::download);
    //绑定添加播放队列事件
    connect(addButton,&QPushButton::clicked, this, &HistoryItem::addTolist);

    if(m_type==1){
        QString path_jpg=Path+fileName+".mp4";
        QDir pa=QDir(path_jpg);
        QString srtFile =  pa.absolutePath();
        qDebug()<<"in history item : rcmdvideo's abspath:"<<srtFile;
        if(QFile::exists(srtFile)){
            downloadfinished(fileName);
        }
    }
}

// 析构函数
HistoryItem::~HistoryItem() {

}
// 鼠标悬停时显示删除按钮
void HistoryItem::enterEvent(QEvent *event) {
    if(m_type == 0 ){
        closeButton->setVisible(true);
        aiButton->setVisible(true);
    }else if (m_type ==1){

        addButton->setVisible(true);
        aiButton->setVisible(true);
        likeButton->setVisible(true);
        unlikeButton->setVisible(true);
        downLoadButton->setVisible(true);
    }else{
        addButton->setVisible(false);
        aiButton->setVisible(true);
        closeButton->setVisible(true);
    }

    QWidget::enterEvent(event);
}
void HistoryItem::m_highlightWords(QStringList words){
    for(auto word : words){

        QString text = fileLabel->text();

        // 创建正则表达式（示例匹配关键词）
        QRegExp valueRegExp(QString("(%1)").arg(word));
        valueRegExp.setCaseSensitivity(Qt::CaseInsensitive);

        // 设置强调样式（基于原有样式调整）
        QString highlightStyle = QString(
            "<font style="
            "'font-size:18px;"  // 原20px -> 18px
            "background-color:rgba(255,245,215,0.7);"  // 浅米黄
            "color:#D35400;"  // 暖橙色
            "font-weight:600;"
            "padding:1px 3px;"
            "border-radius:3px;'"
            ">\\1</font>"
        );

        // 执行替换
        fileLabel->setText(text.replace(valueRegExp, highlightStyle));

        //QRegExp valueRegExp(QString("(%1)").arg(word));
        //valueRegExp.setCaseSensitivity(Qt::CaseInsensitive);
        //fileLabel->setText(fileLabel->text().replace(valueRegExp, "<font style='font-size:16px; background-color:white; color:blue;'>\\1</font>"));
    }
}



// 鼠标移出时隐藏删除按钮
void HistoryItem::leaveEvent(QEvent *event) {

    if(m_type == 0 ){
        closeButton->setVisible(false);
        aiButton->setVisible(false);
    }else if (m_type ==1){
        addButton->setVisible(false);
        aiButton->setVisible(false);
        likeButton->setVisible(false);
        unlikeButton->setVisible(false);
        downLoadButton->setVisible(false);
    }else{
        addButton->setVisible(false);
        aiButton->setVisible(false);
        closeButton->setVisible(false);
    }
    QWidget::leaveEvent(event);
}
//鼠标点击事件，此事件是为了播放功能
void HistoryItem::mousePressEvent(QMouseEvent *event) {
    if (closeButton->geometry().contains(event->pos())||aiButton->geometry().contains(event->pos())||likeButton->geometry().contains(event->pos())
            ||unlikeButton->geometry().contains(event->pos())||downLoadButton->geometry().contains(event->pos())||addButton->geometry().contains(event->pos())) {
        return;  // 如果点到了 `closeButton`，不触发 `itemClicked`还有喜欢和不喜欢等
    }
    //实际播放的时候改成url即可
    QString filename = filePath;

    listWidget->setCurrentItem(item);
    QWidget::mousePressEvent(event);
    emit itemClicked(filename);
}
//响应点击删除按钮的槽函数
void HistoryItem::removeItem() {
    //此时感觉也应该回传选中的视频的url
    //此时也感觉可以同步删除播放队列中的
    delete listWidget->takeItem(listWidget->row(item));
}

//相应相应点击ai图标的槽函数
void HistoryItem::changeToAi(){
   // QString filename = fileLabel->text();
    //在实际中应该回传的是选中视频的url
    emit aiItemclicked(filePath);
}
void HistoryItem::like(){
    qDebug()<<"int historyitem with name "<<fileName<<"islike = "<<isLiked;
    isLiked = !isLiked;
    //对图标进行重新加载
    //这个暂时只是对图标判断进行处理，但加载的图片还没有渲染上去
    if(isLiked){
        //只有当用户喜欢的时候强制修改不喜欢为false
        likeIcon.load(":/new/prefix1/icons/like.svg");
        isUnliked = false;
        unlikeIcon.load(":/new/prefix1/icons/initUnlike.svg");
        unlikeButton->setIcon(unlikeIcon);
        unlikeButton->update();
    }else{
        likeIcon.load(":/new/prefix1/icons/initLike.svg");
    }
//    qDebug()<<"此时的喜欢和不喜欢分别是"<<isLiked<<" "<<isUnliked;
    // 确保 QPushButton 图标更新
    likeButton->setIcon(likeIcon);
    likeButton->update();  // 强制 UI 重新绘制
    //发送信号
    qDebug()<<"int historyitem with name "<<fileName<<"islike = "<<isLiked;

    emit likeItemClicked(fileName,isLiked,isUnliked);
}
void HistoryItem::unlike(){
    isUnliked = !isUnliked;
    if(isUnliked){
        //只有当用户不喜欢的时候强制修改喜欢为false
        unlikeIcon.load(":/new/prefix1/icons/unlike.svg");
        isLiked = false;
        likeIcon.load(":/new/prefix1/icons/initLike.svg");
        likeButton->setIcon(likeIcon);
        likeButton->update();  // 强制 UI 重新绘制

    }else{
         unlikeIcon.load(":/new/prefix1/icons/initUnlike.svg");
    }
//    qDebug()<<"此时的喜欢和不喜欢分别是"<<isLiked<<" "<<isUnliked;
    unlikeButton->setIcon(unlikeIcon);
    unlikeButton->update();

    //发送信号
    emit unlikeItemClicked(fileName,isLiked,isUnliked);
}

void HistoryItem::download(){
    if(!isDownLoad){
        //对于没有下载的应用，发送信号才有意义
        emit downloadClicked(fileName,isDownLoad);
    }
}

void HistoryItem::downloadfinished(QString filename){
    if(filename==this->fileName){
        isDownLoad = true;

        downLoadIcon.load(":/new/prefix1/icons/finish.svg");

        downLoadButton->setIcon(downLoadIcon);
        downLoadButton->update();
    }
}

void HistoryItem::addTolist(){
    if(!isAdd){
        isAdd = !isAdd;
        addIcon.load(":/new/prefix1/icons/add.svg");

        addButton->setIcon(addIcon);
        addButton->update();

        //发送添加到播放队列中
        emit addToList(fileName,m_duration);
    }
}
// 创建圆角图片的函数
QPixmap HistoryItem::createRoundedPixmap(const QPixmap &src, int radius) {
    if (src.isNull()) return QPixmap();

    QPixmap rounded(src.size());
    rounded.fill(Qt::transparent);

    QPainter painter(&rounded);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 创建圆角矩形路径并裁剪
    QPainterPath path;
    path.addRoundedRect(QRectF(0, 0, src.width(), src.height()), radius, radius);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, src);

    return rounded;
}
