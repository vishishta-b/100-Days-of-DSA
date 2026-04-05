#include <stdio.h>
#include <stdlib.h>

// Tree Node structure
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Linked List Node for storing vertical columns
typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

// Queue Item for BFS traversal
typedef struct {
    Node* treeNode;
    int hd;
} QItem;

// Utility function to create a new tree node
Node* createTreeNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Utility function to create a new linked list node
ListNode* createListNode(int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (arr[0] == -1) {
        free(arr);
        return 0;
    }

    // 1. Build the Binary Tree from level-order input
    Node* root = createTreeNode(arr[0]);
    Node** buildQueue = (Node**)malloc(n * sizeof(Node*));
    int bFront = 0, bRear = 0;
    
    buildQueue[bRear++] = root;
    int i = 1;
    
    while (bFront < bRear && i < n) {
        Node* curr = buildQueue[bFront++];
        
        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = createTreeNode(arr[i]);
            buildQueue[bRear++] = curr->left;
        }
        i++;
        
        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createTreeNode(arr[i]);
            buildQueue[bRear++] = curr->right;
        }
        i++;
    }
    free(buildQueue);
    free(arr);

    // 2. Vertical Order Traversal using BFS
    int offset = n; 
    int min_hd = 0, max_hd = 0;
    
    // Arrays to maintain the head and tail of the linked list for each HD
    ListNode** heads = (ListNode**)calloc((2 * n + 1), sizeof(ListNode*));
    ListNode** tails = (ListNode**)calloc((2 * n + 1), sizeof(ListNode*));

    QItem* traverseQueue = (QItem*)malloc(n * sizeof(QItem));
    int tFront = 0, tRear = 0;
    
    // Push root with HD = 0
    traverseQueue[tRear].treeNode = root;
    traverseQueue[tRear].hd = 0;
    tRear++;

    while (tFront < tRear) {
        QItem current = traverseQueue[tFront++];
        Node* currNode = current.treeNode;
        int hd = current.hd;

        // Track the minimum and maximum horizontal distance found
        if (hd < min_hd) min_hd = hd;
        if (hd > max_hd) max_hd = hd;

        // Map the current HD to an array index (shift by 'offset' to avoid negative indices)
        int index = hd + offset;

        // Append to the linked list for this HD (O(1) insertion using tail pointer)
        ListNode* newListNode = createListNode(currNode->data);
        if (heads[index] == NULL) {
            heads[index] = newListNode;
            tails[index] = newListNode;
        } else {
            tails[index]->next = newListNode;
            tails[index] = newListNode;
        }

        // Push children to queue
        if (currNode->left != NULL) {
            traverseQueue[tRear].treeNode = currNode->left;
            traverseQueue[tRear].hd = hd - 1;
            tRear++;
        }
        if (currNode->right != NULL) {
            traverseQueue[tRear].treeNode = currNode->right;
            traverseQueue[tRear].hd = hd + 1;
            tRear++;
        }
    }

    // 3. Print the results from min_hd to max_hd
    for (int j = min_hd; j <= max_hd; j++) {
        int index = j + offset;
        ListNode* temp = heads[index];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    // Cleanup
    free(traverseQueue);
    free(heads);
    free(tails);

    return 0;
}
