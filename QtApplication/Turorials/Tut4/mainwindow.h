#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui // Include MainWindow class in namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow // Inheriting from QMainWindow
{
    Q_OBJECT // Meta Object Compiler converts macro, converts header files to c++ code -> signals and slots

public:
    explicit MainWindow(QWidget *parent = 0); // Constructor
    ~MainWindow(); // Destructor delete all pointer object

private slots:
    void on_CloseButton_clicked();

private:
    Ui::MainWindow *ui; // This object access all widgets added in in window
};

#endif // MAINWINDOW_H
