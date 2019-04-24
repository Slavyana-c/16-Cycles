#include "home.h"
#include "ui_home.h"
#include "mainwindow.h"
#include "resetpassword.h"
#include "addstaff.h"
#include "removestaff.h"
#include "updatestaff.h"
#include "profits.h"
#include "addbikes.h"
#include "addbiketypes.h"
#include "removebikes.h"
#include "updatebikes.h"
#include "createorder.h"
#include "removeorder.h"
#include "updateorders.h"
#include "statisticsbikes.h"
#include "statisticsshops.h"

Home::Home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
}

Home::~Home()
{
    delete ui;
}

void Home::setGroupBoxName(QString name)
{

}

void Home::setUserEmail(QString email)
{

}

void Home::on_goBackButton_clicked()
{
    this-> close();
}
