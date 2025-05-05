#include "aboutdialog.h"
#include "ui_aboutdialog.h"

aboutDialog::aboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutDialog)
{
    setWindowFlag(Qt::FramelessWindowHint);  // 去掉标题栏和边框
    ui->setupUi(this);
}

aboutDialog::~aboutDialog()
{
    delete ui;
}

void aboutDialog::on_pushButton_clicked()
{
    close();
}

void aboutDialog::on_pushButton_2_clicked()
{
    close();
}
