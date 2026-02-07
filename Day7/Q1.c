#include <stdio.h>

long long fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    
    printf("Enter a number: ");
    if (scanf("%d", &n) == 1) {
        printf("The %d-th Fibonacci number is: %lld\n", n, fib(n));
    }
    
    return 0;
}
