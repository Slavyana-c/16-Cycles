#ifndef REMOVEORDER_H
#define REMOVEORDER_H

#include <QDialog>

namespace Ui {
class RemoveOrder;
}

class RemoveOrder : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveOrder(QWidget *parent = 0);
    ~RemoveOrder();

private slots:
    void on_goBackButton_clicked();

private:
    Ui::RemoveOrder *ui;
};

#endif // REMOVEORDER_H
