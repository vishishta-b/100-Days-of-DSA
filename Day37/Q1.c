#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100005

int pq[MAX_SIZE];
int size = 0;

// Utility function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert an element into the priority queue
void insert(int x) {
    // Insert the new element at the end of the array
    pq[size] = x;
    int curr = size;
    int parent = (curr - 1) / 2;

    // Heapify up: restore min-heap property by comparing with parent
    while (curr > 0 && pq[parent] > pq[curr]) {
        swap(&pq[parent], &pq[curr]);
        curr = parent;
        parent = (curr - 1) / 2;
    }
    size++;
}

// Function to view the highest priority (minimum) element
int peek() {
    if (size == 0) {
        return -1;
    }
    return pq[0];
}

// Function to remove and return the highest priority (minimum) element
int delete_min() {
    if (size == 0) {
        return -1;
    }
    
    int min_val = pq[0];
    
    // Move the last element to the root
    pq[0] = pq[size - 1];
    size--;

    int curr = 0;
    
    // Heapify down: restore min-heap property
    while (1) {
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;
        int smallest = curr;

        // Check if left child is smaller than current
        if (left < size && pq[left] < pq[smallest]) {
            smallest = left;
        }
        // Check if right child is smaller than the current smallest
        if (right < size && pq[right] < pq[smallest]) {
            smallest = right;
        }

        // If the smallest is not the current node, swap and continue
        if (smallest != curr) {
            swap(&pq[curr], &pq[smallest]);
            curr = smallest;
        } else {
            break; // Heap property is restored
        }
    }
    
    return min_val;
}

int main() {
    int n;
    // Read the number of operations
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    char op[10];
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            printf("%d\n", delete_min());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}
