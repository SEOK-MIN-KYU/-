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
int PreOrder(N* tree) {
	if (tree == NULL)
		return 0;
	return tree->data + PreOrder(tree->left) + PreOrder(tree->right);
}
void Order(N* tree, int n) {
	if (tree == NULL)
		return;
	if (tree->id == n)
		printf("%d", PreOrder(tree));
	else {
		Order(tree->left, n);
		Order(tree->right, n);
	}
}
int main() {
	N tree[8];
	N* root = tree;
	int n, i = 0;
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
	scanf("%d", &n);
	if (n >= 1 && n <= 8)
		Order(root, n);
	else
		printf("-1");
	return 0;
	free(root);
}