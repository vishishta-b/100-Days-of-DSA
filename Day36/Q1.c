#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int front, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[(front + i) % n]);
    }
    printf("\n");
}

int main() {
    int n, m;

    // Input: Number of elements
    if (scanf("%d", &n) != 1) return 0;

    // Dynamic memory allocation for the array
    int *queue = (int *)malloc(n * sizeof(int));
    
    // Input: n integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Input: m dequeue operations
    if (scanf("%d", &m) != 1) return 0;

    // In a circular queue, dequeuing 'm' times simply moves the front pointer
    // The elements aren't "deleted," the starting point just shifts.
    int front = m % n;

    // Output elements from the new front to rear
    display(queue, front, n);

    free(queue);
    return 0;
}
