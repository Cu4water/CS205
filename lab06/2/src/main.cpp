#ifndef CSTDIO
#define CSTDIO
#include<cstdio>
#endif
#ifndef MATCH
#define MATCH
#include"match.h"
#endif
char c[100010];
void gets(char *s)
{
    char ch=getchar(),i=0;
    while(ch!='\n')
    {
        s[i++]=ch;
        ch=getchar();
    }
    s[i]=0;
}
int main()
{
    puts("input string");
    gets(c);
    puts("input ch");
    char *ans=match(c,getchar());
    if(ans!=NULL) puts(ans);
    else puts("not found");
}