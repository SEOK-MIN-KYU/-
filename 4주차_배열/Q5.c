#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int n, m, i, j;
	int c = 1, k = 0;
	int** p;
	scanf("%d %d", &n, &m);
	p = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		p[i] = (int*)malloc(sizeof(int) * m);

	while (1) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if ((i + j) == k) {
					p[i][j] = c++;
				}
			}
		}
		k++;
		if (c == n * m + 1) break;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf(" %d", p[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < n; i++)
		free(p[i]);
	free(p);
	return 0;
}