#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000 

long long countSubarrays(int arr[], int n) {
    long long count = 0;
    long long current_sum = 0;

    struct {
        long long sum;
        int freq;
    } map[MAX_SIZE];
    
    int map_size = 0;
    
    for (int i = 0; i < n; i++) {
        long long temp_sum = 0;
        for (int j = i; j < n; j++) {
            temp_sum += arr[j];
            if (temp_sum == 0) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%lld\n", countSubarrays(arr, n));

    free(arr);
    return 0;
}
