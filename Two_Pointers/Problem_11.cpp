/*  Day 24: Problem 11 - Container with Most Water
    You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
    Find two lines that together with the x-axis form a container, such that the container contains the most water.
    Return the maximum amount of water a container can store. Notice that you may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int st = 0, end = height.size()-1;

        // find maxArea based on index difference and height diff
        while(st < end) {
            // find area by finding diff in indices and multiply to smaller height
            maxArea = max(maxArea, (end-st) * min(height[st], height[end]));

            // move left pointer if height on left is smaller else move right pointer
            if(height[st] < height[end]) st++;
            else end--;
        }

        // return maxArea
        return maxArea;
    }
};

/*  Time Complexity: O(N) because we are traversing the height vector.      Space Complexity: O(1) because numbers are stored in int variables.
    Explanation: We use a two pointers approach to solve this problem. As we traverse the height vector of integers, we compare the numbers at index
    st and index end. We find the smaller height and multiply it to the width which is the difference of their indices, end and st. If the new area
    is greater than the max then maxArea is updated. To update the pointer, we move the pointer on the left if the left height is smaller else we
    move the right pointer to the left. Finally, we return maxArea.
*/