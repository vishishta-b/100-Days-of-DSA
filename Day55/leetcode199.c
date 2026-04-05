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
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
    // Initialize return size to 0
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    // Since the number of nodes is up to 100, a result array of 100 is safe.
    // The maximum depth (and thus result size) cannot exceed the number of nodes.
    int* result = (int*)malloc(100 * sizeof(int));
    
    // BFS Queue: Use a simple array-based queue.
    // Max nodes = 100, so a size of 101 is sufficient.
    struct TreeNode** queue = (struct TreeNode**)malloc(101 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    // Start with the root
    queue[rear++] = root;

    while (front < rear) {
        // Number of nodes at the current level
        int levelSize = rear - front;
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

            // If this is the last node of the current level, add it to the result
            if (i == levelSize - 1) {
                result[(*returnSize)++] = node->val;
            }

            // Standard BFS: Add children to queue for the next level
            if (node->left) {
                queue[rear++] = node->left;
            }
            if (node->right) {
                queue[rear++] = node->right;
            }
        }
    }

    free(queue);
    return result;
}
