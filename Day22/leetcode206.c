#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = NULL;

    while (curr != NULL) {
        // 1. Save the next node
        next = curr->next;
        
        // 2. Reverse the current node's pointer
        curr->next = prev;
        
        // 3. Move pointers one position forward
        prev = curr;
        curr = next;
    }

    // After the loop, prev will be the new head
    return prev;
}
