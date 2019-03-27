#include "staff.h"
#include "ui_staff.h"
#include "mainwindow.h"
#include "addstaff.h"

Staff::Staff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Staff)
{
    ui->setupUi(this);

    MainWindow mainWindow;
    if(!mainWindow.openConnection())
    {
        this->close();
        qDebug()<<("Failed open db staff");
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery(mainWindow.db);

    query-> prepare("SELECT * FROM staff");
    query-> exec();
    if(!query-> next())
    {
        this-> close();
        qDebug()<<("error staff");
    }

    mainWindow.close();

    model-> setQuery(*query);

    ui-> staffTable-> setModel(model);
}

Staff::~Staff()
{
    delete ui;
}

void Staff::on_addStaff_clicked()
{
    // Close current window and display new window
    this-> close();
    AddStaff addStaffPage;
    addStaffPage.setModal(true);

    // Set window size
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    addStaffPage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    addStaffPage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    addStaffPage.setWindowTitle("16CyclesAddStaff");

    // Show window
    addStaffPage.exec();
}

void Staff::on_homeButton_clicked()
{
    // Close current window and display new window
    this-> close();
    home homePage;
    homePage.setModal(true);

    // Set window size
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    homePage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    homePage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    homePage.setWindowTitle("16CyclesHome");

    // Show window
    homePage.exec();
}

void Staff::on_refreshButton_clicked()
{
    MainWindow mainWindow;
    if(!mainWindow.openConnection())
    {
        this->close();
        qDebug()<<("Failed open db staff");
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery(mainWindow.db);

    query-> prepare("SELECT * FROM staff");
    query-> exec();
    if(!query-> next())
    {
        this-> close();
        qDebug()<<("error staff");
    }

    mainWindow.close();

    model-> setQuery(*query);

    ui-> staffTable-> setModel(model);
}
