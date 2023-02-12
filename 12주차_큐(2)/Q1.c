#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
	int e;
	struct node* prev;
	struct node* next;
};
int s;
struct node* deque, * r, * f;
void add_front(struct node* deque, int x) {
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->e = x;
	p->prev = NULL;
	p->next = f;
	p->next->prev = p;
	f = p;

}
void add_rear(struct node* deque, int x) {
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->e = x;
	p->prev = r;
	p->next = NULL;
	p->prev->next = p;
	r = p;

}
int delete_front(struct node* deque) {
	struct node* p;
	if (s == 0) {
		printf("underflow\n");
		return -1;
	}
	else {
		p = f;
		if (s == 1)
			free(p);
		else {
			f = f->next;
			f->prev = NULL;
			free(p);
		}
	}
}
int delete_rear(struct node* deque) {
	struct node* p;
	if (s == 0) {
		printf("underflow\n");
		return -1;
	}
	else {
		p = r;
		if (s == 1)
			free(p);
		else {
			r = r->prev;
			r->next = NULL;
			free(p);
		}
	}
}
void print(struct node* deque) {
	struct node* p = f;
	while (p != NULL) {
		printf(" %d", p->e);
		p = p->next;
	}
	printf("\n");
}
int main() {
	int n, x, i, q;
	char c[2];
	s = 0;
	deque = (struct node*)malloc(sizeof(struct node));
	deque->next = NULL;
	deque->prev = NULL;
	f = deque;
	r = deque;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%s", c);
		if (strcmp(c, "AF") == 0) {
			scanf("%d", &x);
			getchar();
			if (s == 0) {
				deque = (struct node*)malloc(sizeof(struct node));
				deque->e = x;
				deque->next = NULL;
				deque->prev = NULL;
				f = deque;
				r = deque;
				s++;
			}
			else {
				add_front(deque, x);
				s++;
			}
		}
		else if (strcmp(c, "AR") == 0) {
			scanf("%d", &x);
			getchar();
			if (s == 0) {
				deque = (struct node*)malloc(sizeof(struct node));
				deque->e = x;
				deque->next = NULL;
				deque->prev = NULL;
				f = deque;
				r = deque;
				s++;
			}
			else {
				add_rear(deque, x);
				s++;
			}
		}
		else if (strcmp(c, "DF") == 0) {
			q = delete_front(deque);
			if (q == -1)
				return;
			s--;
		}
		else if (strcmp(c, "DR") == 0) {
			q = delete_rear(deque);
			if (q == -1)
				return;
			s--;
		}
		else
			print(deque);
	}
	free(deque);
	return 0;
}