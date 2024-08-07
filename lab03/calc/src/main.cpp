#ifndef CSTDIO
#define CSTDIO
#include<cstdio>
#endif
#ifndef READ
#define READ
#include"read.hpp"
#endif
#ifndef CALC
#define CALC
#include"calc.hpp"
#endif
int main()
{
    char c=getchar();
    int a,b;
    a=read();
    b=read();
    printf("%d",calc(c,a,b));
}