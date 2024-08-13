/* Day 15: Problem 40 - Combination Sum II
   Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
   Each number in candidates may only be used once in the combination. Note: The solution set must not contain duplicate combinations.
*/

class Solution {
public:
    // Backtracking needs result of combos, current combo, candidates with info to pick from, target to get to, index we are currently at
    void backtrack(vector<vector<int>>& res, vector<int>& combo, vector<int>& candidates, int target, int index) {
        // if target reached then add the current combo to result
        if(target == 0) {
            res.push_back(combo);
            return;
        }
        // move through the candidates while in bounds AND total left is >= current candidate. No negatives.
        for(int i = index; i < candidates.size() && target >= candidates[i]; ++i) {
            if(i == index || candidates[i] != candidates[i-1]) {
                // add the current candidate to combo
                combo.push_back(candidates[i]);
                // recursive call to evaluate combo with current candidate in combo, updated target and index
                backtrack(res, combo, candidates, target-candidates[i], i+1);
                // remove current candidate
                combo.pop_back();
            }
          /*
            else {
                  cout << "skipped " << candidates[i] << endl;
                  cout << "index: " << index << " i: " << i << endl;
              }
          */
        }
    }
    // returns the combinations that add up to target
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort candidates in ascending order
        sort(candidates.begin(), candidates.end());
        // initialize an array of lists to store the combinations
        vector<vector<int>> result;
        // initialize an array to store current combo
        vector<int> combo;
        // make call to backtrack with starting index at 0
        backtrack(result, combo, candidates, target, 0);
        // return combinations
        return result;
    }
};

/* Time Complexity: O(2^N) because we are moving through each element in candidates in the for-loop and creating a combination for each one. Worst case is we need to make all possible combo and can't "prune" any branches.
   Explanation: This program uses backtracking to create different combinations of the candidates that have a sum of 'target'. First, we sort the candidates into ascending order to deal with larger numbers towards the end.
   Then we initialize an empty vector of lists to store all the successful combinations we generate. Then we create an empty vector to store the current combo we are building. The backtrack() is a recursive function
   that will travel to the nodes of the "tree" aka candidates using index to determine the starting point. In backtrack(), we first check if the target is 0 meaning our combo has a sum of original target.
   If so, then we add the current combo to the result 2D vector and exit the recursive function. 
   Backtrack part:
   Else, we move to the for-loop where start at the index and add that to the current combo and make a recursive call to evaluate that combo. Then we remove it from the combo. We do this until the end of the 
   candidates list to generate a combination with and without each candidate. The loop continues so long as we are in bounds of the candidates list and the target is >= current candidate. 
   If i>index and candidates[i] is equal to previous candidate aka candidates[i-1] then skip to next candidate. This helps avoid duplication of the same candidate in a combination aka repeated combinations because
   of repeated candidates.
*/

