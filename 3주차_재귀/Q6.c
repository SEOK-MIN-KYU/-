#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int gcd(int a, int b) {
	if (a > b) {
		if (b == 0)
			return a;
		else
			return gcd(b, a % b);
	}
	else {
		if (a == 0)
			return b;
		else
			return gcd(a, b % a);
	}
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", gcd(a, b));
	return 0;
}