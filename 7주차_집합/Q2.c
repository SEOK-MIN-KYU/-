#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
	int elem;
	struct node* next;
}N;
void add(N* node, int e) {
	N* p = (N*)malloc(sizeof(N));
	p->elem = e;
	p->next = NULL;
	while (node->next != NULL)
		node = node->next;
	node->next = p;
}
N* UNION(N* A, N* B) {
	N* h1 = A;
	N* h2 = B;
	N* u = (N*)malloc(sizeof(N));
	u->elem = NULL;
	u->next = NULL;
	if (h1->next == NULL && h2->next == NULL)
		return u;
	else if (h1->next == NULL) {
		free(u);
		return h2;
	}
	else if (h2->next == NULL) {
		free(u);
		return h1;
	}
	else {
		h1 = h1->next;
		h2 = h2->next;
		while (h1 != NULL && h2 != NULL) {
			if (h1->elem < h2->elem) {
				add(u, h1->elem);
				h1 = h1->next;
			}
			else if (h1->elem > h2->elem) {
				add(u, h2->elem);
				h2 = h2->next;
			}
			else {
				add(u, h1->elem);
				h1 = h1->next;
				h2 = h2->next;
			}
		}
		while (h1 != NULL) {
			add(u, h1->elem);
			h1 = h1->next;
		}
		while (h2 != NULL) {
			add(u, h2->elem);
			h2 = h2->next;
		}
	}
	return u;
}
N* intersect(N* A, N* B) {
	N* h1 = A;
	N* h2 = B;
	N* i = (N*)malloc(sizeof(N));
	i->elem = NULL;
	i->next = NULL;
	if (h1->next == NULL || h2->next == NULL)
		return i;
	else {
		h1 = h1->next;
		h2 = h2->next;
		while (h1 != NULL && h2 != NULL) {
			if (h1->elem < h2->elem)
				h1 = h1->next;
			else if (h1->elem > h2->elem)
				h2 = h2->next;
			else {
				add(i, h1->elem);
				h1 = h1->next;
				h2 = h2->next;
			}
		}
		while (h1 != NULL)
			h1 = h1->next;

		while (h2 != NULL)
			h2 = h2->next;
	}
	return i;
}
void PRINT(N* node) {
	N* p = node->next;
	if (p == NULL)
		printf(" 0\n");
	else {
		while (p != NULL) {
			printf(" %d", p->elem);
			p = p->next;
		}
		printf("\n");
	}
}
void FREE(N* node) {
	N* p = node;
	while (p != NULL) {
		node = node->next;
		free(p);
		p = node;
	}
}
int main() {
	int n, m, e, j;
	N* A = (N*)malloc(sizeof(N));
	N* B = (N*)malloc(sizeof(N));
	N* u;
	N* i;
	A->elem = NULL;
	B->elem = NULL;
	A->next = NULL;
	B->next = NULL;
	scanf("%d", &n);
	for (j = 0; j < n; j++) {
		scanf("%d", &e);
		add(A, e);
	}
	scanf("%d", &m);
	for (j = 0; j < m; j++) {
		scanf("%d", &e);
		add(B, e);
	}
	u = UNION(A, B);
	PRINT(u);
	i = intersect(A, B);
	PRINT(i);
	FREE(A);
	FREE(B);
	if (u != A && u != B)
		FREE(u);
	FREE(i);
	return 0;
}