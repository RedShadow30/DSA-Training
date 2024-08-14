/* Day 14 - Problem 283 - Move Zeroes
   Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
   Note that you must do this in-place without making a copy of the array.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Two pointer approach
        int l = 0;

        // iterate through the list
        for(int r = 0; r < nums.size(); r++) {
            // if right is non-zero then swap. increase left and right (loop)
            if(nums[r] != 0) {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++;
            }
        }   
    }
};

/* Time Complexity: O(N)   Space Complexity: O(1)
   Explanation: We traverse the list and use two pointers to keep track of left index where there is a zero and right index where we currently are in the list. We swap IFF the right index contains a number that 
   is non-zero.
*/
