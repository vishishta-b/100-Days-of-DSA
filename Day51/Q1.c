#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Find LCA in BST
struct Node* findLCA(struct Node* root, int p, int q) {
    while (root != NULL) {
        // If both nodes are smaller, LCA is in the left
        if (p < root->data && q < root->data) {
            root = root->left;
        }
        // If both nodes are larger, LCA is in the right
        else if (p > root->data && q > root->data) {
            root = root->right;
        }
        // We found the split point
        else {
            return root;
        }
    }
    return NULL;
}

int main() {
    int n, val, p, q;
    struct Node* root = NULL;

    // Input: Number of nodes
    if (scanf("%d", &n) != 1) return 0;

    // Input: Node values to build BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input: The two nodes to find LCA for
    scanf("%d %d", &p, &q);

    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL) {
        printf("%d\n", lca->data);
    }

    return 0;
}
