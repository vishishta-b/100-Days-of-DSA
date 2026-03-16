#include <stdlib.h>

// Define the struct for our KthLargest object
typedef struct {
    int *heap;
    int size;
    int capacity; // This is our 'k'
} KthLargest;

// Utility function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Restores the min-heap property by bubbling an element up
void heapifyUp(KthLargest *obj, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && obj->heap[index] < obj->heap[parent]) {
        swap(&obj->heap[index], &obj->heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Restores the min-heap property by bubbling an element down
void heapifyDown(KthLargest *obj, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < obj->size && obj->heap[left] < obj->heap[smallest]) {
        smallest = left;
    }
    if (right < obj->size && obj->heap[right] < obj->heap[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&obj->heap[index], &obj->heap[smallest]);
        heapifyDown(obj, smallest);
    }
}

// Adds a value to the stream and returns the Kth largest element
int kthLargestAdd(KthLargest* obj, int val) {
    // If we haven't reached capacity k yet, just insert the new element
    if (obj->size < obj->capacity) {
        obj->heap[obj->size] = val;
        heapifyUp(obj, obj->size);
        obj->size++;
    } 
    // If the heap is full, but the new value is larger than our Kth largest (root),
    // replace the root and heapify down to find the new Kth largest.
    else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }
    
    // The root is always the Kth largest element
    return obj->heap[0];
}

// Constructor to initialize the object and the stream
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *obj = (KthLargest *)malloc(sizeof(KthLargest));
    obj->capacity = k;
    obj->size = 0;
    // Allocate memory for exactly k elements
    obj->heap = (int *)malloc(k * sizeof(int));

    // Process the initial array
    for (int i = 0; i < numsSize; i++) {
        kthLargestAdd(obj, nums[i]);
    }
    
    return obj;
}

// Destructor to free the allocated memory
void kthLargestFree(KthLargest* obj) {
    if (obj) {
        free(obj->heap);
        free(obj);
    }
}
