#ifndef CSTRING
#define CSTRING
#include<cstring>
#endif
char *match(char *s,char ch)
{
    int len=strlen(s);
    for(int i=0;i<len;i++)
        if(s[i]==ch) return s+i;
    return NULL;
}