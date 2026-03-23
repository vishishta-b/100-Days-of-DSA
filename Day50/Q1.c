#include <stdio.h>
#include <stdlib.h>

// Standard definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * RECURSIVE SEARCH
 * Best for: Clean, readable code.
 * Space: O(H) due to recursion stack.
 */
struct TreeNode* searchBST_Recursive(struct TreeNode* root, int val) {
    // Base case: root is null (not found) or we found the value
    if (root == NULL || root->val == val) {
        return root;
    }

    // Value is smaller than current node, search the left subtree
    if (val < root->val) {
        return searchBST_Recursive(root->left, val);
    }

    // Value is larger than current node, search the right subtree
    return searchBST_Recursive(root->right, val);
}

/**
 * ITERATIVE SEARCH
 * Best for: Performance and memory efficiency.
 * Space: O(1) constant space.
 */
struct TreeNode* searchBST_Iterative(struct TreeNode* root, int val) {
    struct TreeNode* curr = root;

    while (curr != NULL && curr->val != val) {
        if (val < curr->val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return curr;
}

// Helper function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    /* Sample BST:
            4
           / \
          2   7
         / \
        1   3
    */
    struct TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    int target = 2;
    struct TreeNode* result = searchBST_Iterative(root, target);

    if (result) {
        printf("Found node with value: %d\n", result->val);
    } else {
        printf("Value %d not found in BST.\n", target);
    }

    return 0;
}
