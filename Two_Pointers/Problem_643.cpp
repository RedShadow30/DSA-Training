/*  Day 29: Problem 643 - Maximum Average Subarray I
    You are given an integer array nums consisting of n elements, and an integer k.
    Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value.
    Any answer with a calculation error less than 10-5 will be accepted.
*/

class Solution {
public:
    // sliding window
    double findMaxAverage(vector<int>& nums, int k) {
        // store current sum and max sum
        double currSum = 0, maxSum = 0;

        // get first window's sum
        for(int i = 0; i < k; i++) {
            currSum += nums[i];
        }
        maxSum = currSum;

        // start at k and find rest of the sums, keep max sum
        for(int i = k; i < nums.size(); i++) {
            // add current num to sum
            currSum += nums[i] - nums[i-k];
            // update maxSum
            maxSum = max(maxSum, currSum);
        }

        // return avg of with max sum
        return maxSum / k;
    }
};

/*  Time Complexity: O(N) since we traverse all N elements in nums.     Space Complexity: O(1) since we store in the
    variables currSum and maxSum.
    Explanation: Find the first window's sum and update it as the max sum we have found so far. Then move through the rest
    of the nums where we add the current num and removed (subtract) the num that is no longer in the window length of k. 
    Update maxSum if needed. At the end we return the maxSum we found divided by k.

*/