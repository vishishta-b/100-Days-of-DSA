#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    // Read the number of elements to push
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0; // Exit if input is invalid or 0
    }

    // Dynamically allocate the stack based on n
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1; // Initialize stack as empty

    // Push n elements onto the stack
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        stack[++top] = val; 
    }

    // Read the number of pops
    if (scanf("%d", &m) == 1) {
        // Pop m elements by simply decrementing the top pointer
        for (int i = 0; i < m; i++) {
            if (top >= 0) {
                top--;
            }
        }
    }

    // Display the remaining elements from top to bottom
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) {
            printf(" "); // Space separator
        }
    }
    printf("\n");

    // Free allocated memory
    free(stack);

    return 0;
}
