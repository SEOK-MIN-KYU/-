#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int t, n;
void push(char* st, char c) {
	if (t == n - 1) {
		printf("Stack FULL\n");
		return;
	}
	t += 1;
	st[t] = c;
}
char pop(char* st) {
	if (t == -1) {
		printf("Stack Empty\n");
		return;
	}
	t -= 1;
	return st[t + 1];
}
void peek(char* st) {
	if (t == -1) {
		printf("Stack Empty\n");
		return;
	}
	printf("%c\n", st[t]);
}
void duplicate(char* st) {
	if (t == n) {
		printf("Stack FULL\n");
		return;
	}
	push(st, pop(st));
	push(st, st[t]);
}
void upRotate(char* st, int n) {
	int i;
	char* tmp = (char*)malloc(sizeof(char) * n);
	if (n > t + 1) {
		free(tmp);
		return;
	}
	for (i = 0; i < n; i++)
		tmp[i] = pop(st);
	push(st, tmp[0]);
	for (i = n - 1; i > 0; i--)
		push(st, tmp[i]);
	free(tmp);
}
void downRotate(char* st, int n) {
	int i;
	char* tmp = (char*)malloc(sizeof(char) * n);
	if (n > t + 1) {
		free(tmp);
		return;
	}
	for (i = 0; i < n; i++)
		tmp[i] = pop(st);
	for (i = n - 2; i > -1; i--)
		push(st, tmp[i]);
	push(st, tmp[n - 1]);
	free(tmp);
}
void print(char* st) {
	int i;
	for (i = t; i > -1; i--)
		printf("%c", st[i]);
	printf("\n");
}
int main() {
	int m, k, i;
	char* st, str[6], c;
	scanf("%d", &n);
	st = (char*)malloc(sizeof(char) * n);
	t = -1;
	scanf("%d", &m);
	getchar();
	for (i = 0; i < m; i++) {
		scanf("%s", str);
		getchar();
		if (strcmp(str, "PUSH") == 0) {
			scanf("%c", &c);
			push(st, c);
			getchar();
		}
		else if (strcmp(str, "POP") == 0)
			pop(st);
		else if (strcmp(str, "PEEK") == 0)
			peek(st);
		else if (strcmp(str, "DUP") == 0)
			duplicate(st);
		else if (strcmp(str, "UpR") == 0) {
			scanf("%d", &k);
			upRotate(st, k);
			getchar();
		}
		else if (strcmp(str, "DownR") == 0) {
			scanf("%d", &k);
			downRotate(st, k);
			getchar();
		}
		else if (strcmp(str, "PRINT") == 0)
			print(st);
	}
	free(st);
	return 0;
}