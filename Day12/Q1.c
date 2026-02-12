#include <stdio.h>
#include <stdbool.h>

int main() {
    int m, n;

    if (scanf("%d %d", &m, &n) != 2) return 0;

    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    int matrix[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    bool isSymmetric = true;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = false;
                break; 
            }
        }
        if (!isSymmetric) break;
    }

    if (isSymmetric) {
        printf("Symmetric Matrix\n");
    } else {
        printf("Not a Symmetric Matrix\n");
    }

    return 0;
}
