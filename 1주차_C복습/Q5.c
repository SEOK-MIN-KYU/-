#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct time {
	int h, m, s;
};
int main() {
	int s1, s2, n;
	struct time t1, t2;
	scanf("%d %d %d", &t1.h, &t1.m, &t1.s);
	scanf("%d %d %d", &t2.h, &t2.m, &t2.s);
	s1 = t1.h * 3600 + t1.m * 60 + t1.s;
	s2 = t2.h * 3600 + t2.m * 60 + t2.s;
	n = s2 - s1;
	printf("%d %d %d", n / 3600, n % 3600 / 60, n % 60);
	return 0;
}