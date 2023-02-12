#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student {
	char name[9];
	int s;
};
int main() {
	int i, a = 0;
	struct student s[5];
	for (i = 0; i < 5; i++) {
		scanf("%s %d", s[i].name, &s[i].s);
		a += s[i].s;
	}
	a /= 5;
	for (i = 0; i < 5; i++) {
		if (s[i].s <= a)
			printf("%s\n", s[i].name);
	}
	return 0;
}