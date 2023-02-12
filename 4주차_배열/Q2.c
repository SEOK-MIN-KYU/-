#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int n, m, a, b, i, j, tmp, ary[100], ary1[100];
	int* p;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
		ary1[i] = ary[i];
	}
	scanf("%d", &m);
	p = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < m; i++)
		scanf("%d", &p[i]);
	for (i = 0; i < m - 1; i++)
		ary[p[i + 1]] = ary1[p[i]];
	for (i = 0; i < n; i++)
		printf(" %d", ary[i]);
	free(p);
	return 0;
}