#include <stdio.h>
#include <stdlib.h>
#include "arr.h"
#include<limits.h>


void init(ARR *t, int size) {
    t->A = (int *)malloc(sizeof(int)*size);
    t->size = size;

    for(int i = 0; i < size; i++) {
        t->A[i] = INT_MIN;
    }
    return;
}


void insert(ARR *t, int k) {

    if(t->A[0] == INT_MIN) {
        t->A[0] = k;
        return;
    }
    int i = 0;
    while(t->A[i] != INT_MIN && i<t->size) {
        if(k == t->A[i])
            return;
        else if(k < t->A[i]) {
            i = 2*i + 1;
        }
        else if (k > t->A[i]) {
            i = 2*i + 2;
        }
    }

    if(t->A[i] == INT_MIN) {
        t->A[i] = k;
        return;
    }
}


void traverse(ARR t) {

    if(t.A[0] == INT_MIN) {
        return;
    }
    printf("[");
    stack S;
    init_stack(&S, 15);

    int i = 0, j;
    push_stack(&S, i);
    i = i*2 + 1;
    while(!isEmpty_stack(S) || i<t.size) {

        if((t.A[i] != INT_MIN) && i<t.size) {
            push_stack(&S, i);
            i = i*2 + 1;
        }
        else if(!isEmpty_stack(S)){
            j = pop_stack(&S);
            printf("%d ", t.A[j]);
            i = 2*j + 2;
        }
        else {
            printf("]\n");
            return;
        }
    }
    printf("]\n");
    return;
}



void display(ARR t) {
    printf(" binary tree : ");
    int i=0;
    while(i<t.size) {
        if(t.A[i]=='\0') {
            printf("-  ");
        }
        printf("%d  ",t.A[i]);
        i++;
    }
}


int count_node(ARR t) {
    int temp = 0;

    for(int i = 0; i < t.size; i++) {
        if(t.A[i] != INT_MIN) {
            temp++;
        }
    }
    return temp;
}



// funtion to count the total number of
// leaf nodes in bst
int count_leaf(ARR t, int i) {

    if(t.A[i] == INT_MIN)
        return 0;
    if(t.A[2*i + 1] == INT_MIN && t.A[2*i + 2] == INT_MIN)
        return 1;
    else
        return count_leaf(t, i+1) + count_leaf(t, i+1);

}

