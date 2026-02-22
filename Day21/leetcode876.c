#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Move fast pointer twice as fast as slow pointer
    // Ensure fast and fast->next are not NULL to avoid segmentation faults
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move 1 step
        fast = fast->next->next;    // Move 2 steps
    }

    // When fast reaches the end, slow is at the middle
    return slow;
}
