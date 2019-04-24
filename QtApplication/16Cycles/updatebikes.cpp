#include "updatebikes.h"
#include "ui_updatebikes.h"

UpdateBikes::UpdateBikes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateBikes)
{
    ui->setupUi(this);
}

UpdateBikes::~UpdateBikes()
{
    delete ui;
}

void UpdateBikes::on_goBackButton_clicked()
{
    this-> close();
}
