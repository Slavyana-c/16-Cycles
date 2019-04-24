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
    ui-> filterAllTimeShopsComboBox-> setModel(modelShops);

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

    else
    {
        ui-> filterTwoDatesProfitsLabel-> setText("£0.00");
    }

    // If query returned a value
    if(query.next())
    {
        QString profit = "£";
        profit += query.value(0).toString();
        ui-> filterTwoDatesProfitsLabel-> setText(profit);
    }

    else
    {
        ui-> filterTwoDatesProfitsLabel-> setText("£0.00");
    }


    mainWindow.closeConnection();
}

void Profits::on_filterTwoDatesShopsComboBox_activated(const QString &arg1)
{
    QString dateOne,dateTwo,shopID;
    dateOne = ui-> dateOneLineEdit-> text();
    dateTwo = ui-> dateTwoLineEdit-> text();
    shopID = arg1;

    // Open DB
    MainWindow mainWindow;
    if(!mainWindow.openConnection())
    {
        this->close();
        qDebug()<<("Failed open db bikes");
    }

    QSqlQuery query;
    query.prepare("SELECT SUM(o.total_price) FROM orders o INNER JOIN rented_bikes rb ON o.id = rb.id INNER JOIN bikes b ON rb.bike_id = b.id WHERE b.shop_id = '" + shopID + "' AND date between '" + dateOne + " 00:00:00' AND '" + dateTwo + " 00:00:00'");

    // Execute query
    if(!query.exec())
    {
        QMessageBox::critical(this,"16CyclesProfits","Failed to run query. Enter dates in format 0000-00-00 (year-month-day)");
    }

    else
    {
        ui-> filterTwoDatesProfitsShopsLabel-> setText("£0.00");
    }

    // If query returned a value
    if(query.next())
    {
        QString profit = "£";
        profit += query.value(0).toString();
        ui-> filterTwoDatesProfitsShopsLabel-> setText(profit);
    }

    else
    {
        ui-> filterTwoDatesProfitsShopsLabel-> setText("£0.00");
    }


    mainWindow.closeConnection();
}

void Profits::on_filterAllTimeShopsComboBox_activated(const QString &arg1)
{
    QString shopID;
    shopID = arg1;

    // Open DB
    MainWindow mainWindow;
    if(!mainWindow.openConnection())
    {
        this->close();
        qDebug()<<("Failed open db bikes");
    }

    QSqlQuery query;
    query.prepare("SELECT SUM(o.total_price) FROM orders o INNER JOIN rented_bikes rb ON o.id = rb.id INNER JOIN bikes b ON rb.bike_id = b.id WHERE b.shop_id = '" + shopID + "'");

    // Execute query
    if(!query.exec())
    {
        QMessageBox::critical(this,"16CyclesProfits","Failed to run query.");
    }

    else
    {
        ui-> filterAllTimeShopsProfitsLabel-> setText("£0.00");
    }

    // If query returned a value
    if(query.next())
    {
        QString profit = "£";
        profit += query.value(0).toString();
        ui-> filterAllTimeShopsProfitsLabel-> setText(profit);
    }

    else
    {
        ui-> filterAllTimeShopsProfitsLabel-> setText("£0.00");
    }


    mainWindow.closeConnection();
}
