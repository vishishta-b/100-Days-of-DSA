#include <stdio.h>

int main() {
    int n;
    
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n <= 0) return 0;
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}
