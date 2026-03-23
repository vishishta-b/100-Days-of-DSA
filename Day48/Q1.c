#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* node) {
    // 1. If tree is empty, return 0
    if (node == NULL) {
        return 0;
    }
    
    // 2. If node has no children, it's a leaf node
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }
    
    // 3. Otherwise, sum the leaf nodes of left and right subtrees
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}

int main() {
    /* Constructing a sample tree:
              1
             / \
            2   3
           / \   \
          4   5   6
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    // In this tree, nodes 4, 5, and 6 are leaf nodes.
    printf("Total number of leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}
