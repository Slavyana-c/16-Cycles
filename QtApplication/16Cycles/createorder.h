#ifndef CREATEORDER_H
#define CREATEORDER_H

#include <QDialog>

namespace Ui {
class CreateOrder;
}

class CreateOrder : public QDialog
{
    Q_OBJECT

public:
    explicit CreateOrder(QWidget *parent = 0);
    ~CreateOrder();

private slots:
    void on_goBackButton_clicked();

private:
    Ui::CreateOrder *ui;
};

#endif // CREATEORDER_H
