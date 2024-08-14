/* Day 6 - Problem 74 - Search a 2D Matrix
   You are given an m x n integer matrix matrix with the following two properties:
  
   Each row is sorted in non-decreasing order.
   The first integer of each row is greater than the last integer of the previous row.
   Given an integer target, return true if target is in matrix or false otherwise.
  
   You must write a solution in O(log(m * n)) time complexity.
*/

class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Look through the rows and find the right row to look in
        int start = 0, end = matrix.size()-1, mid = (start+end)/2;
        int row;
        while(start <= end) {
            // first element is too small then update start
            if(target > matrix[mid][0]) {
                start = mid+1;
            }
            // first element is too big then update end
            else if(target < matrix[mid][0]) {
                end = mid-1;
            }
            else {
                row = mid;
                break;
            }

            // update mid and set row to mid
            mid=(start+end)/2;
            row = mid;
        }

        // Look through cols to find target
        start = 0, end = matrix[0].size()-1, mid = (start+end)/2;
        while(start <= end) {
            // middle of row is too big then update end
            if(target < matrix[row][mid]) {
                end = mid-1;
            }
            // middle of row is too small then update start
            else if(target > matrix[row][mid]) {
                start = mid+1;
            }
            // found target
            else {
                return true;
            }

            // update mid
            mid = (start+end)/2;
        }

        return false;
    }
};

/* Time Complexity : O(log M*N)    Space Complexity : O( 4 ) for the four int variables
   Explanation: We are using Binary Search twice. The first time to locate the correct row to look through. The update of mid = (start+end)/2 does interger division and start <= end both 
   ensure that we are scanning the correct row where we do not skip it just because the start is < the target. The second Binary Search looks through the chosen row to find target. Keeps looking as long as
   start is <= end.
*/ 

// ALTERNATIVE O(N) APPROACH is to look at the last elements of the rows and find the row where target is < the last element. Look through that row and check if target exists. This, however, has a time complexity of O(N).

class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Variables to traverse the rows and look at the last element of each row
        int rows = matrix.size(), cols = matrix[0].size(), row = 0, col = cols-1;

        // Traverse the rows while it is less than max rows and col not out of bounds
        while( row < rows && col > -1) {
            // look at last element of row
            int cur = matrix[row][col];

            // found target
            if(cur == target) return true;

            // go to next row if last element is too small
            if(cur < target) row++;
            // shift to previous col in row if last element is too big
            else col--;
        }

        return false;
    }
};
