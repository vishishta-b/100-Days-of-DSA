struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    while (head != NULL) {
        struct ListNode* next_node = head->next;
        head->next = prev;
        prev = head;
        head = next_node;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;
    
   while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Step 2: Reverse the second half (starting from slow)
    slow = reverseList(slow);
    fast = head; // Repurpose 'fast' to point to the start of the list
    
    // Step 3: Compare both halves
    while (slow != NULL) {
        if (fast->val != slow->val) {
            return false; // Mismatch found, not a palindrome
        }
        fast = fast->next;
        slow = slow->next;
    }
    
    return true; // All values matched
}
