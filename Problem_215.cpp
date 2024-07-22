/* Day 1
  Problem 215: Kth Largest Element in an Array
  Given an integer array nums and an integer k, return the kth largest element in the array.
  Note that it is the kth largest element in the sorted order, not the kth distinct element.
  Can you solve it without sorting? Yes :)
*/

class Solution {
public:
  // Use a MIN heap so that it will only comprise of the k largest items. Return the head which is the smallest of the k items.
  int findKthLargestElement(vector<int>& nums, int k) {
    // Create a Priority Queue (default is Max Heap)
    priority_queue<int> pq;
    
    // Multiply -1 and then push to heap. So that originally smaller positive #s are placed at the top. -1 > -2 so -1 is head.
    for(int i = 0; i < nums.size(); ++i) {
      // Push to heap if < k elements in heap
      if(pq.size() < k) {
          pq.push(-1 * nums[i])
      }
      // Push to heap and then pop head to only keep k largest elements
      else {
        pq.push(-1 * nums[i]);
        pq.pop();
      }
    }
    
    // Return the head of the heap after conversion to original number
    return (-1 * pq.top());
  }
};

// Time complexity is O(N log K) and space complexity O(k) where k is the kth largest number.
// Haep has log-time so since we have K items it becomes log k. We are also traversing through the nums with size N so it becomes N log K.
// An alternate approach would be to use QuickSelect since it has a time complexity of O(N) and space complexity of O(1). However, the worst case is O(N^2) so this approach is generally not used.

/*
  Explanation
  Use of MIN heap to find the k elements that are the largest in the nums array. The smallest of the k elements is the head of the heap since Min heap has the smallest as the head, so we return the head.
  Priority Queue is used for Max Heap so to use it as a Min heap you need to multiply -1 to the elements you push to the heap.
*/
