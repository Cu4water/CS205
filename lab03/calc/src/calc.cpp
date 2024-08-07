#ifndef CALC
#define CALC
#include"calc.hpp"
#endif
int calc(char opt,int a,int b)
{
    if(opt=='+') return a+b;
    if(opt=='-') return a-b;
    if(opt=='*') return a*b;
    if(opt=='/') return a/b;
    if(opt=='%') return a%b;
    return 0;
}