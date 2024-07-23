/* Day 2:
   Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
   In other words, return true if one of s1's permutations is the substring of s2.
*/

class Solution {
public:
    bool isEqual(int arr1[26], int arr2[26]) {
        int size = sizeof(arr1)/sizeof(int);

        // Traverse and make sure all values in both arrays match
        for(int i = 0; i < size; ++i) {
            if(arr1[i] != arr2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
       // Fixed Window Size Approach
       // We are trying to find s1 in s2. Frequency matters, window size of s1.
       int len1 = s1.length();
       int len2 = s2.length();

       // if s1 is a longer string then it can't be in s2
       if(len1 > len2) return false;

        // Get all character frequency
        int chars1[26] = {0};
        int chars2[26] = {0};

        // Count frequency of each letter in current window.
        for(int i = 0; i < len1; ++i) {
            chars1[s1[i] - 97]++;
            chars2[s2[i] - 97]++;
        }

        if(isEqual(chars1, chars2)) return true;

        // Slide the window down s2
        for(int i = len1; i < len2; ++i) {
            // Update the hasmap of the second string to know if s1 perm exists in that window
            chars2[s2[i] - 97]++;
            // Shift window by deleting freq of leftmost char
            chars2[s2[i-len1] - 97]--;

            // If same char frequency (hashmaps are equal) as s1 then return true
            if(isEqual(chars1, chars2)) return true;
        }
        // return false if no perms found
        return false;
    }
};

/*
    Time Complexity: O(N2) because goes through all chars in s2 to update frequency.  Space Complexity: O(1) since data is stored in variables and arrays that have O(1) access.
    Substring is when letters must be adjacent, no intruder letters.
*/
