#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int* inStack;
    int* outStack;
    int inTop;
    int outTop;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->inStack = (int*)malloc(sizeof(int) * MAX_SIZE);
    obj->outStack = (int*)malloc(sizeof(int) * MAX_SIZE);
    obj->inTop = -1;
    obj->outTop = -1;
    return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    obj->inStack[++(obj->inTop)] = x;
}

/** Helper function to move elements from inStack to outStack */
void transfer(MyQueue* obj) {
    if (obj->outTop == -1) {
        while (obj->inTop != -1) {
            obj->outStack[++(obj->outTop)] = obj->inStack[(obj->inTop)--];
        }
    }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    transfer(obj);
    return obj->outStack[(obj->outTop)--];
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    transfer(obj);
    return obj->outStack[obj->outTop];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return (obj->inTop == -1 && obj->outTop == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj->inStack);
    free(obj->outStack);
    free(obj);
}
