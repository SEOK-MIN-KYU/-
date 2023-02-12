#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
	int data, id;
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
void PreOrder(N* tree) {
	if (tree == NULL)
		return;
	printf(" %d", tree->data);
	PreOrder(tree->left);
	PreOrder(tree->right);
}
void PostOrder(N* tree) {
	if (tree == NULL)
		return;
	PostOrder(tree->left);
	PostOrder(tree->right);
	printf(" %d", tree->data);
}
void inOrder(N* tree) {
	if (tree == NULL)
		return;
	inOrder(tree->left);
	printf(" %d", tree->data);
	inOrder(tree->right);
}
void Order(N* tree, int n, int m) {
	if (tree == NULL)
		return;
	if (tree->id == m) {
		if (n == 1)
			PreOrder(tree);
		else if (n == 2)
			inOrder(tree);
		else
			PostOrder(tree);
	}
	else {
		Order(tree->left, n, m);
		Order(tree->right, n, m);
	}
}
int main() {
	N* tree;
	tree = (N*)malloc(sizeof(N) * 8);
	int n, m, i = 0;
	int ary[8] = { 20, 30, 50, 70, 90, 120, 130, 80 };
	for (i = 0; i < 8; i++) {
		(tree + i)->data = *(ary + i);
		(tree + i)->id = i + 1;
		(tree + i)->left = NULL;
		(tree + i)->right = NULL;
	}
	child(tree, (tree + 1), (tree + 2));
	child((tree + 1), (tree + 3), (tree + 4));
	rightchild((tree + 2), (tree + 5));
	child((tree + 5), (tree + 6), (tree + 7));
	scanf("%d %d", &n, &m);
	if (m >= 1 && m <= 8)
		Order(tree, n, m);
	else
		printf("-1");
	free(tree);
	return 0;
}