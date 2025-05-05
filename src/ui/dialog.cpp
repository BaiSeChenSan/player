#include "dialog.h"
#include "ui_dialog.h"
#include <QSystemTrayIcon>
#undef slots
#define slots Q_SLOTS
#undef slots
#define slots Q_SLOTS


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QPixmap pixmap(":/new/prefix1/icons/no1.ico");
    QIcon icon(pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    //动图gif
    QMovie *movie = new QMovie(":/new/prefix1/icons/ai.gif");
    movie->setCacheMode(QMovie::CacheAll); // 预加载提升性能
    ui->gifLabel->setMovie(movie);
    movie->start();




    this->setWindowTitle("Lumos视频分析助手");
    networkManager = new QNetworkAccessManager(this);
    m_pythonProcess = new QProcess(this);



}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog:: appendMessage(const QString message, QString type)
{
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    // 根据消息类型设置不同的样式
       if (type == "info") {
           QString icon = "✅";  // 信息图标
           ui->textEdit->appendPlainText(QString("%1 处理完成\n").arg(icon));
           ui->textEdit->appendPlainText(QString("[%1] 分析结果：%2").arg(timestamp).arg(message));
           ui->textEdit->appendPlainText("\n");  // 额外的换行
       } else if (type == "error") {
           QString icon = "❌";  // 信息图标
           ui->textEdit->appendPlainText(QString("[%1] 脚本异常\n").arg(icon));
           ui->textEdit->appendPlainText(QString("[%1] 分析结果：%2").arg(timestamp).arg(message));
           ui->textEdit->appendPlainText("\n");  // 额外的换行
       } else if (type == "loading") {
           QString icon = "🔄";  // 信息图标
           ui->textEdit->appendPlainText(QString("%1 %2\n").arg(icon).arg(message));
       }else
       {
           QString icon = "🚀";  // 信息图标
           ui->textEdit->appendPlainText(QString("%1 [%2] 分析启动：%3").arg(icon).arg(timestamp).arg(message));
           ui->textEdit->appendPlainText("\n");  // 额外的换行
       }

}


void Dialog::on_pushButton_clicked()
{
    QPushButton* triggerBtn = qobject_cast<QPushButton*>(sender());
    QString buttonText = triggerBtn->text();

    QString videoFilePath = "D:/fk2.mp4";  // 你要分析的 MP4 文件路径

    appendMessage(videoFilePath,"get");

    // 绝对路径
    QString pythonPath = "E:/Anaconda/envs/py38/python.exe";
    QString scriptPath1 = "E:/main/mediaplayer-main/src/Detail-analyse.py";
    QString scriptPath2 = "E:/main/mediaplayer-main/src/Quick-analyse.py";

//========================================================================================//

    // 创建进程2（先运行）
    QProcess* process2 = new QProcess(this);
    m_processTimestamps.insert(process2, QDateTime::currentDateTime());
    QProcessEnvironment env2 = QProcessEnvironment::systemEnvironment();
    env2.insert("PATH", "E:/Anaconda/envs/py38/Library/bin;" + env2.value("PATH"));
    env2.insert("PYTHONPATH", "E:/Anaconda/envs/py38"); // 添加 Python 环境路径
    process2->setProcessEnvironment(env2);

    // 监听进程2标准输出
    connect(process2, &QProcess::readyReadStandardOutput, [=](){
        QString output = QString::fromUtf8(process2->readAllStandardOutput()).trimmed();
        ui->textEdit->insertPlainText(QString("%1").arg(output));
        ui->textEdit->moveCursor(QTextCursor::End); // 滚动到底部
    });

    // 监听进程2错误输出
    connect(process2, &QProcess::readyReadStandardError, [=](){
        QString errorOutput = QString::fromUtf8(process2->readAllStandardError()).trimmed();
        ui->textEdit->appendPlainText("[进程2错误] " + errorOutput);
        qDebug() << "[进程2错误] " << errorOutput;  // 调试信息
    });

    // 监听进程2结束，完成后再启动 process1
    connect(process2, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
        this, [=](int exitCode, QProcess::ExitStatus exitStatus){
            QDateTime startTime = m_processTimestamps.value(process2);
            QString duration = QString::number(startTime.msecsTo(QDateTime::currentDateTime())) + "ms";

            if (exitStatus == QProcess::NormalExit) {
                //ui->textEdit->appendPlainText(QString("进程2完成，耗时：%1\n").arg(duration));
            } else {
                ui->textEdit->appendPlainText(QString("[错误] 进程2异常终止（代码：%1）").arg(exitCode));
            }

            process2->deleteLater();
            m_processTimestamps.remove(process2);

            // `process2` 完成后，启动 `process1`
            QProcess* process1 = new QProcess(this);
            m_processTimestamps.insert(process1, QDateTime::currentDateTime());
            QProcessEnvironment env1 = QProcessEnvironment::systemEnvironment();
            env1.insert("PATH", "E:/Anaconda/envs/py38/Library/bin;" + env1.value("PATH"));
            process1->setProcessEnvironment(env1);

            // 监听标准输出
            connect(process1, &QProcess::readyReadStandardOutput, [=](){
                QString output = QString::fromUtf8(process1->readAllStandardOutput()).trimmed();
                ui->textEdit->insertPlainText(QString("%1").arg(output));
                ui->textEdit->moveCursor(QTextCursor::End);
            });

            // 监听进程1结束
            connect(process1, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
                this, [=](int exitCode, QProcess::ExitStatus exitStatus){
                    QDateTime startTime = m_processTimestamps.value(process1);
                    QString duration = QString::number(startTime.msecsTo(QDateTime::currentDateTime())) + "ms";

                    if (exitStatus == QProcess::NormalExit) {
                        //ui->textEdit->appendPlainText(QString("进程1完成，耗时：%1\n").arg(duration));
                    } else {
                        ui->textEdit->appendPlainText(QString("[错误] 进程1异常终止（代码：%1）").arg(exitCode));
                    }

                    process1->deleteLater();
                    m_processTimestamps.remove(process1);
                });

            // 启动进程1
            process1->start(pythonPath, QStringList() << scriptPath1 << videoFilePath);
            if (!process1->waitForStarted()) {
                ui->textEdit->appendPlainText("[错误] 进程1未成功启动！");
            }
        });

    // 启动进程2
    process2->start(pythonPath, QStringList() << scriptPath2 << videoFilePath);
    if (!process2->waitForStarted()) {
        ui->textEdit->appendPlainText("[错误] 进程2未成功启动！");
    }
}







