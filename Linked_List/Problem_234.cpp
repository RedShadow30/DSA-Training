/*  Day 45: Problem 234 - Palindrome Linked List
 *  Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
 *
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
    bool isPalindrome(ListNode* head) {
        vector<int> list, list2;
        
        while(head) {
            list.push_back(head->val);
            list2.push_back(head->val);
            head = head->next;
        }
        
        reverse(list.begin(), list.end());

        return list == list2;
    }
};

/*  Time Complexity: O(N) where all N numbers are traversed.    Space Complexity: O(N) where all N numbers are stored in list and list2
    Explanation: My approach is to get all the numbers from the linked list and store it into two lists. One list is reversed and compared with
    the original list. The boolean value is returned based on whether they are the same or not after reversing.
    Better Solution: O(1) use a Fast and Slow Pointer approach.
*/