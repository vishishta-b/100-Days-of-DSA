#include <stdio.h>
#include <stdlib.h>

int main() {
    int p, q;

    if (scanf("%d", &p) != 1) return 0;
    int *log1 = (int *)malloc(p * sizeof(int));
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    if (scanf("%d", &q) != 1) return 0;
    int *log2 = (int *)malloc(q * sizeof(int));
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    int i = 0;
    int j = 0;

    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }

    printf("\n");

    free(log1);
    free(log2);

    return 0;
}
