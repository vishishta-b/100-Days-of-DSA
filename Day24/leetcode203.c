/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    // 1. Create a dummy node to simplify head deletion
    struct ListNode dummy;
    dummy.next = head;
    
    // 2. Use a 'current' pointer to traverse the list
    struct ListNode* curr = &dummy;
    
    while (curr->next != NULL) {
        if (curr->next->val == val) {
            // 3. Match found: Skip the node
            struct ListNode* temp = curr->next;
            curr->next = curr->next->next;
            // Note: In a real-world scenario, you might free(temp) here
            // depending on how memory management is handled.
        } else {
            // 4. No match: Just move to the next node
            curr = curr->next;
        }
    }
    
    // 5. Return the new head (which is dummy.next)
    return dummy.next;
}
