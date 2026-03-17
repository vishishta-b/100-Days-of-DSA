#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Min Heap structure
typedef struct {
    int *array;
    int capacity;
    int size;
} MinHeap;

// Initialize a new Min Heap
MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// Helper functions to get indices
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return (2 * i) + 1; }
int rightChild(int i) { return (2 * i) + 2; }

// Helper function to swap two integers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Maintain heap property from bottom to top (used after insertion)
void heapifyUp(MinHeap* heap, int index) {
    while (index != 0 && heap->array[parent(index)] > heap->array[index]) {
        swap(&heap->array[parent(index)], &heap->array[index]);
        index = parent(index);
    }
}

// Maintain heap property from top to bottom (used after extraction)
void heapifyDown(MinHeap* heap, int index) {
    int smallest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < heap->size && heap->array[left] < heap->array[smallest]) {
        smallest = left;
    }
    if (right < heap->size && heap->array[right] < heap->array
