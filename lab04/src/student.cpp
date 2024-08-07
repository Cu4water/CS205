#ifndef ALGORITHM
#define ALGORITHM
#include<algorithm>
#endif
#ifndef CSTRING
#include<cstring>
#define CSTRING
#endif
#ifndef STUDENT
#define STUDENT
#include"student.hpp"
#endif
#ifndef READ
#define READ
#include"read.hpp"
#endif

void inputstu(stuinfo *stu,int n){
    for(int i=0;i<n;i++){
        printf("name: ");
        gets(stu[i].name);
        printf("score: ");
        stu[i].score[0]=read();
        stu[i].score[1]=read();
        stu[i].score[2]=read();
        stu[i].ave=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
    }
}
void showstu(stuinfo *stu , int n){
    for(int i=0;i<n;i++){
        printf("name: %s\nscore: %d %d %d\naverage: %lf\n",stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].ave);
    }
}
void sortstu(stuinfo *stu,int n){
    std::sort(stu,stu+n);
}
bool findstu(stuinfo *stu , int n, char *str_name){
    for(int i=0;i<n;i++){
        if(!strcmp(stu[i].name,str_name)){
            printf("name: %s\nscore: %d %d %d\naverage: %lf\n",stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].ave);
            return true;
        }
    }
    return false;
}
bool operator > (const stuinfo &a,const stuinfo &b){
    return a.ave>b.ave;
}
bool operator < (const stuinfo &a,const stuinfo &b){
    return a.ave<b.ave;
}