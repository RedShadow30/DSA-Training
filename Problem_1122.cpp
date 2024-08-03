/* Day 12 - Problem 1122 - Relative Sort Array
   Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
   Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;       

        // count freq of each num in arr1
        unordered_map<int, int> freqs;

        // count frequencies of each number in arr1
        for(int n : arr1) freqs[n]++;

        // for each num in arr2, loop freq times
        for(int n : arr2) {
            // if exists in both arrs then add those freq times
            auto it = freqs.find(n);
            ans.insert(ans.end(), it->second, it->first);
            it->second = 0;
        }

        int size = ans.size();

        // if freq > 0 then add remaining elements to the end, freq (num.second) times
        for(auto num : freqs) {
            if(num.second > 0) {
                ans.insert(ans.end(), num.second, num.first);
            }
        }

        // sort end
        sort(ans.begin()+size, ans.end());
        
        return ans;
    }
};

/* Time Complexity: O(N * log(N))  N to traverse the list, and log(N) for binary search aka .find() method. Lines 16-18.     Space Complexity: O(N) represents the ans vector
   Explanation: For each number in arr2, count it's frequency in arr1. Then, for each num in arr2, find if it exists in the map and add it freq (it->second) times to ans vector. Set the num's freq to 0 
   to make sure we do not add it more than needed. Store the current size of ans to be able to later sort the "end". The "end" are the elements that do not exist in arr2. For any nums in map that have 
   a freq > 0, add num to the end of the ans. Use size var to sort the end of ans. Return ans.
*/
