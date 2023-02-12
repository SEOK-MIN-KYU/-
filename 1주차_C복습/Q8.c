#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student {
	char name[7];
	int k, e, m;
	float a;
};
int main() {
	int n, i;
	struct student* p;
	scanf("%d", &n);
	p = (struct student*)malloc(sizeof(struct student) * n);
	for (i = 0; i < n; i++)
		scanf("%s %d %d %d", p[i].name, &p[i].k, &p[i].e, &p[i].m);
	for (i = 0; i < n; i++) {
		p[i].a = (float)(p[i].k + p[i].e + p[i].m) / 3;
		printf("%s %.1f", p[i].name, p[i].a);
		if (p[i].k >= 90 || p[i].e >= 90 || p[i].m >= 90)
			printf(" GREAT");
		if (p[i].k < 70 || p[i].e < 70 || p[i].m < 70)
			printf(" BAD");
		printf("\n");
	}
	free(p);
	return 0;
}