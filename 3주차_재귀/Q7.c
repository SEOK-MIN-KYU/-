#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int count(char str[], char c, int l) {
	if (l == 1) {
		if (str[0] == c)
			return 1;
		else
			return 0;
	}
	else {
		if (str[l - 1] == c)
			return 1 + (count(str, c, l - 1));
		else
			return 0 + (count(str, c, l - 1));
	}

}
int main() {
	char c, str[100];
	scanf("%s", str);
	getchar();
	scanf("%c", &c);
	printf("%d", count(str, c, strlen(str)));
	return 0;
}