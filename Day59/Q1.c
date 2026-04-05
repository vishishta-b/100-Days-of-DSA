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

// Function to find the index of a value in the inorder array
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Recursive function to construct the binary tree
Node* buildTree(int in[], int post[], int inStrt, int inEnd, int* postIndex) {
    // Base case: if start index is greater than end index, there is no subtree
    if (inStrt > inEnd) {
        return NULL;
    }

    // The current root is the element at postIndex in the postorder array
    Node* tNode = createTreeNode(post[*postIndex]);
    (*postIndex)--; // Decrement postIndex for the next recursive call

    // If this node has no children, we can return it immediately
    if (inStrt == inEnd) {
        return tNode;
    }

    // Find the index of this node in the inorder array
    int inIndex = search(in, inStrt, inEnd, tNode->data);

    // CRITICAL: Using the index, construct the RIGHT subtree first, then the LEFT subtree
    // This is because we are traversing the postorder array from right to left
    tNode->right = buildTree(in, post, inIndex + 1, inEnd, postIndex);
    tNode->left = buildTree(in, post, inStrt, inIndex - 1, postIndex);

    return tNode;
}

// Function to print the preorder traversal (Root, Left, Right)
void printPreorder(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int* in = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }

    int* post = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }

    // postIndex starts at the last element of the postorder array
    int postIndex = n - 1;
    Node* root = buildTree(in, post, 0, n - 1, &postIndex);

    printPreorder(root);
    printf("\n");

    // Cleanup
    free(in);
    free(post);

    return 0;
}
