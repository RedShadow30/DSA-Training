/* Day 10: Problem 438 - Find All Anagrams in a String
   Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
   An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

class Solution {
public:
    // Sliding window of size p.length(), return start if current window has equal freq of characters
    vector<int> findAnagrams(string s, string p) {
        // if size of s < p then return []
        if(s.length() < p.length()) return {};

        // ans vector to return
        vector<int> ans;

        // store the frequency of each letter in vector
        vector<int> mapW(26, 0);
        vector<int> mapP(26, 0);

        // Increase freq of each letter in p (target)
        for(auto x : p) {
            mapP[x - 'a']++;
        }
        // Increase freq of each letter in first window
        for(int i = 0; i < p.length(); i++) {
            mapW[s[i] - 'a']++;
        }

        if(mapW == mapP) ans.push_back(0);

        for(int i = p.length(); i < s.length(); i++) {
            // Delete char freq of old
            mapW[s[i-p.length()] - 'a']--;
           
            // Add new char to hashmap
            mapW[s[i] - 'a']++;

            if(mapW == mapP) ans.push_back(i-p.length()+1);
        }

        return ans;
    }
};

/* Time Complexity: O(N) where N is the length of string s. Space Complexity: O(N) where N is the length of string P.
   Need to continue working on this problem.
   Explanation: There are two vectors that store the frequency of the characters in the window. The window is size p.length() and is used to compare the frequency of the characters within the window and to the 
   frequency of characters in the string p. If they match then the starting index of current window, i-p.length()+1, is added to the ans vector. At the end, ans is returned.
*/
