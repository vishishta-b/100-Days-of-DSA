#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // Initialize the return size to 0
    *returnSize = 0;
    
    // LeetCode constraints guarantee at most 100 nodes.
    int* result = (int*)malloc(100 * sizeof(int));
    
    // Simulate a stack of TreeNode pointers
    struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    int top = -1; // -1 indicates an empty stack
    
    struct TreeNode* current = root;
    
    // Loop until we've traversed all nodes (current is NULL) AND the stack is empty
    while (current != NULL || top != -1) {
        
        // Step 1: Reach the leftmost node of the current node
        while (current != NULL) {
            stack[++top] = current; // Push current node
            current = current->left;
        }
        
        // Step 2: Current must be NULL at this point. Pop the top item from stack.
        current = stack[top--];
        
        // Step 3: Record the node's value (Root)
        result[(*returnSize)++] = current->val;
        
        // Step 4: Visit the right subtree
        current = current->right;
    }
    
    // Free the stack memory since we only need to return the result array
    free(stack);
    
    return result;
}
