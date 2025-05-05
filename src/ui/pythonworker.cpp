#include "pythonworker.h"
#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <Python.h>
#include<QTimer>
#include <QDir>

PythonWorker::PythonWorker(QObject *parent) : QObject(parent) {
    m_pythonName="example";
    m_funcName="compute";
    m_paramsList=QStringList();
    m_paramsList.clear();

    m_threadState = PyThreadState_New(PyInterpreterState_Main());
}

PythonWorker::~PythonWorker() {
    PyThreadState_Clear(m_threadState);
    PyThreadState_Delete(m_threadState);
}

void PythonWorker::set_m_allinfo(QString pythonName,QString funcName,QStringList paramsList){
    m_pythonName=pythonName;
    m_funcName=funcName;
    m_paramsList=paramsList;
}


void PythonWorker::execute() {
    PyGILState_STATE gstate = PyGILState_Ensure(); // 获取当前线程的GIL状态（进入Python环境）

    //2025-4-9 thread python path
    QDir dir;
    QString relativePath = "../web/py/"+m_pythonName+".py"; // Qt 中的相对路径
    QString absoluteFilePath = dir.absoluteFilePath(relativePath); // 转换为绝对路径
    QDir moduleDir = QFileInfo(absoluteFilePath).absoluteDir(); // 获取文件所在目录
    QString absoluteDirPath = moduleDir.absolutePath();
    qDebug() << "Module directory:" << absoluteDirPath;
    // 将模块所在目录添加到 sys.path
    PyObject *sysModule = PyImport_ImportModule("sys");
    PyObject *sysPath = PyObject_GetAttrString(sysModule, "path");
    PyObject *pathToAdd = PyUnicode_FromString(absoluteDirPath.toUtf8().constData());
    PyList_Append(sysPath, pathToAdd);
    // 清理临时对象
    Py_DECREF(pathToAdd);
    Py_DECREF(sysPath);
    Py_DECREF(sysModule);


    PyObject *pModule = PyImport_ImportModule(m_pythonName.toUtf8().constData()); // 导入Python模块（相当于Python中的import example）
    if (!pModule) {
        PyErr_Print();
        qFatal("Failed to import module");
    }
    PyObject *pFunc = PyObject_GetAttrString(pModule, m_funcName.toUtf8().constData()); // 获取模块中的函数对象（相当于获取example.compute）



    //2025-4-9 thread python
    PyObject *pResult = nullptr;
    if (m_paramsList.isEmpty()) {
        // 无参情况
        pResult = PyObject_CallObject(pFunc, nullptr);// 调用无参Python函数（执行compute()）
    } else {
        // 多参数情况
        int numArgs = m_paramsList.size();
        PyObject *pArgs = PyTuple_New(numArgs); // 创建参数元组
        // 填充参数
        for (int i = 0; i < numArgs; ++i) {
            // 将 QString 转换为 Python Unicode 字符串
            PyObject *pArg = PyUnicode_FromString(m_paramsList[i].toUtf8().constData());
            if (!pArg) {
                PyErr_Print();
                Py_DECREF(pArgs);
                return;
            }
            PyTuple_SetItem(pArgs, i, pArg); // 设置参数，PyTuple_SetItem 会窃取引用
        }
        // 调用函数
        pResult = PyObject_CallObject(pFunc, pArgs);
        // 释放参数元组
        Py_DECREF(pArgs);
    }



    /*
    long result = PyLong_AsLong(pResult); // 将Python返回值转换为C++ long类型
    qDebug() << "Python result:" << result;
    emit finished(result);
    */
    qDebug() << "Python "<<m_pythonName<<m_funcName<<m_paramsList<<" Finished !";
    emit finished(m_pythonName,m_funcName,m_paramsList);


    Py_XDECREF(pResult); // 清理
    Py_XDECREF(pFunc);
    Py_XDECREF(pModule);
    PyGILState_Release(gstate); // 释放当前线程的GIL状态（退出Python环境）
}
