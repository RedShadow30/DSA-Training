/*  Day 19: Problem 104 - Maximum Depth of a Binary Tree
    Given the root of a binary tree, return its maximum depth.
    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/**
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
    void dfs(TreeNode* currNode, int count, int& maxCount) {
        // increase count since node visited
        count++;
        // base case is leaf end reached
        if(currNode->left == nullptr && currNode->right == nullptr) {
            return;
        }
        // Update maxCount if needed
        if(count > maxCount) {
            maxCount = count;
        }
        // look at left if exists, recursive call
        if(currNode->left != nullptr) {
            dfs(currNode->left, count, maxCount);
        }
        // look at right if exists, recurisve call
        if(currNode->right != nullptr) {
            dfs(currNode->right, count, maxCount);
        }

    }
    int maxDepth(TreeNode* root) {
        // count starts at 1
        int count = (root != nullptr)? 1: 0;
        int maxCount = count;

        if(count) 
            dfs(root, count, maxCount);

        return maxCount;
    }
};

// BETTER SOLUTION is below
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // check if node is empty, base case
        if(!root) return 0;
        // visits all left nodes, updating length of left branch
        int left = 1 + maxDepth(root->left);
        // visits all right nodes, updating length of right branch
        int right = 1 + maxDepth(root->right);
        // return bigger of left and right branch
        return max(left,right);
    }
};

/*  Time Complexity: O(N) since all nodes must be visited to calculate greatest depth.    Space Complexity: O(1) since we are storing in int variables.
    Explanation: We are using depth first search to find the greatest length in the tree. The maxDepth() creates a count variable to store varying
    length of the branches, maxCount is used to store the greatest length found so far. If a node exists in the tree then the recursive function, dfs()
    is called. dfs() visits each left node first by recursively calling the currNode updated to the left node (if exists). Once it reaches a leaf (base case),
    it returns to the previous node until it can then move to a right node to see that branch's length. For each node visited, the count increases and is
    compared to the maxCount to see if it needs to be updated.
*/
