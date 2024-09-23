/*  Day 46: Problem 700 - Search in a Binary Search Tree
 *  You are given the root of a binary search tree (BST) and an integer val.
 *  Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, 
 *  return null.
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
    TreeNode* searchBST(TreeNode* root, int val) {
        // base case - leaf node then return
        if(!root) return nullptr;

        // val matches then return current node
        if(root->val == val) return root;

        // go to left tree if val is smaller
        if(root->val < val) {
            return searchBST(root->right, val);
        }
        else {
            return searchBST(root->left, val);
        }
    }
};

/*  Time Complexity: O(N) since we may need to traverse the whole tree with N nodes.    Space Complexity: O(N) since we may need to store
    all those N nodes' numbers.
    Explanation: We are searching a binary tree, so we know that the tree will be constructed where the right node's value will be larger than the
    left node's value. Knowing this, we can compare the current node value to the target value to travel down the correct subtree. If the current
    node value is smaller than the target then we know that we are looking for a larger value so we would travel down the right subtree. We continue
    until we reach a leaf node, at which point, we know that the target value does not exist. Therefore, in that base case, we return nullptr.
*/