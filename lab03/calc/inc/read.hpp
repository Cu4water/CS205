#ifndef CSTDIO
#define CSTDIO
#include<cstdio>
#endif
inline int read()
{
    int x=0;
    char c=getchar();
    while(c>57||c<48) c=getchar();
    while(c>47&&c<58) x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return x;
}