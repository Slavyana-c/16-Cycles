#include "editdb.h"
#include "ui_editdb.h"
#include "mainwindow.h"

EditDb::EditDb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDb)
{
    ui->setupUi(this);
}

EditDb::~EditDb()
{
    delete ui;
}

void EditDb::on_homeButton_clicked()
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
