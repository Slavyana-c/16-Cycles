#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "home.h"
#include <QMainWindow>
#include <QDesktopWidget>
#include <QRect>
#include <QPixmap>
#include <QMessageBox>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeConnection();
    bool openConnection();

public:
    QSqlDatabase db;

private slots:
    void on_quitButton_clicked();

    void on_signInButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
