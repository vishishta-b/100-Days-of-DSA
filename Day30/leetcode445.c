struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // LeetCode constraints specify list lengths are between 1 and 100
    int stack1[100];
    int stack2[100];
    int top1 = -1;
    int top2 = -1;
    
    // Push all values of l1 onto stack1
    while (l1 != NULL) {
        stack1[++top1] = l1->val;
        l1 = l1->next;
    }
    
    // Push all values of l2 onto stack2
    while (l2 != NULL) {
        stack2[++top2] = l2->val;
        l2 = l2->next;
    }
    
    struct ListNode* head = NULL;
    int carry = 0;
    
    // Pop from stacks, add values, and build the result list backwards
    while (top1 >= 0 || top2 >= 0 || carry > 0) {
        int sum = carry;
        
        if (top1 >= 0) {
            sum += stack1[top1--];
        }
        
        if (top2 >= 0) {
            sum += stack2[top2--];
        }
        
        // Calculate new carry and the digit for the current node
        carry = sum / 10;
        
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        
        // Attach the new node to the front of our result list
        newNode->next = head;
        head = newNode;
    }
    
    return head;
}
