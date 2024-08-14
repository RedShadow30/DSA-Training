/* Day 16
   Problem 215: Contains Duplicate
   Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // use hashmap to keep track of freq of each value
        unordered_map<int, int> numFreqs;

        // Traverse nums and update freq of each num. Return true if num reaches freq >= 2
        for(int n : nums) {
            numFreqs[n]++;
            if(numFreqs[n] >= 2) return true;
        }

        return false;
    }
};


/* Time Complexity: O(N) because traverses nums list.   Space Complexity: O(N) where worst case is all numbers in nums are unique. N numbers stored.
   Explanation: Since we need to return true as soon as ANY num reaches a freq >= 2. We can keep track of each
   number's frequency using a hashmap. If the number's freq reaches 2 or above then we return true else we continue.
   Once we exit the loop, it means that all the nums were unique there for we return false.
*/