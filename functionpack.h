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
        path("C:/Users/Horatio/source/Integral_3_ways-CourseWork/img/FunctionsBlack/Asset_" + title + "@2x.png"),
        whitePath("C:/Users/Horatio/source/Integral_3_ways-CourseWork/img/FunctionsWhite/Asset_" + title + "@4x.png"),
        title(title){}

    decltype(auto) getFunc()        {return func;}
    decltype(auto) getPath()        {return path;}
    decltype(auto) getWhitePath()   {return whitePath;}
    decltype(auto) getTitle()       {return title;}


private:
    function<double(double)> func;
    string path;
    string whitePath;
    string title;
};

class FunctionPack
{
public:
    FunctionPack();
    void next();
    void prev();
    Function getCurrentFunc();
    Function getFuncByIdx(int idx)     const;
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
