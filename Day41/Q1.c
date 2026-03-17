#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the Queue structure holding front and rear pointers
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Initialize a new empty Queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Enqueue: Add an element to the rear of the queue
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // If the queue is empty, the new node is both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    // Otherwise, add the new node at the end and update the rear pointer
    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue: Remove and return the front element of the queue
int dequeue(Queue* q) {
    // If the queue is empty, return -1 as per the problem statement
    if (q->front == NULL) {
        return -1;
    }

    // Store the previous front and move the front pointer one step ahead
    Node* temp = q->front;
    int dequeuedValue = temp->data;
    q->front = q->front->next;

    // If front becomes NULL, then the queue is now empty, so rear must also be NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return dequeuedValue;
}

// Free the remaining nodes and the queue structure
void freeQueue(Queue* q) {
    Node* current = q->front;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(q);
}

int main() {
    int n;
    // Read the number of operations
    if (scanf("%d", &n) != 1) return 0;

    Queue* q = createQueue();
    char command[20];
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        
        if (strcmp(command, "enqueue") == 0) {
            scanf("%d", &value);
            enqueue(q, value);
        } 
        else if (strcmp(command, "dequeue") == 0) {
            printf("%d\n", dequeue(q));
        }
    }

    freeQueue(q);
    return 0;
}
