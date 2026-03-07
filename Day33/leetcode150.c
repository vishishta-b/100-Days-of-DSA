#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper to check if a string is an operator
bool isOperator(char* s) {
    // Must be length 1 and one of the four operators
    return strlen(s) == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/');
}

int evalRPN(char** tokens, int tokensSize) {
    // Allocate stack on the heap based on the number of tokens
    long* stack = (long*)malloc(sizeof(long) * tokensSize);
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        if (isOperator(tokens[i])) {
            // Pop the two operands
            long b = stack[top--];
            long a = stack[top--];
            long result = 0;

            switch (tokens[i][0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            // Push the result back
            stack[++top] = result;
        } else {
            // Convert string to long and push to stack
            // atol is used to handle potentially large intermediate values
            stack[++top] = atol(tokens[i]);
        }
    }

    int finalResult = (int)stack[top];
    free(stack); // Clean up memory
    return finalResult;
}
