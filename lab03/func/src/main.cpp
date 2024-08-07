#include<cstdio>
int mul(int k)
{
	if(!k) return 1;
	return k*mul(k-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	printf("%d!=%d\n",i,mul(i));
}
