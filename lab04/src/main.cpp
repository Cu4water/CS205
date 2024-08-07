#ifndef CSTDIO
#define CSTDIO
#include<cstdio>
#endif
#ifndef CSTRING
#define CSTRING
#include<cstring>
#endif
#ifndef READ
#define READ
#include"read.hpp"
#endif
#ifndef STUDENT
#define STUDENT
#include"student.hpp"
#endif
const int maxn=100010;
stuinfo students[maxn];
int main()
{
    int n=read();
    printf("Please input %d students\n",n);
    inputstu(students,n);
    puts("information:");
    showstu(students,n);
    puts("sorted:");
    sortstu(students,n);
    showstu(students,n);
    char tmp[10010];
    gets(tmp);
    if(!findstu(students,n,tmp))
        puts("no");
}
