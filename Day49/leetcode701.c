/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

// Helper function to allocate memory for a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    // Case 1: If the tree is empty, the new node becomes the root
    if (root == NULL) {
        return createNode(val);
    }

    struct TreeNode* curr = root;
    
    while (1) {
        // Case 2: Value is greater than current node -> go right
        if (val > curr->val) {
            if (curr->right == NULL) {
                curr->right = createNode(val);
                break;
            }
            curr = curr->right;
        } 
        // Case 3: Value is smaller than current node -> go left
        else {
            if (curr->left == NULL) {
                curr->left = createNode(val);
                break;
            }
            curr = curr->left;
        }
    }

    return root;
}
