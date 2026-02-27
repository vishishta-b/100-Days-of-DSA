#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to get the length of a linked list
int getCount(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find the intersection using the difference of lengths
int getIntersection(int d, struct Node* head1, struct Node* head2) {
    struct Node* current1 = head1;
    struct Node* current2 = head2;

    // Move the pointer of the longer list forward by 'd' nodes
    for (int i = 0; i < d; i++) {
        if (current1 == NULL) return -1;
        current1 = current1->next;
    }

    // Traverse both lists simultaneously until a match is found
    while (current1 != NULL && current2 != NULL) {
        if (current1->data == current2->data) {
            return current1->data;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return -1;
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    // Input for first list
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (head1 == NULL) {
            head1 = temp;
            tail1 = temp;
        } else {
            tail1->next = temp;
            tail1 = temp;
        }
    }

    // Input for second list
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (head2 == NULL) {
            head2 = temp;
            tail2 = temp;
        } else {
            tail2->next = temp;
            tail2 = temp;
        }
    }

    // Calculate lengths and find intersection
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int intersectionVal;

    if (c1 > c2) {
        intersectionVal = getIntersection(c1 - c2, head1, head2);
    } else {
        intersectionVal = getIntersection(c2 - c1, head2, head1);
    }

    if (intersectionVal != -1) {
        printf("%d\n", intersectionVal);
    } else {
        printf("No Intersection\n");
    }

    return 0;
}
