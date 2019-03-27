#include "statisticsshops.h"
#include "ui_statisticsshops.h"

StatisticsShops::StatisticsShops(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatisticsShops)
{
    ui->setupUi(this);
}

StatisticsShops::~StatisticsShops()
{
    delete ui;
}

void StatisticsShops::on_goBackButton_clicked()
{
    this-> close();
}
