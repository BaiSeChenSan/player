#ifndef PYTHONWORKER_H
#define PYTHONWORKER_H
#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <Python.h>

#include<QTimer>


class PythonWorker : public QObject {
    Q_OBJECT
public:
    ~PythonWorker();

    QString m_pythonName;
    QString m_funcName;
    QStringList m_paramsList;
    PyThreadState* m_threadState;
    explicit PythonWorker(QObject *parent = nullptr);
    void set_m_allinfo(QString,QString,QStringList);
public slots:
    void execute();

signals:

    void finished(QString,QString,QStringList);

};
#endif // PYTHONWORKER_H
