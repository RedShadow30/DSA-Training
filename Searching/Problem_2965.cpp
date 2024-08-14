/* Day 4: Problem 2965 - Find Missing and Repeated Values
   You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. 
   Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.
   Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.
*/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // declare ans
        vector<int> ans;
        // declare hashmap
        // hashmap to keep track of a number's frequency; number : freq
        unordered_map<int, int> nums;

        // Traverse from 1 to grid.size() * grid.size()
        int size = grid.size() * grid.size();
        for(int i = 1; i <= size; ++i)
            // add each number to the hashmap & set to 0
            nums[i] = 0;

        // Traverse the 2D matrix
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[row].size(); col++) {
                // increase freq of num with ++
                int n = grid[row][col];
                nums[n]++;
                // check if freq == 2, yes then add it to the ans vector
                if(nums[n] == 2)
                    ans.push_back(n);
            }
        }

        // Traverse from 1 to grid.size() * grid.size()
        for(int i = 1; i <= size; ++i){
            // if freq is 0 then add it to ans vector -> b
            if(nums[i] == 0)
                ans.push_back(i);
        }

        // return ans
        return ans;
    }
};

/*
  [ Time taken: 25 m 39 s ]   Time Complexity: O(N^2)    Space Complexity: O(N)
  Traverse range from 1 to row size * row size and add each number to hashmap with freq of 0. These are all the possible values to appear. 
  Traverse 2D matrix and increase each number's frequency by 1 in the HashMap. For each number check if its freq is now 2. If so, then add it to the ans vector.
  At end, traverse the range again and find which number has a freq of 0. Add it to the ans vector. Return ans at the end.
*/
