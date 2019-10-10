typedef struct {
    int *ints;
    int back;
    int front;
    int cap;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *queue;
    queue = (MyQueue *)malloc(sizeof(MyQueue));
    queue->cap = 100;
    queue->ints = (int *)malloc(sizeof(int) * queue->cap);
    queue->back = 0;
    queue->front = 0;
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if (obj->back == obj->cap) {
        obj->cap *= 2;
        obj->ints = (int *)realloc(obj->ints, sizeof(int) * obj->cap);
    }
    obj->ints[obj->back++] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    return obj->ints[obj->front++];
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return obj->ints[obj->front];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj->front == obj->back;
}

void myQueueFree(MyQueue* obj) {
    free(obj->ints);
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
