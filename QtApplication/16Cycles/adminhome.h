#ifndef ADMINHOME_H
#define ADMINHOME_H

#include <QDialog>

namespace Ui {
class AdminHome;
}

class AdminHome : public QDialog
{
    Q_OBJECT

public:
    explicit AdminHome(QWidget *parent = 0);
    ~AdminHome();
    void setGroupBoxName(QString name);

private slots:
    void on_adminLogOutButton_clicked();

    void on_staffViewButton_clicked();

    void on_staffAddButton_clicked();

    void on_staffRemoveButton_clicked();

    void on_staffUpdateButton_clicked();

private:
    Ui::AdminHome *ui;
};

#endif // ADMINHOME_H
