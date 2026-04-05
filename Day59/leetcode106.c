#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

// Helper function to allocate a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive helper to build the tree
struct TreeNode* build(int* inorder, int inStart, int inEnd, 
                       int* postorder, int postStart, int postEnd) {
    
    // Base case: if pointers cross, subtree is empty
    if (inStart > inEnd || postStart > postEnd) {
        return NULL;
    }

    // 1. The last element in the current postorder range is the root
    int rootVal = postorder[postEnd];
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

    // 4. Recursively build subtrees
    // Left Subtree:
    //   Inorder: inStart to inIndex - 1
    //   Postorder: postStart to postStart + leftSize - 1
    root->left = build(inorder, inStart, inIndex - 1, 
                       postorder, postStart, postStart + leftSize - 1);

    // Right Subtree:
    //   Inorder: inIndex + 1 to inEnd
    //   Postorder: postStart + leftSize to postEnd - 1 (exclude the root we just used)
    root->right = build(inorder, inIndex + 1, inEnd, 
                        postorder, postStart + leftSize, postEnd - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorderSize == 0) return NULL;
    
    return build(inorder, 0, inorderSize - 1, 
                 postorder, 0, postorderSize - 1);
}
