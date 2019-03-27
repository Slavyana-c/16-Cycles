#include "createorder.h"
#include "ui_createorder.h"

CreateOrder::CreateOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateOrder)
{
    ui->setupUi(this);
}

CreateOrder::~CreateOrder()
{
    delete ui;
}
