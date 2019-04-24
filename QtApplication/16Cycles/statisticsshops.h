#ifndef STATISTICSSHOPS_H
#define STATISTICSSHOPS_H

#include <QDialog>

namespace Ui {
class StatisticsShops;
}

class StatisticsShops : public QDialog
{
    Q_OBJECT

public:
    explicit StatisticsShops(QWidget *parent = 0);
    ~StatisticsShops();

private slots:
    void on_goBackButton_clicked();

private:
    Ui::StatisticsShops *ui;
};

#endif // STATISTICSSHOPS_H
