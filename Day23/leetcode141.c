/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    // If the list is empty or has only one node, no cycle is possible
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Move fast by 2 and slow by 1
    // We check fast->next to ensure fast->next->next doesn't crash
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move 1 step
        fast = fast->next->next;    // Move 2 steps

        // If they meet, there is a cycle
        if (slow == fast) {
            return true;
        }
    }

    // If we reach the end of the list, there is no cycle
    return false;
}
