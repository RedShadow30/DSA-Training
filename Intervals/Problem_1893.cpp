/* Day 32: Problem 1893 - All Integers in Range are Covered
*/

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        // sort the range
        sort(ranges.begin(), ranges.end());

        // traverse ranges
        for(auto row : ranges) {
            // check if left and right ARE the interval or IN the interval
            if(row[0] <= left && row[1] >= right){
                return true;
            }
            // left must be in the interval, check if right is in interval by increasing left up to right
            else if(row[0] <= left && row[1] < right) {
                left = max(row[1]+1, left);
            }
        }
        return false;
    }
};

/*  Time Complexity: O(N Log N) since we used sort().   Space Complexity: O(1) because we are using variables.
    Explanation: We sort the intervals in non-decreasing order. Then traverse the intervals in ranges, we check
    to see if left and right represent the current interval we are at or are inside it. Left must at least be in 
    the interval, if not then left is increased to reach value of right
*/