#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#define base 100000000
#define width 8
using namespace std;
struct Bignum
{
    long long data[20010],lg;
    Bignum (string t="")
    {
        memset(data,0,sizeof(data));
        int x=t.size()%width;
        lg=(bool)(x)+t.size()/width;
        for (int i=0;i<x;++i)
        	data[lg]=(data[lg]<<3)+(data[lg]<<1)+t[i]-'0';
        for (int i=x;i<t.size();++i)
        	data[lg-(i-x)/width-(bool)(x)]=(data[lg-(i-x)/width-(bool)(x)]<<3)+(data[lg-(i-x)/width-(bool)(x)]<<1)+t[i]-'0';
    }
    Bignum operator * (Bignum b)
    {
        Bignum tmp;
        tmp.lg=lg+b.lg;
        for (int i=1;i<=lg;++i)
            for (int j=1;j<=b.lg;++j)
            {
                tmp.data[i+j-1]+=data[i]*b.data[j];
                int pos=i+j-1;
                while (tmp.data[pos]>=base)
                    tmp.data[pos+1]+=tmp.data[pos]/base,tmp.data[pos]%=base,++pos;
            }
        while (!tmp.data[tmp.lg])
            --tmp.lg;
        return tmp;
    }
    void write()
    {
        printf("%lld",data[lg]);
        for (register int i=lg-1;i>=1;--i)
            printf("%08lld",data[i]);
        printf("\n");
	}
};
int main()
{
    int n;
    string as,bs;
    cin>>n>>as>>bs;
    Bignum a(as),b(bs),c=a*b;
    c.write();
    return 0;
}