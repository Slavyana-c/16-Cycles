#include "home.h"
#include "ui_home.h"
#include "mainwindow.h"
#include "editdb.h"

home::home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
}

home::~home()
{
    delete ui;
}

void home::on_editDBButton_clicked()
{
    // Hide current window and display new window
    this-> hide();
    EditDb editDbPage;
    editDbPage.setModal(true);

    // Set window size
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    editDbPage.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    editDbPage.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    editDbPage.setWindowTitle("16CyclesHome");

    // Show window
    editDbPage.exec();
}

void home::on_logOutButton_clicked()
{
    // Display question to check user wants to log out
    QMessageBox::StandardButton reply = QMessageBox::question(this,"16Cycles","Are you sure you want to log out",
                                                              QMessageBox::Yes | QMessageBox::No);

    // Close window if yes clicked, else do nothing
    if(reply == QMessageBox::Yes)
    {
        // Hide current window and display log in window(MainWindow)
        this-> hide();
    }
}
