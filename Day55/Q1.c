#include <stdio.h>
#include <stdlib.h>

// Tree Node structure
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Utility function to create a new tree node
Node* createTreeNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (arr[0] == -1) {
        free(arr);
        return 0;
    }

    // 1. Build the Binary Tree using a Queue
    Node* root = createTreeNode(arr[0]);
    Node** buildQueue = (Node**)malloc(n * sizeof(Node*));
    int bFront = 0, bRear = 0;
    
    buildQueue[bRear++] = root;
    int i = 1;
    
    while (bFront < bRear && i < n) {
        Node* curr = buildQueue[bFront++];
        
        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = createTreeNode(arr[i]);
            buildQueue[bRear++] = curr->left;
        }
        i++;
        
        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createTreeNode(arr[i]);
            buildQueue[bRear++] = curr->right;
        }
        i++;
    }
    free(buildQueue);

    // 2. Right View using Level Order Traversal (BFS)
    // We can reuse a simple queue for this.
    Node** q = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;
    
    // Push the root node
    q[rear++] = root;
    
    while (front < rear) {
        // Determine how many nodes are at the current level
        int levelSize = rear - front;
        
        // Process all nodes on this level
        for (int j = 0; j < levelSize; j++) {
            Node* curr = q[front++];
            
            // If this is the last node in the current level, print it
            if (j == levelSize - 1) {
                printf("%d ", curr->data);
            }
            
            // Enqueue children for the next level's batch
            if (curr->left != NULL) {
                q[rear++] = curr->left;
            }
            if (curr->right != NULL) {
                q[rear++] = curr->right;
            }
        }
    }
    printf("\n");

    // Cleanup
    free(arr);
    free(q);

    return 0;
}
