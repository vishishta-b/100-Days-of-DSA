#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int lastNonZeroFoundAt = 0;

    // Iterate through the array
    for (int cur = 0; cur < numsSize; cur++) {
        // If the current element is non-zero
        if (nums[cur] != 0) {
            // Swap elements at cur and lastNonZeroFoundAt
            int temp = nums[lastNonZeroFoundAt];
            nums[lastNonZeroFoundAt] = nums[cur];
            nums[cur] = temp;

            // Move the slow pointer forward
            lastNonZeroFoundAt++;
        }
    }
}
