#ifndef UPDATEBIKES_H
#define UPDATEBIKES_H

#include <QDialog>

namespace Ui {
class UpdateBikes;
}

class UpdateBikes : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateBikes(QWidget *parent = 0);
    ~UpdateBikes();

private slots:
    void on_goBackButton_clicked();

private:
    Ui::UpdateBikes *ui;
};

#endif // UPDATEBIKES_H
