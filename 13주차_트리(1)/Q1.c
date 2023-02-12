#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}N;
void leftchild(N* tree, N* p) {
	tree->left = p;
}
void rightchild(N* tree, N* p) {
	tree->right = p;
}
void child(N* tree, N* p, N* q) {
	tree->left = p;
	tree->right = q;
}
int main() {
	N tree[8];
	int n, m, i = 0;
	int ary[8] = { 20, 30, 50, 70, 90, 120, 130, 80 };
	for (i = 0; i < 8; i++) {
		(tree + i)->data = *(ary + i);
		(tree + i)->left = NULL;
		(tree + i)->right = NULL;
	}
	child(tree, (tree + 1), (tree + 2));
	child((tree + 1), (tree + 3), (tree + 4));
	rightchild((tree + 2), (tree + 5));
	child((tree + 5), (tree + 6), (tree + 7));
	scanf("%d", &n);
	m = n - 1;
	if (n >= 1 && n <= 8) {
		if ((tree + m)->left == NULL && (tree + m)->right == NULL)
			printf("%d", (tree + m)->data);
		else if ((tree + m)->left == NULL)
			printf("%d %d", (tree + m)->data, (tree + m)->right->data);
		else if ((tree + m)->right == NULL)
			printf("%d %d", (tree + m)->data, (tree + m)->left->data);
		else
			printf("%d %d %d", (tree + m)->data, (tree + m)->left->data, (tree + m)->right->data);
	}
	else
		printf("-1");
	return 0;
}