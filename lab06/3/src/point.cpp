#ifndef MATH
#define MATH
#include<cmath>
#endif
#ifndef POINT
#define POINT
#include"point.h"
#endif
point SetPoint(const float x,const float y,point &p){
    p.x=x;
    p.y=y;
}
float Distance(const point *a,const point *b){
    return sqrt((a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y));
}