#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int* prefixAverages1(int* X, int n) {
	int i, j, sum;
	int* A;
	A = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++) {
			sum += X[j];
		}
		A[i] = (int)((float)sum / (i + 1) + 0.5);
	}
	return A;
}
int* prefixAverages2(int* X, int n) {
	int i, j, sum = 0;
	int* A;
	A = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		sum += X[i];
		A[i] = (int)((float)sum / (i + 1) + 0.5);
	}
	return A;
}
int main() {
	int n, i;
	int* X;
	int* A1, * A2;
	scanf("%d", &n);
	X = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &X[i]);
	A1 = prefixAverages1(X, n);
	A2 = prefixAverages2(X, n);
	for (i = 0; i < n; i++)
		printf("%d ", A1[i]);
	printf("\n");
	for (i = 0; i < n; i++)
		printf("%d ", A2[i]);
	free(X);
	free(A1);
	free(A2);
	return 0;
}