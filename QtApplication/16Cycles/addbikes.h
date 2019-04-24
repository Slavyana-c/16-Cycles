#ifndef ADDBIKES_H
#define ADDBIKES_H

#include <QDialog>

namespace Ui {
class AddBikes;
}

class AddBikes : public QDialog
{
    Q_OBJECT

public:
    explicit AddBikes(QWidget *parent = 0);
    ~AddBikes();

private slots:
    void on_goBackButton_clicked();

private:
    Ui::AddBikes *ui;
};

#endif // ADDBIKES_H
