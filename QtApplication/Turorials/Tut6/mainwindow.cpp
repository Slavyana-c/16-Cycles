#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Call;ed when button called
void MainWindow::on_pushButton_clicked()
{
    // Display dialogue message
//    QMessageBox::about(this,"16Cycles","Qt desktop application"); // general
//    QMessageBox::aboutQt(this,"16Cycles About Qt"); // Qt information
//    QMessageBox::critical(this,"16Cycles critical!","This is critical"); // Has critical icon
//    QMessageBox::information(this,"16Cycles","Here is your information"); // Has info(lightbulb) icon
//    QMessageBox::question(this,"16Cycles","How are you?"); // Has question mark icon, yes/no buttons
//    QMessageBox::warning(this,"16Cycles","I see you"); // Has yellow warning icon

    // returning as reply
    QMessageBox::StandardButton reply = QMessageBox::question(this,"16Cycles","heres a question",
                                                              QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }

    else if(reply == QMessageBox::No)
    {
        qDebug() << "No clicked"; // Like cout
    }

    /* Message Types
     * about
     * aboutQt
     * critical // return value
     * information // return value
     * question // return value
     * warning // return value
    */
}
