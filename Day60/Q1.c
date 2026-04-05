#include <stdio.h>
#include <stdlib.h>

// Function to check if the given array represents a Min-Heap
int isMinHeap(int* arr, int n) {
    // We only need to check the internal nodes.
    // The last internal node is at index (n - 2) / 2.
    for (int i = 0; i <= (n - 2) / 2; i++) {
        
        // Check if the left child exists and is strictly smaller than the parent
        if (2 * i + 1 < n && arr[i] > arr[2 * i + 1]) {
            return 0; // False: Min-Heap property violated
        }
        
        // Check if the right child exists and is strictly smaller than the parent
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2]) {
            return 0; // False: Min-Heap property violated
        }
    }
    
    return 1; // True: Min-Heap property holds for all nodes
}

int main() {
    int n;
    
    // Input: Number of nodes
    if (scanf("%d", &n) != 1) {
        return 1; // Error reading input
    }
    
    // Allocate memory for the tree
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // Input: Level-order traversal
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Output the result
    if (isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    // Clean up memory
    free(arr);
    
    return 0;
}
