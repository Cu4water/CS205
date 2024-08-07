#include<cstdio>
template <typename T>
T min(T a, T b) {
	return a>b?a:b;
}
int main() {
	printf("int min is %d\n", min<int>(1,2));
	printf("char min is '%c'\n", min<char>('1','2'));
	printf("float min is %f\n", min<float>(1.0,2.0));
} 
