/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

// Helper function to check if a node is a leaf
int isLeaf(struct TreeNode* node) {
    if (node == NULL) return 0;
    return (node->left == NULL && node->right == NULL);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int sum = 0;

    // Check if the left child exists
    if (root->left != NULL) {
        // If the left child is a leaf, add its value
        if (isLeaf(root->left)) {
            sum += root->left->val;
        } else {
            // If it's not a leaf, continue searching in the left subtree
            sum += sumOfLeftLeaves(root->left);
        }
    }

    // Always continue searching in the right subtree for more left leaves
    sum += sumOfLeftLeaves(root->right);

    return sum;
}
