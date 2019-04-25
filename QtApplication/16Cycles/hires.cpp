#include "hires.h"
#include "ui_hires.h"

Hires::Hires(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hires)
{
    ui->setupUi(this);
}

Hires::~Hires()
{
    delete ui;
}
