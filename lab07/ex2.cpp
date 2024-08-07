#include<cstdio>
int abs(int p) {
	return p>0?p:-p;
}
int abs(int *p, size_t n) {
	for(int i=0; i<n; i++)
		p[i]=abs(p[i]);
	return 1;
}
int main() {
	int n;
	scanf("%d",&n);
	int a[10010];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	abs(a,n);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
//should be size_t, because int can be negative
