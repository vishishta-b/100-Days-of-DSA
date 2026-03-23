#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue structure for Level Order Traversal
struct Queue {
    int front, rear, size;
    struct Node** array;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue functions
struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = 0;
    queue->size = size;
    queue->array = (struct Node**)malloc(queue->size * sizeof(struct Node*));
    return queue;
}

void enqueue(struct Queue* queue, struct Node* node) {
    queue->array[queue->rear++] = node;
}

struct Node* dequeue(struct Queue* queue) {
    return queue->array[queue->front++];
}

int isQueueEmpty(struct Queue* queue) {
    return queue->front == queue->rear;
}

// Level Order Traversal Function
void printLevelOrder(struct Node* root) {
    if (root == NULL) return;

    // Create a queue (size 100 for simplicity; in production use dynamic resizing)
    struct Queue* queue = createQueue(100);

    enqueue(queue, root);

    while (!isQueueEmpty(queue)) {
        struct Node* tempNode = dequeue(queue);

        printf("%d ", tempNode->data);

        // Enqueue left child
        if (tempNode->left != NULL)
            enqueue(queue, tempNode->left);

        // Enqueue right child
        if (tempNode->right != NULL)
            enqueue(queue, tempNode->right);
    }
    
    free(queue->array);
    free(queue);
}

int main() {
    // Constructing a sample tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order Traversal: ");
    printLevelOrder(root);
    printf("\n");

    return 0;
}
