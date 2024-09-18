/* Day 40: Problem 108 - Convert Sorted Array to Binary Tree
 * Given an integer array nums where the elements are sorted in ascending order, convert it to a 
 * height-balanced binary search tree.
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* construct(int left, int right, vector<int>& arr) {
        // base case - no elements in the array then right becomes -1
        if(left > right) return nullptr;

        // calculate midpoint
        int mid = left + ((right - left) / 2);

        // create a new Tree with val at arr[mid]
        TreeNode* root = new TreeNode(arr[mid]);

        // construct left and right subtrees with updated ranges
        root->left = construct(left, mid-1, arr);
        root->right = construct(mid+1, right, arr);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // call recursivev func to construct binary tree
        return construct(0, nums.size()-1, nums);
    }
};

/*  Time Complexity: O(N) since we traverse all N numbers in nums. O(N) since
    we have to remember all N numbers in nums.
    Explanation: To construct the binary tree we need to find the number at the middle
    each time. First, we set our base case to check if our left and right pointer overlapped.
    If it did then we can stop. If not then we find the midpoint of the two and store that
    index in a variable called mid. Using mid, we can create a new sub-tree that stems from a
    node with the value at arr[mid]. The left and right subtree can be created with updated 
    ranges for left and right. At the end, root is returned.
*/