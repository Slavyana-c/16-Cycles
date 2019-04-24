#include "piechartwidget.h"

#include <QPainter>

PieChartWidget::PieChartWidget(QWidget *parent) : QWidget(parent)
{

}

void PieChartWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRectF size = QRectF(10,10,this-> width()-10, this->width()-10);
    painter.setBrush(Qt::red);
    painter.drawPie(size,0,90*16); // size, starting angle, angle span units in 16ths of a degree
    painter.setBrush(Qt::blue);
    painter.drawPie(size,90*16,270*16);
}

