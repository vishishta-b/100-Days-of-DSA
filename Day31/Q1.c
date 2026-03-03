#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);

        if (op == 1) { 
            int val;
            scanf("%d", &val);
            stack[++top] = val;
            
        } else if (op == 2) { 
            if (top == -1) {
                printf("Stack Underflow\n");
            } else {
                printf("%d\n", stack[top--]); 
            }
            
        } else if (op == 3) { 
            if (top != -1) {
                for (int j = top; j >= 0; j--) {
                    printf("%d", stack[j]);
                    if (j > 0) {
                        printf(" ");
                    }
                }
                printf("\n");
            } else {
                printf("\n");
            }
        }
    }

    free(stack);

    return 0;
}
