#include "functionpack.h"

FunctionPack::FunctionPack()
{

}

void FunctionPack::next()
{
    if(currentFuncIdx == functions.size() - 1)
    {
        currentFuncIdx = 0;
    }else
    {
        currentFuncIdx++;
    }
}

void FunctionPack::prev()
{
    if(currentFuncIdx == 0)
    {
        currentFuncIdx = functions.size() - 1;
    }else
    {
        currentFuncIdx--;
    }
}

Function FunctionPack::getCurrentFunc()
{
    return functions[currentFuncIdx];
}


