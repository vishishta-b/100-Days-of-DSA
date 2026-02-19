#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* res = (int*)malloc(numsSize * sizeof(int));

    res[0] = 1; 
    for (int i = 1; i < numsSize; i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }
    
    int suffix = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        res[i] = res[i] * suffix;
        suffix *= nums[i];
    }
    
    return res;
}
