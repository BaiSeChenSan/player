#ifndef DIALOG_H
#define DIALOG_H


#include <QListWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QDateTime>
#include <QTextBrowser>
#include <QLabel>
#include <QMovie>
#include <QTimer>
#include <QPropertyAnimation>
#include <QScrollBar>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QProcess>
#include <QCoreApplication>
//#include <Python.h>
#include <QProcess>
#include <QToolTip>
#include <QSystemTrayIcon>
#include <QNetworkAccessManager>
#include <QByteArray>
#include <QBuffer>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

#undef slots


#define slots Q_SLOTS
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;

    QNetworkAccessManager *networkManager;  // 声明 QNetworkAccessManager

    QSslConfiguration sslConfig;
    void initPlaylist(QVBoxLayout *layout);

    void triggerVisualFeedback();

    void updateAnalysisDisplay(const QString &videoName);

    QString parseAiResponse(const QByteArray &response);
    QProcess* m_pythonProcess; // 保持进程对象生命周期
    QHash<QProcess*, QDateTime> m_processTimestamps;  // 时间戳管理
    void appendMessage(const QString message, QString type);
    QNetworkAccessManager *manager;
    QByteArray gifData;
    QBuffer *buffer;


};

#endif // DIALOG_H
