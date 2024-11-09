



typedef struct stack{
    node *a;
    int size;
    int top;
}stack;

node pop_stack(stack *s);
void push_stack(stack *s, node d);
int isEmpty_stack(stack s);
int isFull_stack(stack s);
void init_stack(stack *s, int len);
void remoov(bst *t, int d);
void traverse_stack(stack l);
node peek_stack(stack s);

