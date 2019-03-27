#include "addbikes.h"
#include "ui_addbikes.h"

AddBikes::AddBikes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBikes)
{
    ui->setupUi(this);
}

AddBikes::~AddBikes()
{
    delete ui;
}

void AddBikes::on_goBackButton_clicked()
{
    this-> close();
}
