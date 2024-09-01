/* Day 31: Problem 303 - Range Sum Query
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
*/

class NumArray {
public:
    // dynamic programming
    NumArray(vector<int>& nums) {
        // begin sum with 0
        numbers.push_back(0);
        // add next sum by adding current num to last num in numbers
        for(int n : nums)
            numbers.push_back(numbers.back() + n);    
    }
    
    int sumRange(int left, int right) {
        // return sum by subtracting right+1 (inclusive) and left
        return numbers[right+1] - numbers[left];
    }
private:
    vector<int> numbers;
};

/* Time Complexity: O(N) since we traverse N numbers.   Space Complexity: O(N) since we store N sums.
 * Explanation: The nums input vector is used to generate the sums as we traverse the vector. We added the sum
 * found so far into numbers vector. Dynamic programming problem since we are adding the lastly found sum + new
 * number to the sum storing list. This makes it easier when finding the sum range as we need to get the sum from
 * index right+1 (since inclusive) and subtract sum found at index left.
*/