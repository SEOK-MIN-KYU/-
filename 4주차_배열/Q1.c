#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int n, m, a, b, i, j, tmp, ary[100];
	int* p;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &ary[i]);
	scanf("%d", &m);
	p = (int*)malloc(sizeof(int) * m * 2);
	for (i = 0; i < m * 2; i++)
		scanf("%d", &p[i]);
	for (i = 0; i < m * 2; i += 2) {
		a = p[i];
		b = p[i + 1];
		for (j = 0; j < (b - a + 1) / 2; j++) {
			tmp = ary[j + a];
			ary[j + a] = ary[b - j];
			ary[b - j] = tmp;
		}
	}
	for (i = 0; i < n; i++)
		printf(" %d", ary[i]);
	free(p);
	return 0;
}