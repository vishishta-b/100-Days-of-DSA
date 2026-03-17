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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    
    // LeetCode constraints guarantee at most 100 nodes.
    int* result = (int*)malloc(100 * sizeof(int));
    
    struct TreeNode* current = root;
    struct TreeNode* pre;
    
    while (current != NULL) {
        if (current->left == NULL) {
            // No left child: record the value and move right
            result[(*returnSize)++] = current->val;
            current = current->right;
        } else {
            // Find the inorder predecessor of current
            pre = current->left;
            while (pre->right != NULL && pre->right != current) {
                pre = pre->right;
            }
            
            if (pre->right == NULL) {
                // Make current the right child of its inorder predecessor (Create the thread)
                pre->right = current;
                current = current->left;
            } else {
                // Revert the changes made to restore the original tree (Destroy the thread)
                pre->right = NULL;
                result[(*returnSize)++] = current->val;
                current = current->right;
            }
        }
    }
    
    return result;
}
