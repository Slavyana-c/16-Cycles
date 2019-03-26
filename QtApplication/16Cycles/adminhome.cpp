#include "adminhome.h"
#include "ui_adminhome.h"
#include "mainwindow.h"
#include "addstaff.h"
#include "removestaff.h"
#include "updatestaff.h"

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
