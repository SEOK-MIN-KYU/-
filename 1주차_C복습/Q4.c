#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int l, i, j;
	char str[100], tmp;
	scanf("%s", str);
	l = strlen(str);
	for (i = 0; i < l; i++) {
		printf("%s\n", str);
		tmp = str[0];
		for (j = 0; j < l - 1; j++) {
			str[j] = str[j + 1];
		}
		str[l - 1] = tmp;
	}
	return 0;
}
