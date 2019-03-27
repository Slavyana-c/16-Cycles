#include "statisticsbikes.h"
#include "ui_statisticsbikes.h"

StatisticsBikes::StatisticsBikes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatisticsBikes)
{
    ui->setupUi(this);
}

StatisticsBikes::~StatisticsBikes()
{
    delete ui;
}

void StatisticsBikes::on_goBackButton_clicked()
{
    this-> close();
}
