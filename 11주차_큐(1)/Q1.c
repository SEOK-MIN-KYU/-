#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int* q, s, f, r;
void PRINTq() {
	int i;
	for (i = 0; i < s; i++) {
		printf(" %d", q[i]);
	}
	printf("\n");
}
int enqueue(int e) {
	if ((r + 1) % s == f) {
		printf("overflow");
		PRINTq();
		return -1;
	}
	else {
		r = (r + 1) % s;
		q[r] = e;
	}
}
int dequeue() {
	int e;
	if (r == f) {
		printf("underflow");
		return -1;
	}
	else {
		e = q[f];
		f = (f + 1) % s;
		q[f] = 0;
		return e;
	}
}
int main() {
	int n, i, e, p;
	char c;
	scanf("%d", &s);
	f = 0;
	r = 0;
	q = (int*)malloc(sizeof(int) * s);
	for (i = 0; i < s; i++) {
		q[i] = 0;
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c", &c);
		if (c == 'I') {
			scanf("%d", &e);
			p = enqueue(e);
			if (p == -1)
				return;
		}
		else if (c == 'D') {
			p = dequeue();
			if (p == -1)
				return;
		}
		else
			PRINTq();
	}
	free(q);
	return 0;
}