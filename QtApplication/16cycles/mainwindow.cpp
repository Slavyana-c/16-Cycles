#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPixmap>
#include <QtSql>
#include <QSqlDatabase>
#include <QDesktopWidget>
#include <QSqlError>
#include <QSqlDriver>
#include <QDebug>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QDesktopWidget desktop;

    this-> setFixedSize(QDesktopWidget().availableGeometry(this).size());
    //resize(QDesktopWidget().availableGeometry(this).size());
    // Logo
    QPixmap logo(":/resourcefile/images/app_static_images_logo.png");
    int width = ui-> labelLogo-> width();
    int height = ui-> labelLogo-> height();
    ui-> labelLogo-> setPixmap(QPixmap(logo.scaled(width,height,Qt::KeepAspectRatio)));

    // Database Connection
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    const QString DRIVER("QSQLITE");
    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        db = QSqlDatabase::addDatabase(DRIVER);
        //db.setDatabaseName("/home/cserv1_a/soc_msc/ll16m23c/year2/Project/16-cycles/QtApplication/16cycles/employees.db");
        db.setDatabaseName("employees.db");
        if(!db.open())
        {
            qWarning() << "ERROR: " << db.lastError();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonClose_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"16Cycles","Are you sure you want to quit?",
                                                              QMessageBox::No | QMessageBox::Yes);

    if(reply == QMessageBox::Yes)
    {
        db.close();
        QApplication::quit();
    }
}

void MainWindow::on_pushButtonLogin_clicked()
{
    QString username = ui-> lineEditUsername-> text();
    QString password = ui-> lineEditPassword-> text();

    if(!db.isOpen())
    {
        qDebug() << "FAILED TO OPEN THE DATABASE";
        return;
    }

    QSqlQuery query;
    query.exec("SELECT * FROM employees WHERE Username='" + username + "' AND Password='" + password + "'");
    if(query.next())
    {
        QMessageBox::information(this,"Login Success","Username and Password correct");
        hide();
        homeDialog = new HomeDialog(this);
        homeDialog->show();
    }
    else
    {
        QMessageBox::critical(this,"Login Failed","Username and Password incorrect");
    }
}
