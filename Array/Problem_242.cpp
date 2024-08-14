/* Day 9 - Problem 242 - Valid Anagram
   Given two strings s and t, return true if t is an anagram of s, and false otherwise.
   An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        // if t and s are not the same length then we cannot make an anagram
        if(s.length() != t.length()) return false;

        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        // Determine the char freq of each word and if the numbers are the same then we have an anagram
        for(int i = 0; i < s.length(); i++) {
            map1[s[i]]++;
            map2[t[i]]++;
        }

        return map1 == map2;
    }
};

/* Time Complexity: O(N) where N is length of the strings.
   Compare the length of the strings and if they are not the same then return false. Some letters may be missing so we cannot create a valid anagram. If the strings have equal length then we can add the frequency
   of each character in the strings to its respective hashmap and compare the frequencies of characters in both the hashmaps. If the hashmaps have equal frequencies then that is a valid anagram.
*/
