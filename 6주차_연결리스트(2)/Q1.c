#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
    int coef, exp;
    struct node* next;
}N;

typedef struct list {
    N* head;
}L;

void initialize(L* list) {
    list->head = (N*)malloc(sizeof(N));
    list->head->next = NULL;
}
N* appendTerm(N* k, int c, int e) {
    N* t = (N*)malloc(sizeof(N));
    t->coef = c;
    t->exp = e;
    t->next = NULL;
    k->next = t;
    k = t;
    return k;

}
L* addPoly(N* x, N* y) {
    int sum = 0;
    L* result = (L*)malloc(sizeof(L));
    initialize(result);
    N* i = x->next;
    N* j = y->next;
    N* k = result->head;
    while (i != NULL && j != NULL) {
        if (i->exp > j->exp) {
            k = appendTerm(k, i->coef, i->exp);
            i = i->next;
        }
        else if (i->exp < j->exp) {
            k = appendTerm(k, j->coef, j->exp);
            j = j->next;
        }
        else {
            sum = i->coef + j->coef;
            if (sum != 0)
                k = appendTerm(k, sum, i->exp);
            i = i->next;
            j = j->next;
        }
    }
    while (i != NULL) {
        k = appendTerm(k, i->coef, i->exp);
        i = i->next;
    }
    while (j != NULL) {
        k = appendTerm(k, j->coef, j->exp);
        j = j->next;
    }
    return result;
}
void print(L* list) {
    N* p;
    p = list->head;
    while (p->next != NULL) {
        p = p->next;
        printf("%d %d ", p->coef, p->exp);

    }
}
int main() {
    int n, m, c, e, i;
    L* p = (L*)malloc(sizeof(L));
    L* q = (L*)malloc(sizeof(L));
    L* r;

    N* pp;

    initialize(p);
    initialize(q);

    N* cur1 = p->head;
    N* cur2 = q->head;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        cur1 = appendTerm(cur1, c, e);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &c, &e);
        cur2 = appendTerm(cur2, c, e);
    }
    r = addPoly(p->head, q->head);
    print(r);
    pp = p->head;
    while (pp != NULL) {
        pp = pp->next;
        free(pp);
    }
    pp = q->head;
    while (pp != NULL) {
        pp = pp->next;
        free(pp);
    }
    free(p);
    free(q);
    free(r);
    return 0;
}