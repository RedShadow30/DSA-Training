/*  Day 33: Problem 79 - Word Search
    Given an m x n grid of characters board and a string word, return true if word exists in the grid.
    The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically 
    neighboring. The same letter cell may not be used more than once.
*/

class Solution {
public:
    bool backtrack(string word, vector<vector<char>>& board, int i, int j) {
        // if word is empty then return true
        if(word.length() < 1) return true;

        // check boundaries and char at current location. return false if wrong letter or outside boundaries
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
            return false;

        // store a dummy char in spot if found correct letter
        char temp = board[i][j];
        board[i][j] = '\0';

        // check in all directions: above, below, left, and right. reducing word
        if(backtrack(word.substr(1), board, i-1, j) || backtrack(word.substr(1), board, i+1, j) ||
           backtrack(word.substr(1), board, i, j-1) || backtrack(word.substr(1), board, i, j+1))
            return true;

        // if did not find the correct letters then replace with O.G. letter
        board[i][j] = temp;
        return false;
        
    }

    bool exist(vector<vector<char>>& board, string word) {
        // traverse thru matrix
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                // see if it is the start of letter in word, if yes then look for other letters recursively
                if(backtrack(word, board, i, j))
                    return true;
            }
        }

        return false;
    }
};

/*  Time Complexity: O(m*n*4^l) where m and n are the dimensions of the matrix. 4 represents the 4 different directions that the recursive
    call can go in and l represents the length of word.    
    
    Space Complexity: O(l) since we are storing the l length of letters from word if the word exists.
    
    Explanation: Traverse through the matrix until we find a letter that is the same as the first letter in word. This begins the recursive
    call to backtrack(). In backtrack(), our base case is to check if our word has a length < 1 meaning there are no letters left to look
    for and that we are done since all letter have been found successfully. In that base case, we return true. If not then we look to make
    sure we can visit surrounding cells. 
    If no surrounding cells to visit and no letters matched then we return false. 
    Else, we create 4 recursive calls where each visits one of the 4 directions from the cell. In each recursive call, the word is updated
    to send the rest of the letters except the first letter. In the case where none of the directions found the correct letter, the board
    is updated with the letters it originally had.
*/