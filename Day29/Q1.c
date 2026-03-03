#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k;
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (scanf("%d", &k) != 1) {
        return 0;
    }

    k = k % n;

    if (k > 0) {
        tail->next = head;

        int stepsToNewTail = n - k;
        struct Node* newTail = head;
        
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        head = newTail->next;
        newTail->next = NULL;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    current = head;
    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}
