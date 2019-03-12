#include "mainwindow.h"
#include "ui_mainwindow.h"

// Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Open main window
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Code executed when close button clicked
void MainWindow::on_CloseButton_clicked()
{
    ui-> label-> setText("Button clicked"); // label on ui object
}
