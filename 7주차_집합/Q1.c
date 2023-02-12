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
int subset(N* A, N* B) {
	if (A == NULL)
		return 0;
	else {
		while (A != NULL) {
			if (B == NULL)
				return A->elem;
			else if (A->elem < B->elem)
				return A->elem;
			else if (A->elem > B->elem)
				B = B->next;
			else {
				A = A->next;
				B = B->next;
			}
		}
		return 0;
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
	int n, m, e, i;
	N* A = (N*)malloc(sizeof(N));
	N* B = (N*)malloc(sizeof(N));
	A->elem = NULL;
	B->elem = NULL;
	A->next = NULL;
	B->next = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &e);
		add(A, e);
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &e);
		add(B, e);
	}
	printf("%d", subset(A, B));
	FREE(A);
	FREE(B);
	return 0;
}