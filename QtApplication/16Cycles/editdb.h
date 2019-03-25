#ifndef EDITDB_H
#define EDITDB_H

#include <QDialog>

namespace Ui {
class EditDb;
}

class EditDb : public QDialog
{
    Q_OBJECT

public:
    explicit EditDb(QWidget *parent = 0);
    ~EditDb();

private slots:

    void on_homeButton_clicked();

private:
    Ui::EditDb *ui;
};

#endif // EDITDB_H
