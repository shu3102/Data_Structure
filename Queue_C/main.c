
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"Queue.h"


int main() {
    queue Q;        // declering the queue
    init_queue(&Q, 5);         // initializing the queue

    enqueue(&Q, 10);
    enqueue(&Q, 20);
    enqueue(&Q, 30);
    enqueue(&Q, 40);
    traverse(Q);
    dequeue(&Q);
    traverse(Q);
    dequeue(&Q);
    traverse(Q);
    enqueue(&Q, 10);
    traverse(Q);
    enqueue(&Q, 20);
    traverse(Q);
    enqueue(&Q, 30);
    traverse(Q);
    enqueue(&Q, 40);
    traverse(Q);
    
}