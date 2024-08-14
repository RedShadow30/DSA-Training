/* Day 9 - Problem 88 - Merge Sorted Array
   You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
   Merge nums1 and nums2 into a single array sorted in non-decreasing order.
   The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m 
   elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

class Solution {
public:
    // Two Pointers Approach
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // nums2 empty then return bc no changes necessary
        if(n == 0) return;

        // Pointer 1: Fill up empty spots in nums1. Start pointer at end of nums1.
        int currIndex = nums1.size()-1;

        // Add larger number to the end of nums1 and move pointer1 left
        while(n > 0 && m > 0) {
            // add nums2 last # if it is >= last # in nums1
            if(nums2[n-1] >= nums1[m-1]) {
                nums1[currIndex] = nums2[n-1];
                n--;
            }
            // add nums1 last # to end if < last # in nums2
            else {
                nums1[currIndex] = nums1[m-1];
                m--;
            }
            // shift down nums1 to store in previous spot
            currIndex--;
        }

        // make sure no stranded nums in nums2
        while(n > 0) {
            nums1[currIndex] = nums2[n-1];
            n--;
            currIndex--;
        }
    }
};

/* Time Complexity: O(N) because we are moving through the entirety of nums1.   Space Complexity: O(N) because nothing is stored except the variable currIndex.
   We are filling up nums1 by comparing the ends of each array. The larger number is added to the end of nums1 and a pointer is used to keep track of the index at which we need to add the number. The indices of
   the array that had it's number added also has it's index position decreased by 1 to compare the suceeding largest number. If there are remaining numbers that need to be added from nums2 then they are added 
   but this is only true if n > 0. 
*/
