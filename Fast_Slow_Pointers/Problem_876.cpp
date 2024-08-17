/*  Day 19: Problem 876 - Middle of the Linked List
    Given the head of a singly linked list, return the middle node of the linked list.
    If there are TWO middle nodes, return the SECOND middle node.
*/


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Two pointers: slow and fast moving at different paces
        ListNode *slow = head, *fast = head;

        // fast will travel ahead until reaches end.
        while(fast && fast->next) {
            // fast moves two nodes
            fast = fast->next->next;
            // slow moves to next node
            slow = slow->next;
        }

        return slow;
    }
};

/*  Time Complexity: O(N) because fast pointer traverses to end of list.    Space Complexity: O(1) since we are using ListNode structs.
    Explanation: We use the fast variable to get to the end of the list and move two at a time. The slow variable moves like normal to the
    next in the list. The slow will reach middle when fast reaches end. 
*/