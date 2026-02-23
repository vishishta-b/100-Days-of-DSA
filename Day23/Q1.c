#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node
void appendNode(struct Node** head, struct Node** tail, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    }
    (*tail)->next = newNode;
    *tail = newNode;
}

// Function to merge two sorted linked lists iteratively
struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    struct Node* dummy = createNode(0);
    struct Node* tail = dummy;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }
    
    struct Node* mergedHead = dummy->next;
    free(dummy);
    return mergedHead;
}

int main() {
    int n, m, data;
    struct Node* list1 = NULL;
    struct Node* tail1 = NULL;
    struct Node* list2 = NULL;
    struct Node* tail2 = NULL;
    
    // Read first list
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        appendNode(&list1, &tail1, data);
    }
    
    // Read second list
    if (scanf("%d", &m) != 1) return 1;
    for (int i = 0; i < m; i++) {
        scanf("%d", &data);
        appendNode(&list2, &tail2, data);
    }
    
    // Merge the lists
    struct Node* mergedList = mergeSortedLists(list1, list2);
    
    // Print the merged list
    struct Node* temp = mergedList;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
    
    // Free the merged list
    while (mergedList != NULL) {
        temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }
    
    return 0;
}
