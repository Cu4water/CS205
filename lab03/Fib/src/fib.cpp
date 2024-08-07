#ifndef FIB
#define FIB
#include"fib.hpp"
#endif
#ifndef CSTDIO
#define CSTDIO
#include<cstdio>
#endif
int a[10010];
void fib(int n)
{
    a[0]=0;
    a[1]=1;
    a[2]=1;
    for(int i=3;i<=n;i++)
        a[i]=a[i-1]+a[i-2];
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
        if(i%10==0) printf("\n");
    }
}