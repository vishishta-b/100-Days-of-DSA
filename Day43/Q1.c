#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Binary Tree Node
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Helper function to create a new tree node
TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function for Inorder Traversal (Left -> Root -> Right)
void printInorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

int main() {
    int n;
    // Read the number of elements
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    // Allocate memory for the level-order array
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Edge case: Empty tree
    if (arr[0] == -1) {
        free(arr);
        return 0;
    }

    // Create a Queue to store tree node pointers. 
    // The max size of the queue will not exceed 'n'.
    TreeNode** queue = (TreeNode**)malloc(n * sizeof(TreeNode*));
    int front = 0, rear = 0;

    // Create the root node and enqueue it
    TreeNode* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1; // Start reading from the second element in the array
    while (front < rear && i < n) {
        // Dequeue the front node
        TreeNode* current = queue[front++];

        // 1. Process the Left Child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left; // Enqueue the left child
        }
        i++; // Move to the next element in the array

        // 2. Process the Right Child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right; // Enqueue the right child
        }
        i++; // Move to the next element in the array
    }

    // Print the inorder traversal of the constructed tree
    printInorder(root);
    printf("\n");

    // Clean up memory (Note: A full implementation would also recursively free the tree nodes)
    free(arr);
    free(queue);

    return 0;
}
