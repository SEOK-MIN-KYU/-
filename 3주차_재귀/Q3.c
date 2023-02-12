#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int digit(int n) {
	if (n < 10)
		printf("%d\n", n);
	else {
		printf("%d\n", n % 10);
		digit(n / 10);
	}

}
int main() {
	int n;
	scanf("%d", &n);
	digit(n);
	return 0;
}