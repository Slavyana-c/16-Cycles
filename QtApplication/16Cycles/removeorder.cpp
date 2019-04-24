#include "removeorder.h"
#include "ui_removeorder.h"

RemoveOrder::RemoveOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveOrder)
{
    ui->setupUi(this);
}

RemoveOrder::~RemoveOrder()
{
    delete ui;
}

void RemoveOrder::on_goBackButton_clicked()
{
    this-> close();
}
