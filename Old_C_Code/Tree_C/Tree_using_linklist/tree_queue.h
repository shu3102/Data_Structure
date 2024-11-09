



typedef struct queue{
    node *Q;
    int front;
    int rear;
    int size;
    int present;
}queue;


void init_queue(queue *q,int len);
int isFull(queue q);
int isEmpty(queue q);
void enqueue(queue *q, node x);
node dequeue(queue *q);

