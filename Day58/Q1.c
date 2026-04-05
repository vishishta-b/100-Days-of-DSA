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
Node* buildTree(int in[], int pre[], int inStrt, int inEnd, int* preIndex) {
    // Base case: if start index is greater than end index, there is no subtree
    if (inStrt > inEnd) {
        return NULL;
    }

    // The current root is the element at preIndex in the preorder array
    Node* tNode = createTreeNode(pre[*preIndex]);
    (*preIndex)++; // Increment preIndex for the next recursive call

    // If this node has no children, we can return it immediately
    if (inStrt == inEnd) {
        return tNode;
    }

    // Find the index of this node in the inorder array
    int inIndex = search(in, inStrt, inEnd, tNode->data);

    // Using the index, construct the left and right subtrees
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, preIndex);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return tNode;
}

// Function to print the postorder traversal (Left, Right, Root)
void printPostorder(Node* node) {
    if (node == NULL) {
        return;
    }
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int* pre = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }

    int* in = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }

    // preIndex must be passed by reference so it increments globally across all recursive calls
    int preIndex = 0;
    Node* root = buildTree(in, pre, 0, n - 1, &preIndex);

    printPostorder(root);
    printf("\n");

    // Cleanup
    free(pre);
    free(in);

    return 0;
}
