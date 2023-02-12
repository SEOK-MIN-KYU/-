#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int n, i;
	int* p1, * p2;
	scanf("%d", &n);
	p1 = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &p1[i]);
	p2 = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &p2[i]);
	for (i = 0; i < n; i++)
		printf(" %d", p1[i] + p2[n - i - 1]);
	free(p1);
	free(p2);
	return 0;
}