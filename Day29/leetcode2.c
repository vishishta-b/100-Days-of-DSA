/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Use a dummy node to simplify list creation and avoid edge cases
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    
    struct ListNode* current = &dummy;
    int carry = 0;
    
    // Continue looping if there are still nodes to process or a leftover carry
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        
        // Add l1's value if available, then advance l1
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        // Add l2's value if available, then advance l2
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        // Calculate the new carry for the next iteration
        carry = sum / 10;
        
        // Create the new node with the single-digit result
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        
        // Attach the new node to our result list
        current->next = newNode;
        current = newNode;
    }
    
    // The dummy node's next pointer holds the actual head of our result list
    return dummy.next;
}
