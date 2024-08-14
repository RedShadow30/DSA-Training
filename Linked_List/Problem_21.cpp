/* Day 3: Problem 21 - Merge Two Sorted Lists
  You are given the heads of two sorted linked lists list1 and list2.
  Merge the two lists into one sorted list. The list should be made by SPLICING together the nodes of the first two lists.
  Return the head of the merged linked list.
  
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       // Create the dummy node and its tail
       ListNode *dummy = new ListNode();
       ListNode *tail = dummy;

       while(list1 != nullptr && list2 != nullptr) {
        // List 1's element is inserted
        if(list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        }
        // List 2's element is inserted
        else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
       }

       // If one of the list empty then append the non-empty list to the tail
        if(list1 != nullptr) {
            tail->next = list1; 
        }
        else if(list2 != nullptr) {
            tail->next = list2;
        }

        // Return the head
        return dummy->next;
    }
};

// Time Complexity : O(N) where N is the size of the bigger list.

/*
  Explanation: Given the head of both the lists, compare both the lists' values in the current node and add the smaller value. Depending on which list it was added from, move on to the next item of that list.
  If one list is bigger than the other, append the list with remaining elements to the end of the tail. Return the head aka dummy.
*/
