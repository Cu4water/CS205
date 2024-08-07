#ifndef STEREO
#define STEREO
#include"stereo.hpp"
#endif

int CStereoShape::used_time=0;
int main()
{
    CCube cube1(4,5,6);
    CSphere sphere1(7.9);
    CStereoShape *p = &(cube1);
    p->Show();
    printf("%.2f %.2f\n",p->GetArea(),p->GetVol());
    p=&(sphere1);
    p->Show();
    printf("%d objects are created\n",p->GetNumOfObject());
    return 0;
}