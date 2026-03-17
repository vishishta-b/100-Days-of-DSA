#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the Node structure for the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Define the Deque structure
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Deque;

// Initialize a new Deque
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    if (!dq) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    dq->front = NULL;
    dq->rear = NULL;
    dq->size = 0;
    return dq;
}

// 7. empty(): Check whether the deque is empty
bool empty(Deque* dq) {
    return dq->size == 0;
}

// 8. size(): Return the number of elements
int size(Deque* dq) {
    return dq->size;
}

// 1. push_front(value): Insert at the front
void push_front(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (empty(dq)) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
    dq->size++;
}

// 2. push_back(value): Insert at the rear
void push_back(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (empty(dq)) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }
    dq->rear = newNode;
    dq->size++;
}

// 3. pop_front(): Remove from the front
void pop_front(Deque* dq) {
    if (empty(dq)) {
        printf("Deque Underflow: Cannot pop from an empty deque.\n");
        return;
    }
    Node* temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front == NULL) {
        dq->rear = NULL; // Deque becomes empty
    } else {
        dq->front->prev = NULL;
    }
    free(temp);
    dq->size--;
}

// 4. pop_back(): Remove from the rear
void pop_back(Deque* dq) {
    if (empty(dq)) {
        printf("Deque Underflow: Cannot pop from an empty deque.\n");
        return;
    }
    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear == NULL) {
        dq->front = NULL; // Deque becomes empty
    } else {
        dq->rear->next = NULL;
    }
    free(temp);
    dq->size--;
}

// 5. front(): Return the front element
int front(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return -1; // Return a sentinel value
    }
    return dq->front->data;
}

// 6. back(): Return the rear element
int back(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return -1; // Return a sentinel value
    }
    return dq->rear->data;
}

// Additional: clear()
void clear(Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

// Helper function to print the deque state
void printDeque(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    Node* current = dq->front;
    printf("Deque: [ ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("]\n");
}

int main() {
    Deque* dq = createDeque();

    printf("Pushing back 10 and 20...\n");
    push_back(dq, 10);
    push_back(dq, 20);
    printDeque(dq);

    printf("Pushing front 5...\n");
    push_front(dq, 5);
    printDeque(dq);

    printf("Front element: %d\n", front(dq));
    printf("Rear element: %d\n", back(dq));
    printf("Current size: %d\n", size(dq));

    printf("\nPopping front...\n");
    pop_front(dq);
    printDeque(dq);

    printf("Popping back...\n");
    pop_back(dq);
    printDeque(dq);

    printf("\nClearing the deque...\n");
    clear(dq);
    printf("Is deque empty? %s\n", empty(dq) ? "Yes" : "No");

    free(dq);
    return 0;
}
