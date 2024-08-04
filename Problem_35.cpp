/* Day 12 - Problem 35 - Search Insert Position
   Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
   You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:
    // Binary search because O(log N) time complexity
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high) {
            int middle = low + (high - low) / 2;
            if(nums[middle] == target) {
                return middle;
            }
            else if (nums[middle] > target) {
                high = middle -1;
            }
            else if (nums[middle] < target) {
                low = middle + 1;
            }
        }

        return low;
    }
};

/* Time Complexity: O(log N)   Space Complexity: O(1)
   Explanation: Simple binary search algorithm where we need to find the target value and return it's index if it exists. Else, return index low since it would be inserted after low index if it does not exist.
*/

