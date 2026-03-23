/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* curr = root;

    while (curr != NULL) {
        // If both nodes are smaller than current, move left
        if (p->val < curr->val && q->val < curr->val) {
            curr = curr->left;
        }
        // If both nodes are larger than current, move right
        else if (p->val > curr->val && q->val > curr->val) {
            curr = curr->right;
        }
        // We found the split point (one is left, one is right, or curr is p or q)
        else {
            return curr;
        }
    }
    
    return NULL;
}
