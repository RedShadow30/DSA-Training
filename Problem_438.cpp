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

        // Two pointers: start and start+2 for window size of p.length()-1
        int st, end = p.length()-1;

        // hashmaps to store char freq in window and p
        unordered_map <char, int> mapW;
        unordered_map <char, int> mapP;

        // store current frequency of characters in first window
        for(st = 0; st <= end; st++) {
            mapW[s[st]]++;
            mapP[p[st]]++;
        }

        if(mapW == mapP) ans.push_back(0);

        st = 1;
        // traverse the list with window size of three start at st=1 and end=3
        while(end < s.length()-1) {
            end++;
            // Delete char freq of old
            mapW[s[st-1]]--;
            cout << "st=" << s[st-1] << " " << mapW[s[st-1]] << endl;

            // Add new char to hashmap
            mapW[s[end]]++;
            cout << "end=" << s[end] << " " << mapW[s[end]] << endl;

            for(char m : p) cout << m << ":" << mapW[m] << " ";
            cout << endl;
            for(char m : p) cout << m << ":" << mapP[m] << " ";

            // if hashmap of p and window are equal then add st index to ans
            cout << "st=" << st;
             if(mapW == mapP){
                cout << "true";
             }
             else {
                cout << "false";
             }
             cout << endl;

            if(mapW == mapP) ans.push_back(st);
            st++;
            cout << endl;
        }

        return ans;
    }
};

/* Time Complexity: O(N) where N is the length of string s. Space Complexity: O(N) where N is the length of string P.
   Need to continue working on this problem.
   Explanation: There are two hashmaps that store the frequency of the characters in the window. The window is size p.length() and is used to compare the frequency of the characters within the window and to the 
   frequency of characters in the string p. If they match then the starting index st is added to the ans vector. At the end, ans is returned.
   Bug: Line 57 where mapW == mapP return false even though they have the same frequency of characters. Works for the first window but not the next windows. May need to revise how the string is traversed.
*/
