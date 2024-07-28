/* Day 7: Problem 56 - Merge Intervals
   Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        // Add first element
        result.push_back(intervals[0]);

        // Traverse all the intervals and merge if previous end is >= current start
        for(int i = 1; i < intervals.size(); i++) {
            // merge with last interval in result
            if(intervals[i][0] <= result[result.size()-1][1]) {
                result[result.size()-1][1] = max(result[result.size()-1][1], intervals[i][1]);
            }
            // add interval if does not overlap
            else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};

/* Time Complexity: O(N) where N is the # of intervals.
   Explanation: We move through the intervals list and add it to the result 2D vector if the previous interval's end is not >= the current interval's start number. If it is then we update the last interval's end
   # in result to the max of the the current interval's end and the last interval's end. Finall return result with merged intervals.
*/
       
