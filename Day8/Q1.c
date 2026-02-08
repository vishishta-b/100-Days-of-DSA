#include <stdio.h>

long long power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    else {
        return a * power(a, b - 1);
    }
}

int main() {
    int a, b;

    if (scanf("%d %d", &a, &b) == 2) {
        printf("%lld\n", power(a, b));
    }

    return 0;
}
