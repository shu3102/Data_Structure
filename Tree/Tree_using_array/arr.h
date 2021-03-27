#include <stdio.h>
#include <stdlib.h>

typedef struct ARR {
    int *A;
    int size;
}ARR;

void init(ARR *t, int size);
void insert(ARR *t, int k);
void traverse(ARR t);
void display(ARR t);







typedef struct stack{
    int *a;
    int size;
    int top;
}stack;

int pop_stack(stack *s);
void push_stack(stack *s, int d);
int isEmpty_stack(stack s);
int isFull_stack(stack s);
void init_stack(stack *s, int len);
