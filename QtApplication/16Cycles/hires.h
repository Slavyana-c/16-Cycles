#ifndef HIRES_H
#define HIRES_H

#include <QDialog>

namespace Ui {
class Hires;
}

class Hires : public QDialog
{
    Q_OBJECT

public:
    explicit Hires(QWidget *parent = 0);
    ~Hires();

private:
    Ui::Hires *ui;
};

#endif // HIRES_H
