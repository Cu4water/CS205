#include<cstdio>
struct DayInfo{
    enum Days { SATURDAY,SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY };
    enum Weather {Sunny, Rainy };
    int thisday,thiswea;
};
bool canTrival(DayInfo today){
    return (today.thisday==0||today.thisday==1)&&(today.thiswea==0);
}
#include<iostream>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    DayInfo tmp;
    tmp.thisday=a;
    tmp.thiswea=b;
    std::cout<<canTrival(tmp)<<std::endl;
}