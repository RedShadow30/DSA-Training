/* Day 11: Problem 28 - Find index of first Occurence in a string 
   Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution {
public:
    // Anagram problem, sliding window is solution. Optimized sol is 2 vector. Could also use hashmap.
    int strStr(string haystack, string needle) {
        // if needle is too long then return -1
        if(haystack.length() < needle.length()) return -1;

        // Check if same length and first window is same string
        if(haystack.length() == needle.length() && haystack == needle) return 0;
        
        // Look in first window
        if(haystack.substr(0, needle.length()) == needle) return 0;
        
        // Look through rest of the string if not in first window
        if(haystack.find(needle)) return haystack.find(needle);
        
        return -1;
    }
};

/* Time Complexity: O(N)   Space Complexity: O(1)
   The program covers four cases that can happen with the two strings. First case is to address when string to look in is too small, return -1. Second case is to address when the strings are equal length 
   AND equal. Third case is to check if the first window of length needle in string haystack equal to string needle. Fourth case is to check if remaining part of the string, haystack, has a string equal 
   to needle. If none of the cases then return -1;
*/
