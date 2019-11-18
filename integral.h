#ifndef INTEGRAL_H
#define INTEGRAL_H
#include "functionpack.h"

#include <functional>
#include <cmath>
#include <vector>
#include <QGraphicsScene>


#include <QtCharts>
using namespace QtCharts;


enum class METHOD{AVERAGE, SIMPSON, NEWTON_COTES};

class Integral
{
public:
    Integral();
    //~Integral();
    double         execute();
    void           setParameters(double a = 0., double b = 1., double c = 1., double d = 1.);
    void           setMethod(METHOD method);
    void           setFunc(std::function<double(double)> func = sin);
    void           setIdxOfFunc(short idx = 0);
    void           setStep(double step);
    void           attachAxis(QValueAxis* axisX, QValueAxis* axisY);

    decltype(auto) getMethod()  const       {return currentMethod;}
    decltype(auto) getA()       const       {return a;}
    decltype(auto) getB()       const       {return b;}
    decltype(auto) getC()       const       {return c;}
    decltype(auto) getD()       const       {return d;}
    decltype(auto) getH()       const       {return h;}
    decltype(auto) getN()       const       {return n;}
    decltype(auto) getCurrFunc()const       {return func;}
    decltype(auto) getSeries()              {return series;}
    decltype(auto) getIdxOfFunc()const      {return idxOfFunc;}
    double         getRes()     const;

    void constructSeries();

    //decltype(auto) isExecuted() {return executed;}
    static int              currentIdx;
    //static QGraphicsScene*  scene;
    static QPen             pen;


private:
    METHOD currentMethod = METHOD::AVERAGE;

    std::function<double(double)> func = sin;
    short idxOfFunc = 0;

    //qchart
    QLineSeries*            series;
    QLineSeries*            backSeries;

    double  a    = 0.;  //  left limit
    double  b    = 1.;  //  right limit
    double  c    = 1.;  //  outfunction coefficient
    double  d    = 1.;  //  infunction coefficient
    double  h    = 0.1; //  step/precision
    int     n    = 1;   //  quantity of partitions
    double res = 0.;    //  result of calculations

    //bool executed = false;
};

#endif // INTEGRAL_H
