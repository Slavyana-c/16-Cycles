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

    ui-> plot-> addGraph();
    ui-> plot-> addGraph();
    ui-> plot-> addGraph();
    ui-> plot-> addGraph();

    ui-> plot-> graph(0)-> setName("All Shops");
    ui-> plot-> graph(1)-> setName("Shop 1");
    ui-> plot-> graph(2)-> setName("Shop 2");
    ui-> plot-> graph(3)-> setName("Shop 3");

    ui-> plot-> graph(0)-> setLineStyle(QCPGraph::lsLine);
//    ui-> plot-> graph(0)-> setPen(QPen(Qt::magenta));
//    ui-> plot-> graph(0)-> setBrush(QBrush(Qt::darkMagenta));

    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("yyyy/MM/dd");
    ui-> plot-> xAxis-> setTicker(dateTicker);
    ui-> plot-> graph(0)-> rescaleAxes(true);

    ui-> plot-> graph(0)-> setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross));

    ui-> plot-> xAxis-> setTickLabelFont(QFont(QFont().family(),10));
    ui-> plot-> yAxis-> setTickLabelFont(QFont(QFont().family(),10));

    ui-> plot-> xAxis-> setLabel("Date");
    ui-> plot-> yAxis-> setLabel("profit");

    ui-> plot-> legend-> setVisible(true);
    ui-> plot-> legend-> setBrush(QColor(255,255,255,150));

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
    query.prepare("SELECT SUM(o.total_price) FROM orders o INNER JOIN rented_bikes rb ON o.id = rb.id INNER JOIN bikes b ON rb.bike_id = b.id WHERE b.shop_id = '" + shopID + "' AND date BETWEEN '" + dateOne + " 00:00:00' AND '" + dateTwo + " 00:00:00'");

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

void Profits::on_graphsRefreshButton_clicked()
{

    while(!x.isEmpty())
    {
        x.remove(0);
    }
    while(!y.isEmpty())
    {
        y.remove(0);
    }
    ui->label->setText("started");

//    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
//    dateTicker->setDateTimeFormat("yyyy/MM/dd");
//    ui-> plot-> xAxis-> setTicker(dateTicker);

//    ui-> plot-> graph(0)-> setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross));

//    ui-> plot-> xAxis-> setRange(x.first()-24*60*60,x.last(tring(startDate,"yyyy/MM/dd");)+24*60*60);
//    ui-> plot-> yAxis-> setRange(0,10);





//    ui-> plot-> legend-> setVisible(true);
//    ui-> plot-> legend-> setBrush(QColor(255,255,255,150));

    ui->label->setText("added graph");

    QString startDate, endDate;
    startDate = ui-> startDateLineEdit-> text();
    endDate = ui-> endDateLineEdit-> text();

    ui->label->setText("got dates as " + startDate + endDate);

    if(startDate.length() < 0 || endDate.length() < 0)
    {
        return;
    }

    QDateTime time1,time2;
    time1 = QDateTime::fromString(startDate,"yyyy-MM-dd");
    time2 = QDateTime::fromString(endDate,"yyyy-MM-dd");



    ui->label->setText(time1.toString("yyyy/MM/dd") + time2.toString("yyyy/MM/dd"));

    // Open DB
    MainWindow mainWindow;
    if(!mainWindow.openConnection())
    {
        this->close();
        qDebug()<<("Failed open db bikes");
    }

    QSqlQuery query;

    for(double j = time1.toTime_t(); j + 7*24*60*60 < time2.toTime_t(); j = j + 7*24*60*60)
    {
        QDateTime firstDate,secondDate;
        firstDate.setTime_t(int(j));
        secondDate.setTime_t(int((j + 7*24*60*60) - 1));
        QString firstDateAsString = firstDate.toString("yyyy-MM-dd");
        QString secondDateAsString = secondDate.toString("yyyy-MM-dd");
        ui->label->setText(secondDateAsString);

        query.prepare("SELECT SUM(o.total_price) FROM orders o WHERE date BETWEEN '" + firstDateAsString + " 00:00:00' AND '" + secondDateAsString + " 00:00:00'");
        query.exec();
        query.next();
        x.append(j);
        y.append(query.value(0).toDouble());
    }

    QString t1string = QString::number(time1.toTime_t());
    QString t2string = QString::number(time2.toTime_t());

    //ui->label->setText("yes " + t1string + " " + t2string);

    ui-> plot-> graph(0)-> setData(x,y);
//    ui-> plot-> xAxis-> setRange(x.first()-24*60*60,x.last()+24*60*60);
//    ui-> plot-> yAxis-> setRange(0,y.last());
    ui-> plot-> rescaleAxes(true);
    ui-> plot-> replot();
    ui-> plot-> update();





    mainWindow.closeConnection();
}
