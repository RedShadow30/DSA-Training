/*  Day 17:
    Problem 136 - Single Number
    Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
    You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

class Solution {
public:
    // XOR Problem
    int singleNumber(vector<int>& nums) {
        // Looking for the number that appears odd number of times
        int ans = 0;
        // Traverse nums
        for(int n : nums) {
            ans^=n;
        }
        // return result
        return ans;
    }
};

/*  Time Complexity: O(N) because traversed nums.    Space Complexity: O(1) because only one int variable used (ans).
    Explanation: Using the XOR Gate to find the number with ODD frequencies. Even frequencies results in 0 so number 
    that has only one frequency will continue to exist.
 */