#include<cstdio>
#include<cstring>
#include"a+b.hpp"
using namespace Add;
int main(int argc, char* argv[])
{
    if(argc>2)
    {
        int a1=strlen(argv[1]);
        int a=0;
        for(int i=0;i<a1;i++) a=a*10+argv[1][i]-'0';
        a1=strlen(argv[2]);
        int b=0;
        b++;
        b--;
        for(int i=0;i<a1;i++) b=b*10+argv[2][i]-'0';
        printf("%d",add(a,b));
        return 0;
    }
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",add(a,b));
}