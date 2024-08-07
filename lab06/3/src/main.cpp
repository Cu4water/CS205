#ifndef CSTDIO
#define CSTDIO
#include<cstdio>
#endif
#ifndef POINT 
#define POINT
#include"point.h"
#endif
int main()
{
    float x1,x2,y1,y2;
    point p1,p2;
    point *pp1=&(p1);
    point *pp2=&(p2);
    scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
    SetPoint(x1,y1,p1);
    SetPoint(x2,y2,p2);
    printf("%f",Distance(pp1,pp2));
}