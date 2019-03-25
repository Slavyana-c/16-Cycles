#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Set screen size to size of users screen
    QDesktopWidget desktop;
    QRect mainScreenSize = desktop.availableGeometry(desktop.primaryScreen());
    w.setFixedSize(mainScreenSize.width(),mainScreenSize.height());

    // Remove title bar
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Set window title
    w.setWindowTitle("16CyclesLogIn");

    // Display window
    w.show();

    return a.exec();
}
