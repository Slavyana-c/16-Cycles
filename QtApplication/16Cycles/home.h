#ifndef HOME_H
#define HOME_H

#include <QDialog>

namespace Ui {
class Home;
}

class Home : public QDialog
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = 0);
    ~Home();
    void setGroupBoxName(QString name);
    void setUserEmail(QString email);

private slots:
    void on_goBackButton_clicked();

private:
    Ui::Home *ui;
};

#endif // HOME_H
