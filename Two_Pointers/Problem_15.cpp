/*  Day 22: Problem 15 - 3Sum
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
    Notice that the solution set must not contain duplicate triplets.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        // sort first to choose which numbers could decrease or increase total if added to list
        sort(nums.begin(), nums.end());

        // traverse nums
        for(int i = 0; i < nums.size(); i++) {
            // check if current num is duplicate of prev, skip if yes
            if(i > 0 && nums[i] == nums[i-1]) 
                continue;
            // set two pointers
            int j = i+1;
            int k = nums.size()-1;

            // j and k pointers must point to different elements
            while(j < k) {
                // find current total
                int total = nums[i] + nums[j] + nums[k];

                // move k pointer if total is too big
                if(total > 0) k--;
                // move j pointer if total is too small
                else if(total < 0) j++;
                // add if correct combo where total is 0
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    // skip any duplicate triplets
                    while(nums[j] == nums[j-1] && j < k) j++;
                }
            }
        }
        return res;
    }
};

/*  Time Complexity: O(N^2) because we are traversing nums and checking combinations within the for-loop.
    Space Complexity: O(N) because we are storing in a vector. 
    Explanation: We first sort the input vector and then using two pointers to pick which numbers to include into the list to find a combination
    that would total to 0. The pointers allow us to select which numbers to include in the list. To avoid duplicates in combos generated, a while
    loop is used as soon as a combo is added to make sure the same number (j points at) is not added.
 */