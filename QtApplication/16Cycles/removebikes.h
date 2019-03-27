#ifndef REMOVEBIKES_H
#define REMOVEBIKES_H

#include <QDialog>

namespace Ui {
class RemoveBikes;
}

class RemoveBikes : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveBikes(QWidget *parent = 0);
    ~RemoveBikes();

private slots:
    void on_goBackButton_clicked();

private:
    Ui::RemoveBikes *ui;
};

#endif // REMOVEBIKES_H
