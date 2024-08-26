/*  Day 27: Problem 141 - Linked List Cycle
 *
 *  Given head, the head of a linked list, determine if the linked list has a cycle in it.
 *  There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
 *  Return true if there is a cycle in the linked list. Otherwise, return false.
 * 
 *  Definition for singly-linked list.
 *  struct ListNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 *  };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // make sure that there is two or more nodes first
        if(head == nullptr || head->next == nullptr) return false;

        // two pointers: fast and slow to see if the meet each other
        ListNode *fast = head->next->next, *slow = head;

        // keep going thru list as long as the pointers don't meet 
        while(slow != fast) {
            // check if we can continue to move the fast pointer forward (nodes exist after)
            // if no nodes exist after that means that we have a "non-cycle" linked list
            if(fast == nullptr || fast->next == nullptr)  return false;
            fast = fast->next->next;
            slow = slow->next;
        }

        // pointers intersected so loop exited and can return true
        return true;
    }
};

/*  Time Complexity: O(N) because we move through the entire list of N nodes.       Space Complexity: O(1) since data is stored in a struct with O(1) access time.
    Explanation: First we make sure that there are at least 2 nodes to traverse through. Then we create two pointers: fast and slow. Fast will travel a node ahead of
    slow pointer. This means that if a cycle exists, they are bound to meet at some point. In the loop, we check for the condition of whether they met or not (point
    to the same node). If not then the loop continues traversing until there are no nodes left, at which point we would return false. In the case that they did intersect
    we would exit the while loop and return true at the end.
*/