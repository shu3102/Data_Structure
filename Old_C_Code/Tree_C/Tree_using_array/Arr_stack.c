#include <stdio.h>
#include <stdlib.h>
#include "arr.h"
#include<limits.h>



//Defination of all function
void init_stack(stack *s, int len){
    s->a = (int*)malloc(sizeof(int)*len);
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


void push_stack(stack *s, int d){
    if(isFull_stack(*s))
        return ;
    else {
        s->top++;
        s->a[s->top] = d;
        return;
    }
}

int pop_stack(stack *s) {
   int t = INT_MIN;
    if(isEmpty_stack(*s))
        return t;
    else{
        t = s->a[s->top];
        s->top--;
    }
    return t;
}

