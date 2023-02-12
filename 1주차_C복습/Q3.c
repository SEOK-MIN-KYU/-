#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(int* pa, int* pb) {
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
int main() {
	int n, a, b, i, ary[50];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &ary[i]);
	scanf("%d %d", &a, &b);
	swap(ary + a, ary + b);
	for (i = 0; i < n; i++)
		printf(" %d", ary[i]);
	return 0;
}