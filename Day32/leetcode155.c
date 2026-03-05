#include <stdlib.h>

// Define a structure that holds both the value and the minimum at that level
typedef struct {
    int val;
    int min;
} Element;

typedef struct {
    Element* arr;
    int top;
} MinStack;

// LeetCode constraints specify at most 3 * 10^4 calls will be made
#define MAX_SIZE 30000

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->arr = (Element*)malloc(MAX_SIZE * sizeof(Element));
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->arr[obj->top].val = val;
    
    // If it's the first element, it is the minimum
    if (obj->top == 0) {
        obj->arr[obj->top].min = val;
    } else {
        // Otherwise, the min is the smaller of the new value and the previous min
        int current_min = obj->arr[obj->top - 1].min;
        obj->arr[obj->top].min = (val < current_min) ? val : current_min;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->arr[obj->top].val;
}

int minStackGetMin(MinStack* obj) {
    return obj->arr[obj->top].min;
}

void minStackFree(MinStack* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
