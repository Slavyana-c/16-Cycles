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

    QSqlQueryModel *modelPrices = new QSqlQueryModel();
    QSqlQuery *queryp = new QSqlQuery(mainWindow.db);

    // Get list of prices of rented bikes
    queryp-> prepare("SELECT total_price FROM orders");
    queryp-> exec();
    queryp-> next();
    modelPrices-> setQuery(*queryp);
    ui-> profitsTableView-> setModel(modelPrices);
    ui-> profitsTableView-> resizeColumnsToContents();
    ui-> profitsTableView-> resizeRowsToContents();

    // Calculate sum
    queryp-> prepare("SELECT SUM(total_price) FROM orders");
    queryp-> exec();
    queryp-> next();
    QString profitsSumLabelText = "SUM = " + queryp-> value(0).toString();
    ui-> profitsSumLabel-> setText(profitsSumLabelText);

    // Populate profits shop id combo box
    QSqlQueryModel *modelShops = new QSqlQueryModel();
    queryp-> prepare("SELECT id FROM shops");
    queryp-> exec();
    queryp-> next();
    modelShops-> setQuery(*queryp);
    ui-> profitsShopComboBox-> setModel(modelShops);

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

void Profits::on_profitsShopComboBox_activated(const QString &arg1)
{
    // Open DB
    MainWindow mainWindow;
    if(!mainWindow.openConnection())
    {
        this->close();
        qDebug()<<("Failed open db bikes");
    }

    QSqlQueryModel *modelPrices = new QSqlQueryModel();
    QSqlQuery *queryp = new QSqlQuery(mainWindow.db);

    // Get list of prices of rented bikes for the shop
    queryp-> prepare("SELECT o.total_price FROM orders o INNER JOIN rented_bikes rb ON o.id = rb.order_id INNER JOIN bikes b ON rb.bike_id = b.id WHERE b.shop_id = '" + arg1 + "'");
    queryp-> exec();
    queryp-> next();
    modelPrices-> setQuery(*queryp);
    ui-> profitsTableView-> setModel(modelPrices);
    ui-> profitsTableView-> resizeColumnsToContents();
    ui-> profitsTableView-> resizeRowsToContents();

    // Calculate sum
    queryp-> prepare("SELECT SUM(o.total_price) FROM orders o INNER JOIN rented_bikes rb ON o.id = rb.order_id INNER JOIN bikes b ON rb.bike_id = b.id WHERE b.shop_id = '" + arg1 + "'");
    queryp-> exec();
    queryp-> next();
    QString profitsSumLabelText = "SUM = " + queryp-> value(0).toString();
    ui-> profitsSumLabel-> setText(profitsSumLabelText);

    mainWindow.closeConnection();
}
