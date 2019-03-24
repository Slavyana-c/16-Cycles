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

private:
    Ui::EditDb *ui;
};

#endif // EDITDB_H
