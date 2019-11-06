#ifndef FUNCTIONPACK_H
#define FUNCTIONPACK_H
#include <functional>
#include <vector>
#include <cmath>
using std::function;
using std::string;
using std::vector;

class Function{
public:
    Function(function<double(double)> func, string title):func(func),
        path("C:/Users/Horatio/source/Integral_3_ways-CourseWork/img/Asset_" + title + "@3x.png"),
        title(title){}

   // decltype(auto) operator() (double arg) {return func(arg);}

    decltype(auto) getFunc()    {return func;}
    decltype(auto) getPath()    {return path;}
    decltype(auto) getTitle()   {return title;}

private:
    function<double(double)> func;
    string path;
    string title;
};

class FunctionPack
{
public:
    FunctionPack();
    void next();
    void prev();
    Function getCurrentFunc();
    decltype(auto) getCurrIdx() const {return currentFuncIdx;}

    void setCurrFunc(short currFunc) { currentFuncIdx = currFunc;}

private:
    short currentFuncIdx = 0;
    vector<Function> functions = {Function(sin, "sin"),
                                  Function(exp, "exp"),
                                  Function(log, "ln"),
                                  Function(asin, "arcsin")
                                  };
};

#endif // FUNCTIONPACK_H
