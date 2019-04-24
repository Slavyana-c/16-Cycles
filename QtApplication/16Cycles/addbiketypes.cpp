#include "addbiketypes.h"
#include "ui_addbiketypes.h"

AddBikeTypes::AddBikeTypes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBikeTypes)
{
    ui->setupUi(this);
}

AddBikeTypes::~AddBikeTypes()
{
    delete ui;
}

void AddBikeTypes::on_goBackButtonn_clicked()
{
    this-> close();
}
