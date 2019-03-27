#include "profits.h"
#include "ui_profits.h"

Profits::Profits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Profits)
{
    ui->setupUi(this);
}

Profits::~Profits()
{
    delete ui;
}
