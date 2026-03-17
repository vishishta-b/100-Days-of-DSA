#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int calculate(char* s) {
    int len = strlen(s);
    if (len == 0) return 0;

    // In the worst case (e.g., "1+1+1..."), the stack needs len/2 space
    int* stack = (int*)malloc(sizeof(int) * len);
    int top = -1;

    long currNum = 0;
    char lastOp = '+';

    for (int i = 0; i <= len; i++) {
        char c = (i < len) ? s[i] : '\0'; // Virtual end of string

        if (isdigit(c)) {
            currNum = currNum * 10 + (c - '0');
        }

        // If it's an operator or the end of the string (ignoring spaces)
        if ((!isdigit(c) && c != ' ' ) || i == len) {
            if (lastOp == '+') {
                stack[++top] = currNum;
            } else if (lastOp == '-') {
                stack[++top] = -currNum;
            } else if (lastOp == '*') {
                stack[top] = stack[top] * currNum;
            } else if (lastOp == '/') {
                stack[top] = stack[top] / currNum;
            }
            
            lastOp = c;
            currNum = 0;
        }
    }

    int result = 0;
    while (top != -1) {
        result += stack[top--];
    }

    free(stack);
    return result;
}
