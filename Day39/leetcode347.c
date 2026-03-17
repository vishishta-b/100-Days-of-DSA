#include <stdio.h>
#include <stdlib.h>

// Structure to hold the array value and its frequency
typedef struct {
    int val;
    int freq;
} Node;

// Helper to swap two nodes in the heap
void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

// Maintain heap property from top to bottom
void heapifyDown(Node* heap, int size, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && heap[left].freq < heap[smallest].freq)
        smallest = left;
    if (right < size && heap[right].freq < heap[smallest].freq)
        smallest = right;

    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

// Maintain heap property from bottom to top
void heapifyUp(Node* heap, int idx) {
    int parent = (idx - 1) / 2;
    if (idx > 0 && heap[idx].freq < heap[parent].freq) {
        swap(&heap[idx], &heap[parent]);
        heapifyUp(heap, parent);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    // Step 1: Count frequencies using a direct mapped array
    // Constraints say nums[i] is between -10^4 and 10^4
    int offset = 10000;
    int range = 20001;
    int* freq = (int*)calloc(range, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + offset]++;
    }

    // Step 2: Build a Min-Heap of size k to track the top elements
    Node* heap = (Node*)malloc(k * sizeof(Node));
    int heapSize = 0;

    for (int i = 0; i < range; i++) {
        if (freq[i] > 0) {
            if (heapSize < k) {
                // Heap isn't full yet, just insert
                heap[heapSize].val = i - offset;
                heap[heapSize].freq = freq[i];
                heapifyUp(heap, heapSize);
                heapSize++;
            } else if (freq[i] > heap[0].freq) {
                // Current frequency beats the lowest frequency in our top K
                // Replace the root and fix the heap
                heap[0].val = i - offset;
                heap[0].freq = freq[i];
                heapifyDown(heap, k, 0);
            }
        }
    }

    // Step 3: Extract the results from the heap
    *returnSize = k;
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = heap[i].val;
    }

    // Free allocated memory
    free(freq);
    free(heap);

    return result;
}
