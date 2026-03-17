#include <stdlib.h>

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    // Initialize return size
    *returnSize = 0;
    
    // Edge case: empty tree
    if (root == NULL) {
        return NULL;
    }
    
    // LeetCode constraints guarantee at most 100 nodes.
    int* result = (int*)malloc(100 * sizeof(int));
    
    // Simulate a stack of TreeNode pointers
    struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    int top = -1; 
    
    // Start by pushing the root onto the stack
    stack[++top] = root;
    
    while (top >= 0) {
        // Pop the top node
        struct TreeNode* current = stack[top--];
        
        // 1. Process the Root
        result[(*returnSize)++] = current->val;
        
        // 2. Push the Right child FIRST (so it is processed last)
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        
        // 3. Push the Left child SECOND (so it is processed next)
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
    
    // Free the stack memory 
    free(stack);
    
    return result;
}
