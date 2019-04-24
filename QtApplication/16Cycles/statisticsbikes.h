#ifndef STATISTICSBIKES_H
#define STATISTICSBIKES_H

#include <QDialog>

namespace Ui {
class StatisticsBikes;
}

class StatisticsBikes : public QDialog
{
    Q_OBJECT

public:
    explicit StatisticsBikes(QWidget *parent = 0);
    ~StatisticsBikes();

private slots:
    void on_goBackButton_clicked();

private:
    Ui::StatisticsBikes *ui;
};

#endif // STATISTICSBIKES_H
