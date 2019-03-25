#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Sender(input), Signal(what happened), Reciever(output), Slot(reaction)
    // The macro Q_OBJECT allows this method to be used
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));

    // Can disconnect same way but replace connect with disconnect
}

MainWindow::~MainWindow()
{
    delete ui;
}
