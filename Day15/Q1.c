#include <stdio.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    long long diagonal_sum = 0;
    int current_val;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &current_val);

            if (i == j) {
                diagonal_sum += current_val;
            }
        }
    }

    printf("%lld\n", diagonal_sum);

    return 0;
}
