#include <stdlib.h>

// Standard Node Structure
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// The main object used by LeetCode
typedef struct {
    Node* head; // This will point to our Sentinel Node
    int size;
} MyLinkedList;

// Helper to create a new raw node
Node* createNewNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = createNewNode(-1); // Sentinel node
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;
    
    Node* curr = obj->head->next; // Skip sentinel
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = createNewNode(val);
    newNode->next = obj->head->next;
    obj->head->next = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = createNewNode(val);
    Node* curr = obj->head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) return;
    if (index < 0) index = 0;

    Node* curr = obj->head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    
    Node* newNode = createNewNode(val);
    newNode->next = curr->next;
    curr->next = newNode;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;

    Node* curr = obj->head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    
    Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}
