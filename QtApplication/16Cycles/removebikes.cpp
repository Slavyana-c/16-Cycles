#include "removebikes.h"
#include "ui_removebikes.h"

RemoveBikes::RemoveBikes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveBikes)
{
    ui->setupUi(this);
}

RemoveBikes::~RemoveBikes()
{
    delete ui;
}

void RemoveBikes::on_goBackButton_clicked()
{
    this-> close();
}
