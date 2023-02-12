#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Hanoi(int n, char a, char b, char c) {
	if (n == 1)
		printf("%c %c\n", a, c);
	else {
		Hanoi(n - 1, a, c, b);
		printf("%c %c\n", a, c);
		Hanoi(n - 1, b, a, c);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	Hanoi(n, 'A', 'B', 'C');
	return 0;
}