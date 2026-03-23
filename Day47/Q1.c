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

// Function to calculate the height of the tree
int getHeight(struct Node* node) {
    if (node == NULL) {
        return 0; // Base case: empty tree has height 0
    } else {
        // Compute the height of each subtree
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        // Use the larger one and add 1 for the current node
        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        } else {
            return (rightHeight + 1);
        }
    }
}

int main() {
    // Constructing a sample tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    //    /
    //   6
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(6);

    printf("Height of the tree: %d\n", getHeight(root));

    return 0;
}
