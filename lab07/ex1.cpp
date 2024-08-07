#include<cstdio>
void displaySquare(int side=4, char filledCharacter='*') {
	for(int i=0;i<side;i++) {
		for(int j=0;j<side;j++) {
			putchar(filledCharacter);
		}
		putchar('\n');
	}
}
int main() {
	int s;
	char c;
	scanf("%d %c",&s,&c);
	displaySquare(s,c);
	displaySquare();
}
