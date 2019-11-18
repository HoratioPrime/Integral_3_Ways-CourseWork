#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QtCharts>
using namespace QtCharts;


class Graphic
{
public:
    Graphic();

    void show();
    auto getAxisX() const ;//  {return axisX;}
    auto getAxisY() const ;//  {return axisY;}
    void settleDownAxis();

    QChartView* getChartView()   ;//  {return chartView;}

    //void setXRange(double left, double right) {axisX->setRange(left-5, right+5);}

    void addSeries(QLineSeries* series);
    void removeSeries()                 {chart->removeAllSeries();}
private:

    void setAxis(QValueAxis* axis);

    QChart*          chart;
    QChartView*      chartView;
    QValueAxis*      axisX;
    QValueAxis*      axisY;
};

#endif // GRAPHIC_H
