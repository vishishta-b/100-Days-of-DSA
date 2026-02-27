/*
Structure of the node of the linked list is as
struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        if (!head || !head->next) return;

        Node *slow = head;
        Node *fast = head;

        // Step 1: Detect the loop using Floyd's Cycle-Finding Algorithm
        bool loopFound = false;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                loopFound = true;
                break;
            }
        }

        // Step 2: If a loop exists, find the starting point
        if (loopFound) {
            slow = head;
            
            // Special Case: Loop starts at the Head node
            if (slow == fast) {
                while (fast->next != slow) {
                    fast = fast->next;
                }
            } 
            // Standard Case: Move both pointers until they meet at the node 
            // just before the loop start
            else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            // Step 3: Break the loop by setting the last node's next to NULL
            fast->next = NULL;
        }
    }
};
