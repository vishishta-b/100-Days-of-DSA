#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    // Set the return size
    *returnSize = temperaturesSize;
    
    // Allocate memory for the result array and initialize it with 0s.
    // calloc is perfect here because if we never find a warmer day, 
    // the answer defaults to 0.
    int* result = (int*)calloc(temperaturesSize, sizeof(int));
    
    // Simulate a stack to hold indices
    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    int top = -1; // -1 means the stack is empty
    
    for (int i = 0; i < temperaturesSize; i++) {
        // While stack is not empty AND the current temp is warmer than the temp 
        // at the index stored at the top of the stack
        while (top > -1 && temperatures[i] > temperatures[stack[top]]) {
            int prevIndex = stack[top]; // Get the index of the colder day
            top--; // Pop it from the stack
            
            // The number of days waited is the difference in indices
            result[prevIndex] = i - prevIndex; 
        }
        
        // Push the current index onto the stack to wait for a warmer day
        top++;
        stack[top] = i;
    }
    
    // Free the simulated stack to prevent memory leaks
    free(stack);
    
    return result;
}
