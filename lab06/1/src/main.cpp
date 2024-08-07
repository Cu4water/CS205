#ifndef CSTDIO
#define CSTDIO
#include<cstdio>
#endif
#ifndef SWAP
#define SWAP
#include"swap.h"
#endif
int main()
{
    int a=2;
    int b=1;
    Swap2(a,b);
    printf("%d %d\n",a,b);
    a=2;
    b=1;
    int *aa=&(a);
    int *bb=&(b);
    Swap3(aa,bb);
    printf("%d %d\n",*aa,*bb);
}