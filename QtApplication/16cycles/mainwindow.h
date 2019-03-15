#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

#include "homedialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonClose_clicked();

    void on_pushButtonLogin_clicked();

private:
    Ui::MainWindow *ui;
    HomeDialog *homeDialog;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
