#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// --- Queue Implementation ---
typedef struct {
    int* data;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->data = (int*)malloc(capacity * sizeof(int));
    return q;
}

bool isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int value) {
    q->data[q->rear++] = value;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

void freeQueue(Queue* q) {
    free(q->data);
    free(q);
}

// --- Stack Implementation ---
typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->top = -1;
    s->data = (int*)malloc(capacity * sizeof(int));
    return s;
}

bool isStackEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    s->data[++s->top] = value;
}

int pop(Stack* s) {
    return s->data[s->top--];
}

void freeStack(Stack* s) {
    free(s->data);
    free(s);
}

// --- Main Logic ---
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Handle edge case of 0 elements
    if (n <= 0) {
        return 0;
    }

    Queue* q = createQueue(n);
    Stack* s = createStack(n);

    // Read the input and populate the initial queue
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        enqueue(q, value);
    }

    // Step 1: Dequeue all elements and push them onto the stack
    while (!isQueueEmpty(q)) {
        push(s, dequeue(q));
    }

    // Step 2: Pop all elements from the stack and enqueue them back
    while (!isStackEmpty(s)) {
        enqueue(q, pop(s));
    }

    // Print the reversed queue
    while (!isQueueEmpty(q)) {
        printf("%d ", dequeue(q));
    }
    printf("\n");

    // Clean up memory
    freeQueue(q);
    freeStack(s);

    return 0;
}
