/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

// Helper macro to find the maximum of two integers
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxDepth(struct TreeNode* root) {
    // Base case: If the tree is empty, the depth is 0
    if (root == NULL) {
        return 0;
    }
    
    // Recursively find the depth of left and right subtrees
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    
    // The depth of the current node is 1 plus the maximum of its subtrees
    return 1 + MAX(left, right);
}
