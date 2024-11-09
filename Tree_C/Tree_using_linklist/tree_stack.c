
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"tree.h"

#include"tree_queue.h"
#include"tree_stack.h"

void traverse_stack(stack l) {
    int t = l.top;
    while(t >= 0) {
        printf("\t|%d|\n", l.a[t].key);
        t--;
    }
}


//Defination of all function
void init_stack(stack *s, int len){
    s->a = (node*)malloc(sizeof(node)*len);
    s->size = len;
    s->top = -1;
}


int isFull_stack(stack s) {
    if(s.top == s.size-1)
        return 1;
    else
        return 0;
}


int isEmpty_stack(stack s) {
    if(s.top == -1)
        return 1;
    else
        return 0;
}


void push_stack(stack *s, node d){
    if(isFull_stack(*s))
        return ;
    else {
        s->top++;
        s->a[s->top] = d;
        return;
    }
}

node pop_stack(stack *s) {
   node t = {INT_MIN, NULL, NULL};
    if(isEmpty_stack(*s))
        return t;
    else{
        t = s->a[s->top];
        s->top--;
    }
    return t;
}



node peek_Stack(stack s) {
   node t = {INT_MIN, NULL, NULL};
    if(isEmpty_stack(s))
        return t;
    else{
        t = s.a[s.top];
    }
    return t;
}


