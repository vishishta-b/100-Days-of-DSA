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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    // 1. Initialize result pointers
    int** result = malloc(sizeof(int*) * 2000); // Max nodes is 2000
    *returnColumnSizes = malloc(sizeof(int) * 2000);
    
    // 2. Initialize Queue (using a simple array-based queue)
    struct TreeNode** queue = malloc(sizeof(struct TreeNode*) * 2000);
    int head = 0, tail = 0;
    
    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head; // Number of nodes at current level
        (*returnColumnSizes)[*returnSize] = levelSize;
        
        int* currentLevel = malloc(sizeof(int) * levelSize);
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];
            currentLevel[i] = node->val;
            
            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }
        
        result[(*returnSize)++] = currentLevel;
    }

    free(queue);
    return result;
}
