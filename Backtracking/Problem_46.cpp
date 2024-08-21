/*  Day 23: Problem 46 - Permutations
    Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/

class Solution {
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int index) {
        // if index is beyond nums size, then combo complete
        if(index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // traverse nums
        for(int i = index; i < nums.size(); i++) {
            // get different combo by switching nums at index and i
            swap(nums[index], nums[i]);
            // recursive call incrementing index to next pos
            backtrack(nums, ans, index+1);
            // get different combo by switching back to OG
            swap(nums[index], nums[i]);
        }
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        // store results in this vector
        vector<vector<int>> result;

        // backtracking problem
        backtrack(nums, result, 0);

        // return result
        return result;
    }
};

/*  Time Complexity: O(N!) because it contains a recursive function.
    Space Complexity: O(N) where it stores the N numbers from nums in a vector.

    Explanation: This is a backtracking problem that given an input vector of unique numbers. The numbers are sent to a recursive function backtrack()
    where it keeps track of nums, result, and index. For each index visited, we swap num at index with i and recursively backtrack() this generates one
    possible combo. The recursive call also moves the index to the right by 1 so that the next combo start from the new index. Then it is swapped again 
    to return it to the OG state. This is done from start to end index of nums, generating all possible combos. The base case is when index reaches 
    nums.size(), in which case, we have a combo ready to add to result.
*/