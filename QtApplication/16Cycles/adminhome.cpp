#include "adminhome.h"
#include "ui_adminhome.h"
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

AdminHome::AdminHome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminHome)
{
    ui->setupUi(this);
}

AdminHome::~AdminHome()
{
    delete ui;
}

void AdminHome::setGroupBoxName(QString name)
{
    QString boxName = "Welcome " + name;
    ui-> welcomeGroupBox-> setTitle(boxName);
    userName = name;
}

void AdminHome::setUserEmail(QString email)
{
    userEmail = email;
}

void AdminHome::on_adminLogOutButton_clicked()
{
    // Display question to check user wants to log out
    QMessageBox::StandardButton reply = QMessageBox::question(this,"16Cycles","Are you sure you want to log out",
                                                              QMessageBox::Yes | QMessageBox::No);

    // Close window if yes clicked, else do nothing
    if(reply == QMessageBox::Yes)
    {
        // Hide current window and display log in window(MainWindow)
        this-> close();
    }
}

void AdminHome::on_staffViewButton_clicked()
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

    ui-> tableView-> setModel(model);
    ui-> tableView-> resizeColumnsToContents();
    ui-> tableView-> resizeRowsToContents();
}

void AdminHome::on_staffAddButton_clicked()
{
    // Display new window
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

void AdminHome::on_staffRemoveButton_clicked()
{
    // Display new window
    RemoveStaff removeStaffPage;
    removeStaffPage.setModal(true);

    // Set window size
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    removeStaffPage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    removeStaffPage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    removeStaffPage.setWindowTitle("16CyclesRemoveStaff");

    // Show window
    removeStaffPage.exec();
}

void AdminHome::on_staffUpdateButton_clicked()
{
    // Display new window
    UpdateStaff updateStaffPage;
    updateStaffPage.setModal(true);

    // Set window size
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    updateStaffPage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    updateStaffPage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    updateStaffPage.setWindowTitle("16CyclesUpdateStaff");

    // Show window
    updateStaffPage.exec();
}

void AdminHome::on_resetPasswordButton_clicked()
{
    // Display new window
    ResetPassword resetPasswordPage;
    resetPasswordPage.setModal(true);
    resetPasswordPage.setEmail(userEmail);

    // Set window size
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    resetPasswordPage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    resetPasswordPage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    resetPasswordPage.setWindowTitle("16CyclesResetPassword");

    // Show window
    resetPasswordPage.exec();
}

void AdminHome::on_bikesViewButton_clicked()
{
    MainWindow mainWindow;
    if(!mainWindow.openConnection())
    {
        this->close();
        qDebug()<<("Failed open db bikes");
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery(mainWindow.db);

    // Display question to check user wants to log out
    QMessageBox::StandardButton reply = QMessageBox::question(this,"16Cycles","Do you want to see Bikes?",
                                                              QMessageBox::Yes | QMessageBox::No);

    // Display bikes if yes clicked
    if(reply == QMessageBox::Yes)
    {
        query-> prepare("SELECT * FROM bikes");
        query-> exec();
        if(!query-> next())
        {
            this-> close();
            qDebug()<<("error bikes");
        }

        mainWindow.close();
        model-> setQuery(*query);
        ui-> tableView-> setModel(model);
        ui-> tableView-> resizeColumnsToContents();
        ui-> tableView-> resizeRowsToContents();
    }

    // Display bike types if no
    else
    {
        query-> prepare("SELECT * FROM bike_types");
        query-> exec();
        if(!query-> next())
        {
            this-> close();
            qDebug()<<("error bikes");
        }

        mainWindow.close();
        model-> setQuery(*query);
        ui-> tableView-> setModel(model);
        ui-> tableView-> resizeColumnsToContents();
        ui-> tableView-> resizeRowsToContents();
    }
}

void AdminHome::on_ordersViewButton_clicked()
{
    MainWindow mainWindow;
    if(!mainWindow.openConnection())
    {
        this->close();
        qDebug()<<("Failed open db bikes");
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery(mainWindow.db);

    query-> prepare("SELECT * FROM orders");
    query-> exec();
    if(!query-> next())
    {
        this-> close();
        qDebug()<<("error bikes");
    }

    mainWindow.close();

    model-> setQuery(*query);

    ui-> tableView-> setModel(model);
    ui-> tableView-> resizeColumnsToContents();
    ui-> tableView-> resizeRowsToContents();
}

void AdminHome::on_statisticsProfitsButton_clicked()
{
    Profits profitsPage;
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    profitsPage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    profitsPage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    profitsPage.setWindowTitle("16CyclesProfits");

    // Show window
    profitsPage.exec();
}

void AdminHome::on_bikesUpdateButton_clicked()
{
    UpdateBikes updateBikesPage;
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    updateBikesPage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    updateBikesPage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    updateBikesPage.setWindowTitle("16CyclesUpdateBikes");

    // Show window
    updateBikesPage.exec();
}

void AdminHome::on_bikesAddBikeButton_clicked()
{
    AddBikes addBikesPage;
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    addBikesPage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    addBikesPage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    addBikesPage.setWindowTitle("16CyclesAddBikes");

    // Show window
    addBikesPage.exec();
}

void AdminHome::on_bikesAddTypeButton_clicked()
{
    AddBikeTypes addBikeTypesPage;
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    addBikeTypesPage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    addBikeTypesPage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    addBikeTypesPage.setWindowTitle("16CyclesAddBikeType");

    // Show window
    addBikeTypesPage.exec();
}

void AdminHome::on_BikesRemoveButton_clicked()
{
    RemoveBikes removeBikesPage;
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    removeBikesPage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    removeBikesPage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    removeBikesPage.setWindowTitle("16CyclesRemoveBikes");

    // Show window
    removeBikesPage.exec();
}

void AdminHome::on_ordersUpdateButton_clicked()
{
    UpdateOrders updateOrdersPage;
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    updateOrdersPage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    updateOrdersPage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    updateOrdersPage.setWindowTitle("16CyclesUpdateOrders");

    // Show window
    updateOrdersPage.exec();
}

void AdminHome::on_ordersCreateButton_clicked()
{
    CreateOrder createOrdersPage;
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    createOrdersPage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    createOrdersPage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    createOrdersPage.setWindowTitle("16CyclesCreateOrder");

    // Show window
    createOrdersPage.exec();
}

void AdminHome::on_ordersRemoveButton_clicked()
{
    RemoveOrder removeOrderPage;
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    removeOrderPage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    removeOrderPage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    removeOrderPage.setWindowTitle("16CyclesRemoveOrder");

    // Show window
    removeOrderPage.exec();
}

void AdminHome::on_statisticsBikesButton_clicked()
{
    StatisticsBikes statisticsBikesPage;
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    statisticsBikesPage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    statisticsBikesPage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    statisticsBikesPage.setWindowTitle("16CyclesStatisticsBikes");

    // Show window
    statisticsBikesPage.exec();
}

void AdminHome::on_statisticsShopsButton_clicked()
{
    StatisticsShops statisticsShopsPage;
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    statisticsShopsPage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    statisticsShopsPage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    statisticsShopsPage.setWindowTitle("16CyclesStatisticsShops");

    // Show window
    statisticsShopsPage.exec();
}
