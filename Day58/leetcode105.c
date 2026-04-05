#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

// Helper function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to build the tree
struct TreeNode* build(int* preorder, int preStart, int preEnd, 
                       int* inorder, int inStart, int inEnd) {
    
    // Base case: if pointers cross, the subtree is empty
    if (preStart > preEnd || inStart > inEnd) {
        return NULL;
    }

    // 1. The first element in preorder is the root
    int rootVal = preorder[preStart];
    struct TreeNode* root = createNode(rootVal);

    // 2. Find the index of this root in the inorder array
    int inIndex = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootVal) {
            inIndex = i;
            break;
        }
    }

    // 3. Calculate the size of the left subtree
    int leftSize = inIndex - inStart;

    // 4. Recursively build Left and Right subtrees
    // Left: 
    //   Preorder range: Move past current root, take 'leftSize' elements
    //   Inorder range: Start to index just before root
    root->left = build(preorder, preStart + 1, preStart + leftSize, 
                       inorder, inStart, inIndex - 1);

    // Right:
    //   Preorder range: Elements after the left subtree section
    //   Inorder range: Index just after root to the end
    root->right = build(preorder, preStart + leftSize + 1, preEnd, 
                        inorder, inIndex + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0) return NULL;
    
    return build(preorder, 0, preorderSize - 1, 
                 inorder, 0, inorderSize - 1);
}
