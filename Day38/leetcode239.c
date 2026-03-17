#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    // Edge case handling
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    // The number of windows will be numsSize - k + 1
    *returnSize = numsSize - k + 1;
    int* result = (int*)malloc(sizeof(int) * (*returnSize));

    // Array to simulate the deque (stores indices, not values)
    int* deque = (int*)malloc(sizeof(int) * numsSize);
    int front = 0, rear = -1;

    for (int i = 0; i < numsSize; i++) {
        // 1. Remove elements from the front that are out of the current window bounds
        if (front <= rear && deque[front] < i - k + 1) {
            front++;
        }

        // 2. Remove elements from the rear that are smaller than the current element
        // They are useless because the current element is bigger and appears later
        while (front <= rear && nums[deque[rear]] < nums[i]) {
            rear--;
        }

        // 3. Add the current element's index to the rear
        deque[++rear] = i;

        // 4. If our window has reached size k, record the maximum (which is at the front)
        if (i >= k - 1) {
            result[i - k + 1] = nums[deque[front]];
        }
    }

    // Clean up our simulated deque
    free(deque);
    
    return result;
}
