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

// Global variable to keep track of the total cameras used
int cameras;

/**
 * Helper function that returns the state of the node:
 * 0: Node has a camera
 * 1: Node is covered by a camera
 * 2: Node is NOT covered (Needs a camera)
 */
int solve(struct TreeNode* root) {
    // Base case: If the node is NULL, it's considered "covered" 
    // so we don't try to put a camera on it.
    if (root == NULL) return 1;

    int left = solve(root->left);
    int right = solve(root->right);

    // If either child is NOT covered, the current node MUST have a camera.
    if (left == 2 || right == 2) {
        cameras++;
        return 0;
    }

    // If either child has a camera, the current node is now covered.
    if (left == 0 || right == 0) {
        return 1;
    }

    // Otherwise, both children are covered but don't have cameras,
    // so the current node is not covered (waiting for its parent).
    return 2;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    
    // If the root itself ends up needing a camera (State 2), 
    // we must add one more camera.
    if (solve(root) == 2) {
        cameras++;
    }
    
    return cameras;
}
