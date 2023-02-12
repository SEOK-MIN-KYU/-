#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int n, m = 0, i, j, ary[10000];
	scanf("%d", &n);
	for (i = 0; i < n * n; i++)
		ary[i] = i + 1;
	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (j = m; j < m + n; j++) {
				printf(" %d", ary[j]);
			}
		}
		else {
			for (j = m + n - 1; j >= m; j--) {
				printf(" %d", ary[j]);
			}
		}
		m += n;
		printf("\n");
	}
	return 0;
}