
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"tree.h"

#include"tree_queue.h"
#include"tree_stack.h"
//Problem :

void init_queue(queue *q,int len){
    q->size=len;
    q->front=q->rear=-1;
    q->present = 0;
    q->Q=(node *)malloc(sizeof(node)*len);
}

int isFull(queue q){
    if(q.present == q.size){
        printf("Queue is Full");
        return 1;
    }
    else
        return 0;
}

int isEmpty(queue q){
    if(q.present == 0){
        //printf("Queue is Empty\n");
        return 1;
    }
    else
        return 0;

}


void enqueue(queue *q, node x) {
    if(q->front == -1 || q->rear == -1) {
        q->rear = (q->rear+1) % q->size;
        q->front = (q->front+1) % q->size;
        q->Q[q->rear]=x;
        q->present++;
        return;
    }
    if(!isFull(*q)){
        q->rear = (q->rear+1) % q->size;
        q->Q[q->rear]=x;
        q->present++;
        return;
    }

    return;
}

node dequeue(queue *q) {
    node x = {INT_MIN, NULL, NULL};
    if(!isEmpty(*q)){
        q->front = (q->front+1) % q->size;
        x=q->Q[q->front];
    }
    q->present--;
    return x;
}



