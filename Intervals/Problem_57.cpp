/*  Day 28: Problem 57 - Insert Interval
    Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
    Return intervals after the insertion.
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;

        // keep adding intervals from intervals iff newInterval does not overlap with it
        while(i < intervals.size() && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // modify newInterval with upcoming intervals if they can also be merged
        while(i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            i++;
        }
        // add updated newInterval to result
        result.push_back(newInterval);

        // add the remaining intervals 
        while(i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

/*  Time Complexity: O(N) since we traverse the N elements of intervals.    Space Complexity: O(N) since we are storing the N intervals in result.
    Explanation: First we declare a 2D vector to store the merged intervals. Then, we keep adding intervals from intervals iff the interval does not
    overlap with the newInterval. Once it does overlap, we enter the 2nd while loop where we modify the newInterval in case the following intervals 
    can be merged into it. After updates are complete, the interval is added to result. Finally, we add any remaining intervals into result and return it.
*/