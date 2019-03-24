#include "editdb.h"
#include "ui_editdb.h"
#include "mainwindow.h"

EditDb::EditDb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDb)
{
    ui->setupUi(this);

    // Open database
    MainWindow mainWindow;
    if(!mainWindow.openConnection())
    {
        this->close();
        qDebug()<<("Failed open db editdb");
    }
}

EditDb::~EditDb()
{
    delete ui;
}
