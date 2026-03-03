#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    
    // Read the number of elements
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0; // Exit if input is invalid or list size is 0
    }

    struct Node* head = NULL;
    struct Node* tail = NULL;

    // Read the elements and create the linked list
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        // Allocate memory for the new node
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        // If it's the first node, it becomes both head and tail
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            // Append the new node and update the tail
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Make the list circular by pointing the last node to the head
    if (tail != NULL) {
        tail->next = head;
    }

    // Traverse and print the circular linked list
    if (head != NULL) {
        struct Node* current = head;
        
        // Use a do-while loop to ensure we print the head node 
        // before the loop checks the (current != head) condition.
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
        
        printf("\n");
    }

    // Free the allocated memory to prevent memory leaks
    if (head != NULL) {
        struct Node* current = head;
        struct Node* nextNode;
        do {
            nextNode = current->next;
            free(current);
            current = nextNode;
        } while (current != head);
    }

    return 0;
}
