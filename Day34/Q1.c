#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for a stack node
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap overflow\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct Node* temp = *top;
    int poppedVal = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedVal;
}

int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {
        // Skip whitespace
        if (exp[i] == ' ') continue;

        // If character is a digit, handle multi-digit numbers
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--; // Adjust index after inner loop
            push(&stack, num);
        } 
        // If character is an operator
        else {
            int val2 = pop(&stack); // Second operand
            int val1 = pop(&stack); // First operand
            
            switch (exp[i]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char exp[100];
    printf("Enter postfix expression (space separated): ");
    // Using %[^\n] to read strings with spaces
    scanf("%[^\n]s", exp);

    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}
