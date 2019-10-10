struct stack {
    int *ints;
    int nr_ints;
    int cap;
};

struct stack *stack_new(int cap) {
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->cap = cap;
    s->ints = (int *)malloc(sizeof(int) * s->cap);
    s->nr_ints = 0;
    return s;
}

/** Push element x to the back of queue. */
void stack_push(struct stack *s, int x) {
    if (s->nr_ints == s->cap) {
        s->cap *= 2;
        s->ints = (int *)realloc(s->ints, sizeof(int) * s->cap);
    }
    s->ints[s->nr_ints++] = x;
}

/** Removes the element from in front of queue and returns that element. */
int stack_pop(struct stack *s) {
    return s->ints[--s->nr_ints];
}

/** Get the front element. */
int stack_peek(struct stack *s) {
    return s->ints[s->nr_ints - 1];
}

/** Returns whether the queue is empty. */
bool stack_empty(struct stack *s) {
    return s->nr_ints == 0;
}

void stack_free(struct stack *s) {
    free(s->ints);
    free(s);
}


typedef struct {
    struct stack *s;
    struct stack *s2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *queue;
    queue = (MyQueue *)malloc(sizeof(MyQueue));
    queue->s = stack_new(100);
    queue->s2 = stack_new(100);
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    stack_push(obj->s, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int val;
    while (!stack_empty(obj->s))
        stack_push(obj->s2, stack_pop(obj->s));
    val = stack_pop(obj->s2);
    while (!stack_empty(obj->s2))
        stack_push(obj->s, stack_pop(obj->s2));
    return val;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    int val;
    while (!stack_empty(obj->s))
        stack_push(obj->s2, stack_pop(obj->s));
    val = stack_peek(obj->s2);
    while (!stack_empty(obj->s2))
        stack_push(obj->s, stack_pop(obj->s2));
    return val;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return stack_empty(obj->s);
}

void myQueueFree(MyQueue* obj) {
    stack_free(obj->s);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
