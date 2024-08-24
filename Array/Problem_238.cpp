/*  Day 25: Problem 238 - Product of Array Except Self
    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
    You must write an algorithm that runs in O(n) time and without using the division operation.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // if size is 2 then return the reverse of nums
        if(nums.size() == 2) {
            reverse(nums.begin(), nums.end());
            return nums;
        }

        // Initialize vector of size nums, each storing 1
        vector<int> result(nums.size(), 1);
        int prod = 1;
        // traverse nums and find prefix product (total product of #s before current, exclusive)
        for(int i = 0; i < nums.size(); i++) {
            result[i] *= prod;
            prod *= nums[i];
        }
        
        prod = 1;
        // traverse nums and multiply each num with suffix product (total product of #s after current, exclusive)
        for(int i=nums.size()-1; i >= 0; i--) {
            result[i] *= prod;
            prod *= nums[i];
        }

        // Return result  
        return result;      
    }
};

/*  Time Complexity: O(N) because we are traversing nums.    Space Complexity: O(1) if we do not include the final result vector.
    Explanation: We first check if the size of nums is 2. If so, we return the reverse of nums. If not then we create a vector of size nums and 
    set each value to 1. Then, we create a variable to keep track of the total product as we traverse nums. We replace each num in the result
    vector with the product so far aka prefix product (multiply each # before current, exclusive). Next, we go in the opposite direction, starting
    at the end of nums and move to the front. We find the product and multiply the suffix product to the current spot. This is an O(N) solution that
    has each spot storing the total product in the array except itself.
*/