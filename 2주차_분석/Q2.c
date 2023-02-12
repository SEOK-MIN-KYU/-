#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int mostOnes(int** A, int n) {
	int i = 0, j = 0, r = 0;
	while (i < n && j < n) {
		if (A[i][j] == 0)
			i++;
		else {
			r = i;
			j++;
		}
	}
	return r;
}
int main() {
	int n, i, j;
	int** A;
	scanf("%d", &n);
	A = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		A[i] = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	}
	printf("%d", mostOnes(A, n));
	for (i = 0; i < n; i++)
		free(A[i]);
	free(A);
	return 0;
}