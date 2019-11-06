
#include "integral.h"


QGraphicsScene*     Integral::scene;
int                 Integral::currentIdx = -1;
int                 Integral::cx;
int                 Integral::cy;
QPen                Integral::pen;

Integral::Integral()
{
    currentIdx++;

}

double Integral::execute()
{


    //executed = true;
    Integral::scene->clear();
    //Integral::scene->addLine(0, sin(i),
      //                       0, sin(i), QPen(QColor().fromRgb(155,155,155)));




    int i; // счётчик
    double n; // задаём число разбиений n
    n = (b - a) / h;
    double x0 = a;

    double kx = 0.;
    double ky = 0.;

    if(a < 0 && b <= 0 && abs(a) < cx/4 && abs(a) > cx/2)
    {
        kx = abs((cx*3/8)/a);
    }else if(a >= 0 && b > 0 && abs(b) < cx/4 && abs(b) > cx/2)
    {
        kx = (cx*3/8)/b;
    }else{
        if(abs(a) > b)
        {
            kx = abs((cx*3/8)/a);
        }else
        {
            kx = kx = (cx*3/8)/b;
        }
    }

    int k = 50; // увеличение графика
    double x = 0.;
    double fRes = 0.;


    switch(currentMethod){
    case METHOD::AVERAGE:
       /* while(j < cx*2)
        {
            if( (j >= a+cx) && (j <= b+cx) )
            {
                j+= b - a + h;*/
                for (i = 1; i <= n; i++)
                {
                    x = a + h * (i - 0.5);
                    fRes = c * func(d*x);
                    res +=  h * fRes;
                    if(-k*fRes+cy > 0 && -k*fRes+cy < cy*2)
                    {

                        pen.setColor(QColor().fromRgb(41,98,255));
                        Integral::scene->addLine(kx*x+cx, cy,
                                                kx*x+cx, -k*(fRes)+cy, pen);
                        pen.setColor(QColor().fromRgb(255,255,255));
                        Integral::scene->addLine(kx*x+cx, -k*fRes+cy,
                                                kx*x+cx, -k*fRes+cy, pen);

                    }

                }
           /*     prevPY = -k*fRes;
                pen.setColor(QColor().fromRgb(255,255,255));
            }
            x = j-cx;
            fRes = c * func(d*x);
            if(-k*fRes+cy > 0 && -k*fRes+cy < cy*2 && prevPY + cy > 0 && prevPY + cy < cy*2 && j != 0.)
            {
                Integral::scene->addLine(k*(x-h)+cx, prevPY+cy,
                                        k*x+cx, -k*fRes+cy, pen);
            }
            prevPY = -k*fRes;
            j+= h;
        }*/
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

    double j = 0;
    double prevPY = 0.;
    pen.setColor(QColor().fromRgb(255,255,255));
    while(j < cx*2)
    {
         prevPY = -k*fRes;
         x = j-cx;
         fRes = c * func(d*x);
         if(-k*fRes+cy > 0 && -k*fRes+cy < cy*2 && prevPY + cy > 0 && prevPY + cy < cy*2 && j != 0.)
         {
             Integral::scene->addLine(kx*(x-h)+cx, prevPY+cy,
                                     kx*x+cx, -k*fRes+cy, pen);
         }
         prevPY = -k*fRes;
         j+= h;
    }

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
