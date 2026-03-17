#include <stdio.h>
#include <stdlib.h>

// Macro to find the maximum of two numbers
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Define the Binary Tree Node
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

// Function to calculate the height (maximum depth) of the binary tree
int findHeight(TreeNode* root) {
    // Base case: an empty tree has a height of 0
    if (root == NULL) {
        return 0;
    }
    
    // Recursively find the height of the left and right subtrees
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    
    // The height of the current node is 1 + the maximum of the subtree heights
    return 1 + MAX(leftHeight, rightHeight);
}

int main() {
    int n;
    // Read the number of elements
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("0\n");
        return 0;
    }

    // Allocate memory and read the level-order array
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Edge case: if the root is -1, the tree is empty
    if (arr[0] == -1) {
        printf("0\n");
        free(arr);
        return 0;
    }

    // --- Build the Tree using a Queue ---
    TreeNode** queue = (TreeNode**)malloc(n * sizeof(TreeNode*));
    int front = 0, rear = 0;

    TreeNode* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1; 
    while (front < rear && i < n) {
        TreeNode* current = queue[front++];

        // Process Left Child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++; // Move to the next array element

        // Process Right Child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++; // Move to the next array element
    }

    // Calculate and print the height of the tree
    printf("%d\n", findHeight(root));

    // Clean up allocated arrays
    free(arr);
    free(queue);

    return 0;
}
