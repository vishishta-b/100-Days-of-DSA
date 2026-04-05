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

// Function to convert the tree into its mirror image
void mirrorTree(Node* root) {
    if (root == NULL) {
        return;
    }
    
    // 1. Recursively mirror the left and right subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
    
    // 2. Swap the left and right children of the current node
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// Function to print the inorder traversal of the tree
void printInorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
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

    // 1. Build the Binary Tree from level-order input
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

    // 2. Convert the tree to its mirror image
    mirrorTree(root);

    // 3. Print the inorder traversal
    printInorder(root);
    printf("\n");

    return 0;
}
