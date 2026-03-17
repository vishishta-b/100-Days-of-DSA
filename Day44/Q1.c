#include <stdio.h>
#include <stdlib.h>

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

// 1. Inorder Traversal (Left -> Root -> Right)
void printInorder(TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

// 2. Preorder Traversal (Root -> Left -> Right)
void printPreorder(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

// 3. Postorder Traversal (Left -> Right -> Root)
void printPostorder(TreeNode* root) {
    if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    // Read the number of elements
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    // Read the level-order array
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Handle empty tree edge case
    if (arr[0] == -1) {
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

        // Left Child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right Child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    // --- Execute and Print Traversals ---
    printInorder(root);
    printf("\n");

    printPreorder(root);
    printf("\n");

    printPostorder(root);
    printf("\n");

    // Clean up allocated arrays
    free(arr);
    free(queue);

    return 0;
}
