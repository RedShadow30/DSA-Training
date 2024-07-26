/* Day 5: Problem 2 - Add Two Numbers
   You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit.
   Add the two numbers and return the sum as a linked list.
   You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        int carry = 0;

        // loop through lists as long as one of them is not empty or carry is not 0
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0;
            // add l1's digit to sum
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            // add l2's digit to sum
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            // add any carry from previous sum
            sum += carry;
            carry = sum/10; // if > 10, set it so can be added in next loop
            dummy->next = new ListNode(sum%10); // if sum was 12 then 2 is digit to add, connect to tail
            dummy = dummy->next; // update tail
        }
        return head->next; 
    }
};

/* Time Complexity: O(N) where N is the number of elements in the list. Space Complexity: O(N) since we are storing a list with at least N digit length where N is the # of numbers in the list.
  Explanation: Since we need to return the head of a linked list, we need to create a dummy node that will build the list. The head points at the list's starting node. We loop as long as 
  there are nodes in either of the lists OR there a carry that needs to be added. The carry are for test cases where the number of digits increase after adding (e.g. 9 + 1 = 10 goes from single to double digits).
  We add to the sum and find the carry with '/10' and number to add to the next node in list with '%10'. We are done once no nodes are left and carry = 0. We return the head.
*/
