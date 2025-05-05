#include "summary.h"
#include "ui_summary.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QHeaderView>
#include <QListWidgetItem>
#include <QDebug>
#include <QJsonObject>

Summary::Summary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Summary)
{
    ui->setupUi(this);

    // 初始化表格
    ui->tableWidget->clear(); // 清空所有内容
    ui->tableWidget->setColumnCount(3); // 固定 3 列
    ui->tableWidget->setHorizontalHeaderLabels({"时段", "要求", "操作"});
    ui->tableWidget->setRowCount(0); // 确保行数为 0
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 设置表头撑满表格
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 美化表格样式
    ui->tableWidget->setStyleSheet(
        "QTableWidget {"
        "    border: 1px solid #dcdcdc;"
        "    gridline-color: #dcdcdc;"
        "    selection-background-color: #e6f3ff;"
        "}"
        "QHeaderView::section {"
        "    background-color: #f5f5f5;"
        "    border: 1px solid #dcdcdc;"
        "    padding: 4px;"
        "    font-weight: bold;"
        "}"
        "QPushButton {"
        "    background-color: #007bff;"
        "    color: white;"
        "    border-radius: 3px;"
        "    padding: 4px 8px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #0056b3;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #004085;"
        "}"
    );

    // 加载保存的数据
    loadTableData();

    // 设置 like 和 dislike 为横向排列
    ui->like->setFlow(QListView::LeftToRight); // 从左到右排列
    ui->like->setWrapping(true); // 启用自动换行
    ui->like->setResizeMode(QListView::Adjust); // 自动调整大小

    ui->dislike->setFlow(QListView::LeftToRight); // 从左到右排列
    ui->dislike->setWrapping(true); // 启用自动换行
    ui->dislike->setResizeMode(QListView::Adjust); // 自动调整大小

    // 配置 addLike 去掉增加减少按键
    ui->addLike->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 禁用垂直滚动条
    ui->addLike->setFixedHeight(50); // 固定高度

    // 美化样式

    // like 和 dislike 的样式
    ui->like->setStyleSheet(
        "QListWidget {"
        "    border: 1px solid #dcdcdc;"
        "    border-radius: 5px;"
        "    background-color: #f9f9f9;"
        "    padding: 5px;"
        "}"
        "QListWidget::item {"
        "    background-color: #e6f3ff;"
        "    border: 1px solid #dcdcdc;"
        "    border-radius: 5px;"
        "    padding: 5px;"
        "    margin: 3px;"
        "    min-width: 80px;"
        "    max-width: 120px;"
        "    min-height: 30px;"
        "}"
        "QListWidget::item:hover {"
        "    background-color: #d6eaff;"
        "}"
        "QListWidget::item:selected {"
        "    background-color: #c0dfff;"
        "}"
    );

    ui->dislike->setStyleSheet(
        "QListWidget {"
        "    border: 1px solid #dcdcdc;"
        "    border-radius: 5px;"
        "    background-color: #f9f9f9;"
        "    padding: 5px;"
        "}"
        "QListWidget::item {"
        "    background-color: #ffe6e6;"
        "    border: 1px solid #dcdcdc;"
        "    border-radius: 5px;"
        "    padding: 5px;"
        "    margin: 3px;"
        "    min-width: 80px;"
        "    max-width: 120px;"
        "    min-height: 30px;"
        "}"
        "QListWidget::item:hover {"
        "    background-color: #ffd6d6;"
        "}"
        "QListWidget::item:selected {"
        "    background-color: #ffc0c0;"
        "}"
    );

    // addButton、addButton_2 和 addDislike 的样式
    ui->addButton_3->setStyleSheet(
        "QPushButton {"
        "    background-color: #007bff;"
        "    color: white;"
        "    border-radius: 5px;"
        "    padding: 5px 10px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #0056b3;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #004085;"
        "}"
    );

    ui->addButton_2->setStyleSheet(
        "QPushButton {"
        "    background-color: #28a745;"
        "    color: white;"
        "    border-radius: 5px;"
        "    padding: 5px 10px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #218838;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #1e7e34;"
        "}"
    );

    // 美化 checkBox 样式
    ui->checkBox1->setStyleSheet(
        "QCheckBox {"
        "    spacing: 5px;"
        "}"
        "QCheckBox::indicator {"
        "    width: 18px;"
        "    height: 18px;"
        "}"
    );
    ui->checkBox2->setStyleSheet(
        "QCheckBox {"
        "    spacing: 5px;"
        "}"
        "QCheckBox::indicator {"
        "    width: 18px;"
        "    height: 18px;"
        "}"
    );
    ui->checkBox3->setStyleSheet(
        "QCheckBox {"
        "    spacing: 5px;"
        "}"
        "QCheckBox::indicator {"
        "    width: 18px;"
        "    height: 18px;"
        "}"
    );

    // 初始化 like 和 dislike 显示
    updateLikeDisplay();
    updateDislikeDisplay();

    // 连接添加按钮
    connect(ui->addButton, &QPushButton::clicked, this, &Summary::addRow);

    // 加载 checkBox 状态
    loadCheckBoxState();
}

Summary::~Summary()
{
    saveTableData(); // 退出时保存表格数据
    saveCheckBoxState(); // 退出时保存 checkBox 状态
    delete ui;
}

void Summary::on_first_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Summary::on_second_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Summary::on_third_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

// 自定义对话框，用于同时输入时段和要求
void Summary::addRow()
{
    QDialog dialog(this);
    dialog.setWindowTitle("添加记录");
    dialog.setStyleSheet(
        "QDialog { background-color: #ffffff; }"
        "QLineEdit { border: 1px solid #dcdcdc; padding: 4px; }"
        "QLabel { font-weight: bold; }"
    );

    QFormLayout form(&dialog);
    QLineEdit *periodEdit = new QLineEdit;
    QLineEdit *requirementEdit = new QLineEdit;
    form.addRow("时段:", periodEdit);
    form.addRow("要求:", requirementEdit);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        QString period = periodEdit->text().trimmed();
        QString requirement = requirementEdit->text().trimmed();
        if (period.isEmpty() || requirement.isEmpty()) {
            QMessageBox::warning(this, "输入错误", "时段和要求不能为空！");
            return;
        }

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        // 设置时段和要求
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(period)); // 时段
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(requirement)); // 要求

        // 操作列添加编辑和删除按钮
        QWidget *widget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(widget);
        QPushButton *editButton = new QPushButton("编辑");
        QPushButton *deleteButton = new QPushButton("删除");
        layout->addWidget(editButton);
        layout->addWidget(deleteButton);
        layout->setContentsMargins(0, 0, 0, 0);
        ui->tableWidget->setCellWidget(row, 2, widget); // 操作

        // 连接按钮信号
        connect(editButton, &QPushButton::clicked, this, [=]() { editRow(row); });
        connect(deleteButton, &QPushButton::clicked, this, [=]() { deleteRow(row); });

        saveTableData(); // 保存数据
    }
}

// 编辑一行
void Summary::editRow(int row)
{
    QDialog dialog(this);
    dialog.setWindowTitle("编辑记录");
    dialog.setStyleSheet(
        "QDialog { background-color: #ffffff; }"
        "QLineEdit { border: 1px solid #dcdcdc; padding: 4px; }"
        "QLabel { font-weight: bold; }"
    );

    QFormLayout form(&dialog);
    QLineEdit *periodEdit = new QLineEdit(ui->tableWidget->item(row, 0)->text());
    QLineEdit *requirementEdit = new QLineEdit(ui->tableWidget->item(row, 1)->text());
    form.addRow("时段:", periodEdit);
    form.addRow("要求:", requirementEdit);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        QString period = periodEdit->text().trimmed();
        QString requirement = requirementEdit->text().trimmed();
        if (period.isEmpty() || requirement.isEmpty()) {
            QMessageBox::warning(this, "输入错误", "时段和要求不能为空！");
            return;
        }

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(period));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(requirement));

        saveTableData(); // 保存数据
    }
}

// 删除一行
void Summary::deleteRow(int row)
{
    if (QMessageBox::question(this, "确认删除", "确定删除该行？") == QMessageBox::Yes) {
        ui->tableWidget->removeRow(row);
        saveTableData(); // 保存数据
    }
}

// 加载表格数据
void Summary::loadTableData()
{
    // 清空表格内容，但保留列结构
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"时段", "要求", "操作"});
    ui->tableWidget->setRowCount(0);

    QFile file("table_data.json");
    if (!file.open(QIODevice::ReadOnly)) return;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonArray array = doc.array();
    for (const QJsonValue &value : array) {
        QJsonObject obj = value.toObject();
        QString period = obj["period"].toString();
        QString requirement = obj["requirement"].toString();

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        // 设置时段和要求
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(period));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(requirement));

        // 操作列添加编辑和删除按钮
        QWidget *widget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(widget);
        QPushButton *editButton = new QPushButton("编辑");
        QPushButton *deleteButton = new QPushButton("删除");
        layout->addWidget(editButton);
        layout->addWidget(deleteButton);
        layout->setContentsMargins(0, 0, 0, 0);
        ui->tableWidget->setCellWidget(row, 2, widget);

        // 连接按钮信号
        connect(editButton, &QPushButton::clicked, this, [=]() { editRow(row); });
        connect(deleteButton, &QPushButton::clicked, this, [=]() { deleteRow(row); });
    }
}

// 保存表格数据
void Summary::saveTableData()
{
    QJsonArray array;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QJsonObject obj;
        obj["period"] = ui->tableWidget->item(row, 0)->text();
        obj["requirement"] = ui->tableWidget->item(row, 1)->text();
        array.append(obj);
    }

    QJsonDocument doc(array);
    QFile file("table_data.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    }
}

// 添加 like 关键词
void Summary::on_addButton_2_clicked()
{
    QString newLike = ui->addLike->toPlainText().trimmed();
    if (newLike.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请输入关键词！");
        return;
    }

    // 检查是否已存在
    if (m_user_like.contains(newLike)) {
        QMessageBox::information(this, "提示", "该关键词已存在！");
        ui->addLike->clear();
        return;
    }

    // 添加到 m_user_like
    m_user_like.insert(newLike);
    qDebug() << "m_user_like count:" << m_user_like.count();

    // 更新显示
    updateLikeDisplay();

    // 清空输入框
    ui->addLike->clear();
}

// 卡片点击事件 - like
void Summary::on_like_itemClicked(QListWidgetItem *item)
{
    QString like = item->text();
    if (QMessageBox::question(this, "删除确认", QString("确定删除关键词 '%1' 吗？").arg(like)) == QMessageBox::Yes) {
        m_user_like.remove(like);
        updateLikeDisplay();
    }
}

// 更新 like 显示
void Summary::updateLikeDisplay()
{
    ui->like->clear();
    for (const QString &like : m_user_like) {
        QListWidgetItem *item = new QListWidgetItem(like);
        item->setTextAlignment(Qt::AlignCenter);
        ui->like->addItem(item);
    }
}


// 卡片点击事件 - dislike
void Summary::on_dislike_itemClicked(QListWidgetItem *item)
{
    QString dislike = item->text();
    if (QMessageBox::question(this, "删除确认", QString("确定删除关键词 '%1' 吗？").arg(dislike)) == QMessageBox::Yes) {
        m_user_dislike.remove(dislike);
        updateDislikeDisplay();
    }
}

// 更新 dislike 显示
void Summary::updateDislikeDisplay()
{
    ui->dislike->clear();
    for (const QString &dislike : m_user_dislike) {
        QListWidgetItem *item = new QListWidgetItem(dislike);
        item->setTextAlignment(Qt::AlignCenter);
        ui->dislike->addItem(item);
    }
}

// checkBox1 状态改变
void Summary::on_checkBox1_stateChanged(int state)
{
    if (state == Qt::Checked) {
        updateCheckBoxState("checkBox1");
    }
}

// checkBox2 状态改变
void Summary::on_checkBox2_stateChanged(int state)
{
    if (state == Qt::Checked) {
        updateCheckBoxState("checkBox2");
    }
}

// checkBox3 状态改变
void Summary::on_checkBox3_stateChanged(int state)
{
    if (state == Qt::Checked) {
        updateCheckBoxState("checkBox3");
    }
}

// 更新 checkBox 互斥状态并保存
void Summary::updateCheckBoxState(QString selected)
{
    // 确保互斥：取消其他 checkBox 的选中状态
    if (selected == "checkBox1") {
        ui->checkBox2->setChecked(false);
        ui->checkBox3->setChecked(false);
    } else if (selected == "checkBox2") {
        ui->checkBox1->setChecked(false);
        ui->checkBox3->setChecked(false);
    } else if (selected == "checkBox3") {
        ui->checkBox1->setChecked(false);
        ui->checkBox2->setChecked(false);
    }

    // 更新变量
    selectedCheckBox = selected;

    // 保存状态
    saveCheckBoxState();
}

// 加载 checkBox 状态
void Summary::loadCheckBoxState()
{
    QFile file("checkbox_state.json");
    if (!file.open(QIODevice::ReadOnly)) {
        // 如果文件不存在，默认选中 checkBox1
        updateCheckBoxState("checkBox1");
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonObject obj = doc.object();
    selectedCheckBox = obj["selected"].toString();

    // 根据保存的状态更新 checkBox
    if (selectedCheckBox == "checkBox1") {
        ui->checkBox1->setChecked(true);
    } else if (selectedCheckBox == "checkBox2") {
        ui->checkBox2->setChecked(true);
    } else if (selectedCheckBox == "checkBox3") {
        ui->checkBox3->setChecked(true);
    } else {
        // 如果保存的状态无效，默认选中 checkBox1
        updateCheckBoxState("checkBox1");
    }
}

// 保存 checkBox 状态
void Summary::saveCheckBoxState()
{
    QJsonObject obj;
    obj["selected"] = selectedCheckBox;

    QJsonDocument doc(obj);
    QFile file("checkbox_state.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    }
}

void Summary::on_addButton_3_clicked()
{
    QString newDislike = ui->addDislike->toPlainText().trimmed();
    if (newDislike.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请输入关键词！");
        return;
    }

    // 检查是否已存在
    if (m_user_dislike.contains(newDislike)) {
        QMessageBox::information(this, "提示", "该关键词已存在！");
        ui->addLike->clear();
        return;
    }

    // 添加到 m_user_dislike
    m_user_dislike.insert(newDislike);
    qDebug() << "m_user_dislike count:" << m_user_dislike.count();

    // 更新显示
    updateDislikeDisplay();

    // 清空输入框
    ui->addLike->clear();
}
