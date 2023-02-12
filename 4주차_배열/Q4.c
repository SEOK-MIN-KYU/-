#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int n, m, N, M, i, j;
	int a = 0, b = -1, c = 1, l = 1;
	int** p;
	scanf("%d %d", &n, &m);
	N = n;
	M = m;
	p = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		p[i] = (int*)malloc(sizeof(int) * m);
	while (n > 0 && m > 0) {
		for (i = 0; i < m; i++) {
			b += l;
			p[a][b] = c++;
		}
		n--;
		for (i = 0; i < n; i++) {
			a += l;
			p[a][b] = c++;
		}
		m--;
		l *= -1;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf(" %d", p[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < n; i++)
		free(p[i]);
	free(p);
	return 0;
}