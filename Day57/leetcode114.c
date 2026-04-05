#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;

    while (curr != NULL) {
        // If there is a left child, we need to move it to the right
        if (curr->left != NULL) {
            
            // 1. Find the rightmost node in the left subtree
            // This node will eventually point to the current right subtree
            struct TreeNode* predecessor = curr->left;
            while (predecessor->right != NULL) {
                predecessor = predecessor->right;
            }

            // 2. Connect the rightmost node of left subtree to current right
            predecessor->right = curr->right;

            // 3. Move the entire left subtree to the right
            curr->right = curr->left;
            
            // 4. Set left child to NULL as required
            curr->left = NULL;
        }
        
        // Move to the next node in the flattened chain (always to the right)
        curr = curr->right;
    }
}
