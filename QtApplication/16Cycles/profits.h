#ifndef PROFITS_H
#define PROFITS_H

#include <QDialog>

namespace Ui {
class Profits;
}

class Profits : public QDialog
{
    Q_OBJECT

public:
    explicit Profits(QWidget *parent = 0);
    ~Profits();

private slots:
    void on_goBackButton_clicked();

    void on_filterTwoDatesRefreshButton_clicked();

    void on_filterTwoDatesShopsComboBox_activated(const QString &arg1);

    void on_filterAllTimeShopsComboBox_activated(const QString &arg1);

private:
    Ui::Profits *ui;
};

#endif // PROFITS_H
