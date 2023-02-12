#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int MAX(int n, int ary[]) {
	int m;
	if (n == 1)
		return ary[0];
	m = MAX(n - 1, ary);
	if (ary[n - 1] > m)
		return ary[n - 1];
	else
		return m;
}
int main() {
	int n, i, ary[20];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &ary[i]);
	printf("%d", MAX(n, ary));
	return 0;
}
