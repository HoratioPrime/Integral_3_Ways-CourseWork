#include "graphic.h"

Graphic::Graphic()
{
    chart = new QChart();
    chartView = new QChartView(chart);

    axisX = new QValueAxis();
    axisY = new QValueAxis();
    axisX->setTitleText("X");
    axisY->setTitleText("Y");
    setAxis(axisX);
    setAxis(axisY);

    /*
    axisX = new QValueAxis();
    axisX->setGridLineVisible(false);
    axisX->setTitleText("X");
    axisX->setTitleBrush(QBrush(QColor().fromRgb(155,155,155)));


    axisY = new QValueAxis();
    axisY->setGridLineVisible(false);
    axisY->setTitleText("Y");
    axisY->setTitleBrush(QBrush(QColor().fromRgb(155,155,155)));
    */

    chart->legend()->hide();
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    chartView->setRenderHint(QPainter::Antialiasing);
}

void Graphic::addSeries(QLineSeries *series)
{
    chart->setBackgroundBrush(QBrush(QColor().fromRgb(37,37,37)));
    chartView->setBackgroundBrush(QBrush(QColor().fromRgb(37,37,37)));
    chart->addSeries(series);

    series->attachAxis(axisX);
    series->attachAxis(axisY);
}

void Graphic::setAxis(QValueAxis* axis)
{
    axis->setGridLineVisible(false);
    axis->setTitleBrush(QBrush(QColor().fromRgb(155,155,155)));
    axis->setLabelsBrush(QBrush(QColor().fromRgb(155,155,155)));
}

void Graphic::show()
{
    chartView->show();
}

auto Graphic::getAxisX() const   {return axisX;}
auto Graphic::getAxisY() const   {return axisY;}

void Graphic::settleDownAxis()
{
    delete axisX;
    delete axisY;
    axisX = new QValueAxis();
    axisY = new QValueAxis();
    axisX->setTitleText("X");
    axisY->setTitleText("Y");
    setAxis(axisX);
    setAxis(axisY);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

}

QChartView* Graphic::getChartView()     {return chartView;}
