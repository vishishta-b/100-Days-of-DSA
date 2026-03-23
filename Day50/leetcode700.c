#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Base Case: root is null (not found) or root is the value (found!)
    if (root == NULL || root->val == val) {
        return root;
    }

    // If target is smaller than root, search left
    if (val < root->val) {
        return searchBST(root->left, val);
    }

    // If target is larger than root, search right
    return searchBST(root->right, val);
}
