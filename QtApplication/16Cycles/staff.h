#ifndef STAFF_H
#define STAFF_H

#include <QDialog>

namespace Ui {
class Staff;
}

class Staff : public QDialog
{
    Q_OBJECT

public:
    explicit Staff(QWidget *parent = 0);
    ~Staff();

private slots:
    void on_addStaff_clicked();

    void on_homeButton_clicked();

    void on_refreshButton_clicked();

private:
    Ui::Staff *ui;
};

#endif // STAFF_H
