#include <stdbool.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

// Helper function to check if two trees are mirrors of each other
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    // If both nodes are null, they are symmetric
    if (t1 == NULL && t2 == NULL) return true;
    
    // If only one is null, or values don't match, they aren't symmetric
    if (t1 == NULL || t2 == NULL) return false;
    if (t1->val != t2->val) return false;
    
    // Check internal mirrors: 
    // Left's Left vs Right's Right AND Left's Right vs Right's Left
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root) {
    // An empty tree is technically symmetric
    if (root == NULL) return true;
    
    // Start comparing the left and right subtrees from the root
    return isMirror(root->left, root->right);
}
