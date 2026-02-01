#include <stdio.h>

int main() {
    int n, pos, x;

    // Input the initial size
    if (scanf("%d", &n) != 1) return 1;

    // Define array with extra space for the new element
    int arr[n + 1];

    // Input the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position and value to insert
    scanf("%d", &pos);
    scanf("%d", &x);

    // Convert 1-based position to 0-based index
    int index = pos - 1;

    // Shift elements to the right
    // We start from the end of the array and move backwards
    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[index] = x;

    // Print the updated array
    for (int i = 0; i <= n; i++) {
        printf("%d%s", arr[i], (i == n) ? "" : " ");
    }
    printf("\n");

    return 0;
}