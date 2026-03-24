/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // 1. Base Case: If root is null or matches p or q, return root
    if (root == NULL || root == p || root == q) {
        return root;
    }

    // 2. Recursive calls for left and right subtrees
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // 3. If both left and right returned something, current root is the LCA
    if (left != NULL && right != NULL) {
        return root;
    }

    // 4. If only one side returned a node, return that non-NULL side
    // (If both are NULL, this naturally returns NULL)
    return (left != NULL) ? left : right;
}
