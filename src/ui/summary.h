#ifndef SUMMARY_H
#define SUMMARY_H

#include <QDialog>
#include <QJsonObject>
#include <QSet>
#include<QString>
#include <QListWidgetItem>
#include<QDebug>
namespace Ui {
class Summary;
}

class Summary : public QDialog
{
    Q_OBJECT

public:
    QSet<QString> m_user_like = {
        "NAVI",
        "电子竞技",
        "CS",
        "李渊",
        "孤岛惊魂",
        "美食制作",
        "大学生",
        "就业",
        "原创",
        "鬼泣",
        "belike",
        "荒野",
        "FPS",
        "娱乐",
        "校园"
    };
    QSet<QString> m_user_dislike = {
        "NAVI",
        "电子竞技",
        "CS",
        "李渊",
        "孤岛惊魂",
        "美食制作",
        "大学生",
        "就业",
        "原创",
        "鬼泣",
        "belike",
        "荒野",
        "FPS",
        "娱乐",
        "校园"
    };
    explicit Summary(QWidget *parent = nullptr);
    ~Summary();

private slots:
    void on_first_clicked();
    void on_second_clicked();
    void on_third_clicked();
    void addRow();
    void editRow(int row);
    void deleteRow(int row);
//    void on_addButton_clicked(); // 添加按钮点击事件
    void on_like_itemClicked(QListWidgetItem *item); // 卡片点击事件

    void on_addButton_2_clicked();    //添加喜好词

    void on_dislike_itemClicked(QListWidgetItem *item); // dislike 卡片点击事件

    void on_addButton_3_clicked();    //添加屏蔽词

    void on_checkBox1_stateChanged(int state); // checkBox1 状态改变
    void on_checkBox2_stateChanged(int state); // checkBox2 状态改变
    void on_checkBox3_stateChanged(int state); // checkBox3 状态改变

private:
    Ui::Summary *ui;
    void loadTableData(); // 加载表格数据
    void saveTableData(); // 保存表格数据
    void updateLikeDisplay(); // 更新 like 显示
    void updateDislikeDisplay(); // 更新 dislike 显示

    QString selectedCheckBox; // 保存当前选中的 checkBox
    void loadCheckBoxState(); // 加载 checkBox 选择状态
    void saveCheckBoxState(); // 保存 checkBox 选择状态
    void updateCheckBoxState(QString selected); // 更新 checkBox 互斥状态

};

#endif // SUMMARY_H
