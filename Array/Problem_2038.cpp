/* Day 14: Problem 2038 - Remove Colored Pieces if Neighbors are same color */

class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.length() < 3) return false;

        // Track consecutive plays
        int Alice = 0, Bob = 0;

        // Continue looping until string <= 3
        for(int i = 1; i < colors.length()-1; ++i) {
            // look for a AAA
            if(colors[i-1] == 'A' && colors[i] == 'A' && colors[i+1] == 'A')
                Alice++;
            // look for a BBB after
            if(colors[i-1] == 'B' && colors[i] == 'B' && colors[i+1] == 'B')
                Bob++;
        }

        // if Bob had more plays then false because he went last
        return Alice > Bob;

    }
};

/* Time Complexity: O(N) where N is length of the string.     Space Complexity: O(1) since only two variables used to store info.
   Explanation: We find the number of "AAA" and "BBB" combos within the string. Who ever has more wins, where we return true if Alice has more. 
*/
