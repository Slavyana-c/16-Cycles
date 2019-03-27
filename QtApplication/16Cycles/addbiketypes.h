#ifndef ADDBIKETYPES_H
#define ADDBIKETYPES_H

#include <QDialog>

namespace Ui {
class AddBikeTypes;
}

class AddBikeTypes : public QDialog
{
    Q_OBJECT

public:
    explicit AddBikeTypes(QWidget *parent = 0);
    ~AddBikeTypes();

private slots:
    void on_goBackButtonn_clicked();

private:
    Ui::AddBikeTypes *ui;
};

#endif // ADDBIKETYPES_H
