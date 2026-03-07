#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top < MAX - 1)
        stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

// Function to define operator precedence
int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

int main() {
    char exp[MAX];
    char x;
    
    printf("Enter infix expression: ");
    scanf("%s", exp);
    
    printf("Postfix expression: ");
    
    for (int i = 0; exp[i] != '\0'; i++) {
        // If operand, print it
        if (isalnum(exp[i])) {
            printf("%c", exp[i]);
        } 
        // If opening bracket, push to stack
        else if (exp[i] == '(') {
            push(exp[i]);
        } 
        // If closing bracket, pop until '(' is found
        else if (exp[i] == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        } 
        // If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i])) {
                printf("%c", pop());
            }
            push(exp[i]);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        printf("%c", pop());
    }
    
    printf("\n");
    return 0;
}
