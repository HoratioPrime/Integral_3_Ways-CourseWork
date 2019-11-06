#ifndef INTEGRAL_H
#define INTEGRAL_H
#include "functionpack.h"

#include <functional>
#include <cmath>
#include <vector>
#include <QGraphicsScene>



enum class METHOD{AVERAGE, SIMPSON, NEWTON_COTES};

class Integral
{
public:
    Integral();
    double         execute();
    void           setParameters(double a = 0., double b = 1., double c = 1., double d = 1.);
    void           setMethod(METHOD method);
    void           setFunc(std::function<double(double)> func = sin);
    void           setIdxOfFunc(short idx = 0);
    void           setStep(double step);

    decltype(auto) getMethod()  const       {return currentMethod;}
    decltype(auto) getA()       const       {return a;}
    decltype(auto) getB()       const       {return b;}
    decltype(auto) getC()       const       {return c;}
    decltype(auto) getD()       const       {return d;}
    decltype(auto) getH()       const       {return h;}
    decltype(auto) getCurrFunc()const       {return func;}
    decltype(auto) getIdxOfFunc()const      {return idxOfFunc;}
    double         getRes()     const;



    //decltype(auto) isExecuted() {return executed;}
    static int              currentIdx;
    static QGraphicsScene*  scene;
    static int              cx;
    static int              cy;
    static QPen             pen;
private:
    METHOD currentMethod = METHOD::AVERAGE;

    std::function<double(double)> func = sin;
    short idxOfFunc = 0;

    double a = 0.;
    double b = 1.;
    double c = 1.;
    double d = 1.;
    double h = 0.1;
    double res = 0.;

    //bool executed = false;
};

#endif // INTEGRAL_H
