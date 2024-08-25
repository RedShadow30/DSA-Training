/*  Day 26: Problem 54 - Spiral Matrix
    Given an m x n matrix, return all elements of the matrix in spiral order.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // initialize length of row and cols and direction variables. declare result variable
        int rows = matrix.size(), cols = matrix[0].size(), x = 0, y = 0, dx = 1, dy = 0;
        vector<int> result;

        // loop through matrix. add current value to result variable
        for(int i = 0; i < rows*cols; i++) {
            result.push_back(matrix[y][x]);
            // update matrix with garbage value so not revisited
            matrix[y][x] = -999;

            // change direction of traversal if will go outside bounds or visited value
            if(!(0 <= x+dx && x+dx < cols && 0 <= y+dy && y+dy < rows) || matrix[y+dy][x+dx] == -999) {
                int temp = dx;
                dx = -dy;
                dy = temp;
            }

            // move pointer to next value in direction specified
            x += dx;
            y += dy;

        }

        return result;
    }
};

/*  Time Complexity: O(N) because traversing through the matrix with one for-loop.       Space Complexity: O(N) because stored in a vector with N elements (size of matrix).
    Explanation: Store the number of rows and cols in matrix. Determine the starting position for traversing (left-corner of matrix). use two variables dx, dy to set the direction
    of which the traversal will go. For loop to traverse matrix, add to result, replace with garbage value (any # outside input range) so it is not revisited. Next, check if we need to update the 
    direction where we do if we are going outside the bounds or if we are going to a visited cell. Update the x and y value towards the dx and dy direction. Lastly, return result.
*/