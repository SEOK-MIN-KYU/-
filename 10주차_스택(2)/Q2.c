#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int t;
void push(char* st, char c) {
	if (t == 99) {
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
int evaluate(char* exp) {
	if (exp == '+')
		return 1;
	else if (exp == '-')
		return 2;
	else if (exp == '*')
		return 3;
	else if (exp == '/')
		return 4;
	else
		return 0;
}
int main() {
	int n, m, i, p1, p2;
	char st[100], exp[100];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		t = -1;
		m = 0;
		scanf("%s", exp);
		getchar();
		while (m != strlen(exp)) {
			if (evaluate(exp[m]) == 0) {
				push(st, exp[m] - '0');
			}
			else {
				if (evaluate(exp[m]) == 1) {
					p1 = pop(st);
					p2 = pop(st);
					push(st, p1 + p2);
				}
				else if (evaluate(exp[m]) == 2) {
					p1 = pop(st);
					p2 = pop(st);
					push(st, p2 - p1);
				}
				else if (evaluate(exp[m]) == 3) {
					p1 = pop(st);
					p2 = pop(st);
					push(st, p1 * p2);
				}
				else if (evaluate(exp[m]) == 4) {
					p1 = pop(st);
					p2 = pop(st);
					push(st, p2 / p1);
				}
			}
			m++;
		}
		printf("%d\n", pop(st));
	}
	return 0;
}