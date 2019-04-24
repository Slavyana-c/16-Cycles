#include "profits.h"
#include "ui_profits.h"
#include "mainwindow.h"

Profits::Profits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Profits)
{
    ui->setupUi(this);

    // Open DB
    MainWindow mainWindow;
    if(!mainWindow.openConnection())
    {
        this->close();
        qDebug()<<("Failed open db bikes");
    }
    QSqlQuery *queryp = new QSqlQuery(mainWindow.db);

    // Populate profits shop id combo box
    QSqlQueryModel *modelShops = new QSqlQueryModel();
    queryp-> prepare("SELECT id FROM shops");
    queryp-> exec();
    queryp-> next();
    modelShops-> setQuery(*queryp);
    ui-> filterTwoDatesShopsComboBox-> setModel(modelShops);

    mainWindow.closeConnection();
}

Profits::~Profits()
{
    delete ui;
}

void Profits::on_goBackButton_clicked()
{
    this-> close();
}

void Profits::on_filterTwoDatesRefreshButton_clicked()
{
    QString dateOne,dateTwo;
    dateOne = ui-> dateOneLineEdit-> text();
    dateTwo = ui-> dateTwoLineEdit-> text();

    // Open DB
    MainWindow mainWindow;
    if(!mainWindow.openConnection())
    {
        this->close();
        qDebug()<<("Failed open db bikes");
    }

    QSqlQuery query;
    query.prepare("SELECT SUM(o.total_price) FROM orders o WHERE date between '" + dateOne + " 00:00:00' AND '" + dateTwo + " 00:00:00'");

    // Execute query
    if(!query.exec())
    {
        QMessageBox::critical(this,"16CyclesProfits","Failed to run query. Enter dates in format 0000-00-00 (year-month-day)");
    }

    // If query returned a value
    if(query.next())
    {
        QString profit = "£";
        profit += query.value(0).toString();
        ui-> FilterTwoDatesProfitsLabel-> setText(profit);
    }

    else
    {
        ui-> FilterTwoDatesProfitsLabel-> setText("£0.00");
    }


    mainWindow.closeConnection();
}
