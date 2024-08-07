#ifndef CSTDIO
#define CSTDIO
#include<cstdio>
#endif

class CStereoShape {
    private:
        static int used_time;
    public:
        CStereoShape(){used_time++;}
        int GetNumOfObject() {return used_time;}
        virtual float GetArea() = 0;
        virtual float GetVol() = 0;
        virtual void Show() = 0;
};


class CCube: public CStereoShape {
    private:
        float a,b,c;
    public:
        CCube(float aa, float bb, float cc):CStereoShape(), a(aa), b(bb), c(cc) {}
        float GetArea() {return (a*b+b*c+c*a)*2;}
        float GetVol() {return a*b*c;}
        void Show() {printf("The 3 lengths of this cube is: %.2f, %.2f, %.2f\n",a,b,c);}
};

class CSphere: public CStereoShape {
    private:
        float r;
    public:
        CSphere(float rr):CStereoShape(), r(rr) {}
        float GetArea() {return 4*3.1415926*r*r;}
        float GetVol() {return 3.1415926*r*r*r;}
        void Show() {printf("The r lengths of this thing is: %.2f\n",r);}

};