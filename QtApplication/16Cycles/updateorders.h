#ifndef UPDATEORDERS_H
#define UPDATEORDERS_H

#include <QDialog>

namespace Ui {
class UpdateOrders;
}

class UpdateOrders : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateOrders(QWidget *parent = 0);
    ~UpdateOrders();

private slots:
    void on_goBackButton_clicked();

private:
    Ui::UpdateOrders *ui;
};

#endif // UPDATEORDERS_H
