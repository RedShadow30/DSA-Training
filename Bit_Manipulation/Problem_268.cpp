/* Day 16
   Problem 268: Missing Number
   Explanation: Given an array nums containing n distinct numbers in the range [0, n], 
   return the only number in the range that is missing from the array.
*/


class Solution {
public:
    // XOR
    int missingNumber(vector<int>& nums) {
       int ans=nums.size();

       // traverse nums and xor each num in nums to itself. This is to find the missing number.
       for(int i = 0; i < nums.size(); i++) {
            /* if # ^ 0 then #. 
               if # ^ same # then 0. 
               # ^ diff # = #^diff.
            */
            ans = ans ^ i;          // XOR with index
            ans = ans ^ nums[i];    // XOR with val at index
        }

        return ans;
    }
};


/* Time Complexity: O(N)        Space Complexity: O(1)
   Explanation: We use the XOR operation to find the missing number from nums. In the for loop,
   e.g. [3,0,1] we XOR each number and the number left is 2. 
   i goes 0, 1, 2
   ans is 3

    3^3^0^0^1^1^2= dups cancel leaving 2
*/