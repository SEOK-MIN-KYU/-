#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void ABC(int ary[], int k) {
	int i, tmp;
	int j = k;
	int m = ary[k];
	for (i = k; i < 10; i++) {
		if (ary[i] > m) {
			m = ary[i];
			j = i;
		}
	}
	tmp = ary[k];
	ary[k] = ary[j];
	ary[j] = tmp;
}
int main() {
	int ary[10], k;
	for (k = 0; k < 10; k++)
		scanf("%d", &ary[k]);
	for (k = 0; k < 10; k++)
		ABC(ary, k);
	for (k = 0; k < 10; k++)
		printf(" %d", ary[k]);
	return 0;
}