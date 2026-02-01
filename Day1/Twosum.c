#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // 1. Set the size of the return array (LeetCode requires this)
    *returnSize = 2;

    // 2. Allocate memory for the result (2 integers)
    int* result = (int*)malloc(2 * sizeof(int));
    if (result == NULL) return NULL; // Safety check for memory allocation

    // 3. Loop through each element
    for (int i = 0; i < numsSize; i++) {
        // 4. Loop through the *remaining* elements
        for (int j = i + 1; j < numsSize; j++) {
            // Check if they add up to the target
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result; // Return immediately once found
            }
        }
    }
    
    // If no solution is found (though the problem guarantees one)
    *returnSize = 0;
    return NULL;
}
