#include "updateorders.h"
#include "ui_updateorders.h"

UpdateOrders::UpdateOrders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateOrders)
{
    ui->setupUi(this);
}

UpdateOrders::~UpdateOrders()
{
    delete ui;
}

void UpdateOrders::on_goBackButton_clicked()
{
    this-> close();
}
