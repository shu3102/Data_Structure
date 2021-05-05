
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"Queue.h"


void init_queue(queue *q,int len){
    q->size=len;
    q->front=q->rear=-1;
    q->present = 0;
    q->Q=(int *)malloc(sizeof(int)*len);
}

int isFull(queue q){
    if(q.present == q.size){
        printf("Queue is Full\n");
        return 1;
    }
    else
        return 0;
}

int isEmpty(queue q){
    if(q.present == 0){
        printf("Queue is Empty\n");
        return 1;
    }
    else
        return 0;

}


void enqueue(queue *q, int x) {
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

int dequeue(queue *q) {
    int x = INT_MAX;
    // {INT_MIN, NULL, NULL};
    if(!isEmpty(*q)){
        q->front = (q->front+1) % q->size;
        x=q->Q[q->front];
    }
    q->present--;
    return x;
}


void traverse(queue q) {
    int t = q.front;
    int p = q.present;
    printf("[ ");
    while(p) {
        printf("%d ", q.Q[t]);
        t = (t + 1)%q.size;
        p--;
    }
    printf("]\n");
    return;
}
