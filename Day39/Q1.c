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
    if (right < heap->size && heap->array[right] < heap->array[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->array[index], &heap->array[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Insert a new element into the heap
void insert(MinHeap* heap, int x) {
    if (heap->size == heap->capacity) {
        // Double the capacity if full
        heap->capacity *= 2;
        heap->array = (int*)realloc(heap->array, heap->capacity * sizeof(int));
    }
    
    // Insert at the end
    heap->array[heap->size] = x;
    int currentIndex = heap->size;
    heap->size++;
    
    // Fix the Min Heap property
    heapifyUp(heap, currentIndex);
}

// Return the smallest element without removing it
int peek(MinHeap* heap) {
    if (heap->size <= 0) {
        return -1;
    }
    return heap->array[0];
}

// Remove and return the smallest element
int extractMin(MinHeap* heap) {
    if (heap->size <= 0) {
        return -1;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    // Store the minimum value to return later
    int root = heap->array[0];
    
    // Move the last element to the root
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    
    // Fix the Min Heap property
    heapifyDown(heap, 0);
    
    return root;
}

// Free allocated memory
void freeHeap(MinHeap* heap) {
    free(heap->array);
    free(heap);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // We can safely initialize the capacity to 'n' because the 
    // maximum number of elements inserted cannot exceed 'n'.
    MinHeap* heap = createHeap(n);
    char command[20];
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        
        if (strcmp(command, "insert") == 0) {
            scanf("%d", &value);
            insert(heap, value);
        } 
        else if (strcmp(command, "extractMin") == 0) {
            printf("%d\n", extractMin(heap));
        } 
        else if (strcmp(command, "peek") == 0) {
            printf("%d\n", peek(heap));
        }
    }

    freeHeap(heap);
    return 0;
}
