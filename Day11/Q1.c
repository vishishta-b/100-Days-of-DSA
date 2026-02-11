#include <stdio.h>

int main() {
    int m, n;

    
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int first[m][n], second[m][n], sum[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &first[i][j]);
        }
    }

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &second[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] = first[i][j] + second[i][j];

            printf("%d", sum[i][j]);
            if (j < n - 1) {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
