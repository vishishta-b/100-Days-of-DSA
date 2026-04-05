#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    // 2. Zigzag Level Order Traversal using Two Stacks
    Node** currentLevel = (Node**)malloc(n * sizeof(Node*));
    Node** nextLevel = (Node**)malloc(n * sizeof(Node*));
    int topCurrent = -1, topNext = -1;

    // Push root to current level
    currentLevel[++topCurrent] = root;
    bool leftToRight = true;

    while (topCurrent >= 0) {
        // Pop from current level
        Node* temp = currentLevel[topCurrent--];
        printf("%d ", temp->data);

        // Push children to next level based on the current direction
        if (leftToRight) {
            if (temp->left)  nextLevel[++topNext] = temp->left;
            if (temp->right) nextLevel[++topNext] = temp->right;
        } else {
            if (temp->right) nextLevel[++topNext] = temp->right;
            if (temp->left)  nextLevel[++topNext] = temp->left;
        }

        // If current level is empty, swap stacks and toggle direction
        if (topCurrent == -1) {
            leftToRight = !leftToRight;
            
            // Swap stack pointers
            Node** tempStack = currentLevel;
            currentLevel = nextLevel;
            nextLevel = tempStack;
            
            // Transfer the top index
            topCurrent = topNext;
            topNext = -1;
        }
    }
    printf("\n");

    // Cleanup
    free(arr);
    free(currentLevel);
    free(nextLevel);

    return 0;
}
