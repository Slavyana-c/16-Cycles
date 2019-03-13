#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPixmap>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlDriver>
#include <QDebug>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName(":/resourcefile/database/app.db");
        if(!db.open())
        {
            qWarning() << "ERROR: " << db.lastError();
            ui-> labelDb-> setText("noooooope");
        }
        else
        {
            ui-> labelDb-> setText("Database connected");
        }
    }
    //    db.setDatabaseName(":/resourcefile/database/app.db");

//    if(!db.open())
//    {
//        ui-> labelDb-> setText("noooooope");
//        qDebug()<<QSqlDatabase::lastError(db);
//    }
//    else
//    {
//        ui-> labelDb-> setText("Database connected");
//    }
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
        QApplication::quit();
    }
}

void MainWindow::on_pushButtonLogin_clicked()
{
    QString username = ui-> lineEditUsername-> text(); //
    QString password = ui-> lineEditPassword-> text();

    // fixed username password
    if(username == "dummy" && password == "123")
    {
        QMessageBox::information(this,"Login","Username and Password is correct.");
        hide();
        homeDialog = new HomeDialog(this);
        homeDialog->show();
    }

    else
    {
        QMessageBox::warning(this,"Login","Username and Password are not correct.");
    }
}
