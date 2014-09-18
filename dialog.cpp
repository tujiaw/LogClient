#include "dialog.h"
#include "ui_dialog.h"
#include "logclient.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pbSend_clicked()
{
    MYLOG << ui->content->text();
}
