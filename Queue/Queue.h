
typedef struct queue{
    int *Q;
    int front;
    int rear;
    int size;
    int present;
}queue;


void init_queue(queue *q,int len);
int isFull(queue q);
int isEmpty(queue q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
void traverse(queue q);
