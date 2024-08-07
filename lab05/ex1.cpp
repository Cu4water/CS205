#include<cstdio>
int main()
{
	int *num=new int[5];
	for(int i=0;i<5;i++)
		*(num+i)=i;
	int *p=num;
	for(int i=0;i<5;i++)
	{
		printf("%d ",*(p++));
	}
}


