#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* node, int data) {
    // 1. If the tree is empty, return a new node
    if (node == NULL) {
        return newNode(data);
    }

    // 2. Otherwise, recur down the tree
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Helper function to print the tree (Inorder) to verify insertion
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Inserting values
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Inorder traversal of BST always produces sorted output
    printf("Inorder Traversal (Sorted): ");
    inorder(root);
    printf("\n");

    return 0;
}
