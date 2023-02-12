#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int t, f;
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
int convert(char* exp, int j) {
	if (j == 0 && t != j && (exp[j] == '+' || exp[j] == '-')) {
		f = 1;
		return 6;
	}
	else if (t != -1 && (exp[j] == '+' || exp[j] == '-') && (exp[j - 1] == '!' || exp[j - 1] == '*' || exp[j - 1] == '/' || exp[j - 1] == '+' || exp[j - 1] == '-' || exp[j - 1] == '>' || exp[j - 1] == '<' || exp[j - 1] == '&' || exp[j - 1] == '|'))
		return 6;
	else if (exp[j] == '!')
		return 6;
	else if (exp[j] == '*' || exp[j] == '/')
		return 5;
	else if (exp[j] == '+' || exp[j] == '-')
		return 4;
	else if (exp[j] == '>' || exp[j] == '<')
		return 3;
	else if (exp[j] == '&')
		return 2;
	else if (exp[j] == '|')
		return 1;
	else
		return 0;
}
int main() {
	int n, i, j, k;
	char st[100], exp[100], con[100];
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		t = -1, k = 0; f = 0;
		for (j = 0; j < 100; j++) {
			con[j] = '\0';
			st[j] = '\0';
		}
		scanf("%s", exp);
		getchar();
		for (j = 0; j < strlen(exp); j++) {
			if (exp[j] == '(')
				push(st, exp[j]);
			else if (exp[j] == ')') {
				while (st[t] != '(') {
					con[k++] = pop(st);
				}
				pop(st);
			}
			else if (convert(exp, j) == 6)
				push(st, exp[j]);
			else if (convert(exp, j) == 0)
				con[k++] = exp[j];
			else {
				if (f == 1)
					con[k++] = pop(st);
				else {
					while (t != -1 && convert(exp, j) <= convert(st, t)) {
						con[k++] = pop(st);
					}
				}
				if (convert(exp, j) == 1 || convert(exp, j) == 2) {
					push(st, exp[j++]);
				}
				push(st, exp[j]);
			}
		}
		while (t != -1) {
			con[k++] = pop(st);
		}
		printf("%s\n", con);
	}
	return 0;
}