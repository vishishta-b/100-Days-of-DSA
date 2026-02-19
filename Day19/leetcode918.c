#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;
    int currMax = 0, maxSum = nums[0];
    int currMin = 0, minSum = nums[0];

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];

        currMax = MAX(x, currMax + x);
        maxSum = MAX(maxSum, currMax);

        currMin = MIN(x, currMin + x);
        minSum = MIN(minSum, currMin);

        totalSum += x;
    }

    if (maxSum < 0) {
        return maxSum;
    }

    return MAX(maxSum, totalSum - minSum);
}
