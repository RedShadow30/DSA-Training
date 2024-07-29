/* Day 8: Problem 83 - Remove Duplicates from Sorted Array
   Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
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
    // Must delete dups and sort
    ListNode* deleteDuplicates(ListNode* head) {
        // To 'delete', update the prev's pointer's next to the next node
        set<int> uniques;

        // Keep track of the current node and prec
        ListNode* current = head;
        ListNode* prev = head;

        // traverse list and add elements to a set if does not already exist. 
        while(current != nullptr) {
            // if does exist then update pointers and compare new current to 
            if(uniques.find(current->val) != uniques.end() ) {
                cout << current->val << " ";
                prev->next = current->next;
                current = prev->next;
            }
            // only move to next value if inserted a unique
            else {
                uniques.insert(current->val);
                prev = current;
                current = current->next;
            }
        }

        return head;
    }
};

/* [ Time taken: 17 m 4 s ]
   Time Complexity: O(N log N) because while-loop * find()
   Space Complexity: O(N) because stored in set
  
   Set to contain and compare the unique numbers.
   As we look at each number in the list, we update the pointers using dummy vars 'current' and 'prev' if the current value is a duplicate (exists in set).
   Recall, find() method of set has a time complexity of O(log N) as it uses binary search.
   If the current value exists, then we also update the prev value's next pointer to point to the curr value's next number. and update the current to the prev value's next. This is so that we do not skip of repeating duplicates.
   The only time we have a "normal" traversal is if we found a unique number. In which case, we add the value to the set, update the prev to point to the current, and update the current to point to the next value.
   We exit the loop once we point to nullptr and return the head.
*/
