/* Day 13 - Problem 206 - Reverse Linked List
 *  Given the head of a singly linked list, reverse the list, and return the reversed list.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        ListNode* nextNode = nullptr;

        // Traverse list and swap pointer addresses
        while(currNode != nullptr) {
            // store next node in the list
            nextNode = currNode->next;
            // node after current becomes previous
            currNode->next = prevNode;
            // previous becomes current
            prevNode = currNode;
            // current node becomes next node
            currNode = nextNode;
        }

        // return head of reversed list aka previous node
        return prevNode;
    }
};

/* Time Complexity: O(N)   Space Complexity: O(1)
   Explanation: We traverse the list and swap the pointer addresses of the nodes in the list. 
*/
