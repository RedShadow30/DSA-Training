/*  Day 39: Problem 94 - Binary Tree Inorder Traversal
 *  Given the root of a binary tree, return the inorder traversal of its nodes' values.
 *  Time Taken:  6m 46s
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
    void dfs(TreeNode* root, vector<int>& res) {
        // base case - no child nodes then return
        if(root == nullptr) {
            return;
        }

        // visit left node
        dfs(root->left, res);
        // add current node to res
        res.push_back(root->val);
        // visit right node
        dfs(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // create result to store nums
        vector<int> result;
        // call recursive func
        dfs(root, result);
        // return result
        return result;
    }
};

/*  Time Complexity: O(N) where all N nodes are visited. Space Complexity: O(N) where N nodes' values
    are stored in the vector result.
    Explanation: We use the Depth-First Search approach where we visit all left nodes until we hit a 
    leaf node. Once we hit a leaf node then we add that node's val to the list and backtrack to predecessor.
    We add the predecessor's value and then navigate to the right node. This is inorder traversal (left, current, right).
    We add each number to result and since it is passed by reference we can return it in the inorderTraversal() function.
*/