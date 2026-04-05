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

// Helper function to check if two subtrees are mirrors of each other
bool isMirror(Node* leftSubtree, Node* rightSubtree) {
    // 1. Both empty -> they match
    if (leftSubtree == NULL && rightSubtree == NULL) {
        return true;
    }
    
    // 2. Only one is empty -> they don't match
    if (leftSubtree == NULL || rightSubtree == NULL) {
        return false;
    }
    
    // 3. Both have values -> check values AND check opposite children recursively
    return (leftSubtree->data == rightSubtree->data) &&
           isMirror(leftSubtree->left, rightSubtree->right) &&
           isMirror(leftSubtree->right, rightSubtree->left);
}

// Main function to initiate the symmetry check
bool isSymmetric(Node* root) {
    // An empty tree is symmetric
    if (root == NULL) {
        return true;
    }
    // Check if the left and right halves are mirrors
    return isMirror(root->left, root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (arr[0] == -1) {
        printf("YES\n"); // An empty tree is technically symmetric
        free(arr);
        return 0;
    }

    // Build the Binary Tree from level-order input
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
    free(arr);

    // Check symmetry and print result
    if (isSymmetric(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
