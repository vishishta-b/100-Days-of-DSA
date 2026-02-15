#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    bool is_identity = true;
    int current_val;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &current_val);
            if (i == j) {
                if (current_val != 1) {
                    is_identity = false;
                }
            } 
            else {
                if (current_val != 0) {
                    is_identity = false;
                }
            }
        }
    }

    if (is_identity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}
