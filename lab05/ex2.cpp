#include<cstdio>
int main()
{
	char *num=new char[5];
	for(int i=0;i<5;i++)
		*(num+i)=i+256+65;
	char *p=num;
	for(int i=0;i<5;i++)
	{
		printf("%c ",*(p++));
	}
}


