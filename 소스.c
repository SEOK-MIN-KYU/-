#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int sum(int n) {
	int i, s = 0;
	for (i = 1; i <= n; i++)
		s += i;
	return s;
}
int main() {
	int n, i, s = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		s += sum(i);
	printf("%d", s);
	return 0;
}