
#include "integral.h"
#include <iostream>

//QGraphicsScene*     Integral::scene;
QPen                Integral::pen;

//qchart
//QChart*          Integral::chart;
//QChartView*      Integral::chartView;
//QValueAxis*      Integral::axisX;
//QValueAxis*      Integral::axisY;

int                 Integral::currentIdx = -1;
//int                 Integral::cx;
//int                 Integral::cy;


Integral::Integral()
{
    series = new QLineSeries();
    series->setColor(QColor().fromRgb(235,235,235));
    backSeries = new QLineSeries();
}


double Integral::execute()
{

    int i; // счётчик
    //double n; // задаём число разбиений n
    n = (b - a) / h;
    double x0 = a;

    //int k = 50; // увеличение графика
    double x = 0.;
    double fRes = 0.;


    switch(currentMethod){
    case METHOD::AVERAGE:

        for (i = 1; i <= n; i++)
        {
            x = a + h * (i - 0.5);
            fRes = c * func(d*x);
            res +=  h * fRes;
        }
        break;

    case METHOD::SIMPSON:
        for (i = 0; i <= n-1; i++)
        {
            res += func(d*x0) + 4.*func(d*(x0 + h/2.)) + func(d*(x0+h));
            x0 += h;
        }
        res *= c*(h/6.);
        break;

    case METHOD::NEWTON_COTES:
        int m = 5.;
        for(i = 0; i <= n-1; i++)
        {
            res += 19.*func(d*x0)
                    + 75.*func(d*(x0 + h/m))
                    + 50.*func(d*(x0 + 2.*h/m))
                    + 50.*func(d*(x0 + 3.*h/m))
                    + 75.*func(d*(x0 + 4.*h/m))
                    + 19.*func(d*(x0 + h)) ;
            x0 += h;
        }
        res *= c*h/288.;
        break;
    }
    //constructSeries();
    return res;
}

void Integral::setMethod(METHOD method)
{
    this->currentMethod = method;
}

void Integral::setFunc(std::function<double (double)> func)
{
    this->func = func;
}

void Integral::setIdxOfFunc(short idx)
{
    idxOfFunc = idx;
}

void Integral::setStep(double step)
{
    h = step;
}

void Integral::attachAxis(QValueAxis *axisX, QValueAxis *axisY)
{
    series->attachAxis(axisX);
    series->attachAxis(axisY);
}

void Integral::setParameters( double a, double b, double c, double d)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

double Integral::getRes() const
{
    return res;
}

void Integral::constructSeries()
{
    series = new QLineSeries();
    series->setColor(QColor().fromRgb(235,235,235));
    double indent = (b - a)/2.;
    double j = a - indent;
    double fRes = 0.;
    double x = 0.;
    while(j < b + indent)
    {
        x = j;
        fRes = c * func(d*x);
        series->append(x, fRes);
        j+= h;
    }
    return;
}
