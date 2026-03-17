#include <stdio.h>
#include <stdlib.h>

#define MAX_CALLS 50005

typedef struct {
    int* maxHeap;
    int maxSize;
    int* minHeap;
    int minSize;
} MedianFinder;

// Swap helper
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// --- Max Heap Operations (Lower Half) ---
void pushMax(MedianFinder* obj, int val) {
    int i = obj->maxSize++;
    obj->maxHeap[i] = val;
    // Heapify Up
    while (i != 0 && obj->maxHeap[(i - 1) / 2] < obj->maxHeap[i]) {
        swap(&obj->maxHeap[(i - 1) / 2], &obj->maxHeap[i]);
        i = (i - 1) / 2;
    }
}

int popMax(MedianFinder* obj) {
    int root = obj->maxHeap[0];
    obj->maxHeap[0] = obj->maxHeap[--obj->maxSize];
    int i = 0;
    // Heapify Down
    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < obj->maxSize && obj->maxHeap[left] > obj->maxHeap[largest])
            largest = left;
        if (right < obj->maxSize && obj->maxHeap[right] > obj->maxHeap[largest])
            largest = right;
            
        if (largest == i) break;
        swap(&obj->maxHeap[i], &obj->maxHeap[largest]);
        i = largest;
    }
    return root;
}

// --- Min Heap Operations (Upper Half) ---
void pushMin(MedianFinder* obj, int val) {
    int i = obj->minSize++;
    obj->minHeap[i] = val;
    // Heapify Up
    while (i != 0 && obj->minHeap[(i - 1) / 2] > obj->minHeap[i]) {
        swap(&obj->minHeap[(i - 1) / 2], &obj->minHeap[i]);
        i = (i - 1) / 2;
    }
}

int popMin(MedianFinder* obj) {
    int root = obj->minHeap[0];
    obj->minHeap[0] = obj->minHeap[--obj->minSize];
    int i = 0;
    // Heapify Down
    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < obj->minSize && obj->minHeap[left] < obj->minHeap[smallest])
            smallest = left;
        if (right < obj->minSize && obj->minHeap[right] < obj->minHeap[smallest])
            smallest = right;
            
        if (smallest == i) break;
        swap(&obj->minHeap[i], &obj->minHeap[smallest]);
        i = smallest;
    }
    return root;
}

// --- LeetCode API Functions ---

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    // Allocate enough memory for the worst-case number of elements in either half
    obj->maxHeap = (int*)malloc(sizeof(int) * MAX_CALLS);
    obj->minHeap = (int*)malloc(sizeof(int) * MAX_CALLS);
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    // 1. Add to max heap
    pushMax(obj, num);
    
    // 2. Balance the values (largest of lower half goes to upper half)
    pushMin(obj, popMax(obj));
    
    // 3. Balance the sizes (Max heap should always have >= elements than Min heap)
    if (obj->maxSize < obj->minSize) {
        pushMax(obj, popMin(obj));
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxSize > obj->minSize) {
        return (double)obj->maxHeap[0];
    } else {
        return ((double)obj->maxHeap[0] + (double)obj->minHeap[0]) / 2.0;
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}
