#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int t;
char* st;
void push(char c) {
	if (t == 999) {
		printf("Stack FULL\n");
		return;
	}
	t += 1;
	st[t] = c;
}
char pop(void) {
	if (t == -1) {
		printf("Stack Empty\n");
		return;
	}
	t -= 1;
	return st[t + 1];
}
int isEmpty(void) {
	if (t == -1)
		return 1;
	else
		return 0;
}
int isBalanced(char* exp) {
	int i;
	char s;
	for (i = 0; i < strlen(exp); i++) {
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
			if (isEmpty())
				return 0;
			s = pop();
			if (exp[i] == ')') {
				if (s != '(')
					return 0;
			}
			else if (exp[i] == '}') {
				if (s != '{')
					return 0;
			}
			else if (exp[i] == ']') {
				if (s != '[')
					return 0;
			}
		}
	}
	return isEmpty();
}
int main() {
	int i, cnt = 0;
	char* exp = (char*)malloc(sizeof(char) * 1000);
	st = (char*)malloc(sizeof(char) * 1000);
	t = -1;
	gets(exp);
	for (i = 0; i < strlen(exp); i++) {
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[' || exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
			cnt++;
	}
	if (isBalanced(exp) == 1)
		printf("OK_%d", cnt);
	else
		printf("Wrong_%d", cnt);
	free(exp);
	free(st);
	return 0;
}