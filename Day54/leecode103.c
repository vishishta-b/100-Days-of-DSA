#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    // Base case: empty tree
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    // The maximum number of nodes is 2000, so the maximum number of levels 
    // and queue operations will not exceed 2000.
    int max_nodes = 2005; 
    
    // Allocate memory for the 2D result array and the column sizes array
    int** result = (int**)malloc(max_nodes * sizeof(int*));
    *returnColumnSizes = (int*)malloc(max_nodes * sizeof(int));
    *returnSize = 0;
    
    // Array-based queue to hold tree nodes
    struct TreeNode** queue = (struct TreeNode**)malloc(max_nodes * sizeof(struct TreeNode*));
    int front = 0;
    int rear = 0;
    
    // Initialize BFS with the root node
    queue[rear++] = root;
    int left_to_right = 1; // 1 represents True (left to right), 0 represents False
    
    while (front < rear) {
        int level_size = rear - front;
        
        // Allocate an array for the current level's values
        int* level_vals = (int*)malloc(level_size * sizeof(int));
        
        for (int i = 0; i < level_size; i++) {
            // Dequeue node
            struct TreeNode* node = queue[front++];
            
            // Calculate index based on the current zigzag direction
            int index = left_to_right ? i : (level_size - 1 - i);
            level_vals[index] = node->val;
            
            // Enqueue children for the next level
            if (node->left != NULL) {
                queue[rear++] = node->left;
            }
            if (node->right != NULL) {
                queue[rear++] = node->right;
            }
        }
        
        // Store the level array and its size
        (*returnColumnSizes)[*returnSize] = level_size;
        result[*returnSize] = level_vals;
        (*returnSize)++;
        
        // Toggle direction for the next level
        left_to_right = !left_to_right; 
    }
    
    // Free the dynamically allocated queue
    free(queue);
    
    return result;
}
