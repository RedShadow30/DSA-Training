/*  Day 37: Problem 257 - Binary Tree Paths
 *  Given the root of a binary tree, return all root-to-leaf paths in any order.
 *  A leaf is a node with no children.
 * 
 *  Definition for a binary tree node.
 *  struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *  };
 */
class Solution {
public:
    // Need to receive result by reference so that updated in OG function as well
    void dfs(TreeNode* node, string s, vector<string>& res) {
        // base case is node is empty
        if(!node) return;

        // add current node value to path
        s += to_string(node->val);

        // if leaf node then add s to result 
        if(!node->left && !node->right)
            res.push_back(s);
        // else travel into the branches with updated string s
        else {
            dfs(node->left, s + "->", res);
            dfs(node->right, s + "->", res);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        // call recursive dfs function
        dfs(root, "", result);
        return result;
    }
};

/*  Time Complexity: O(N) since it is traversing all N nodes of the tree.    Space Complexity: O(N) since we are storing the N nodes' values
    in the vector result.
    Explanation: The dfs recursive function will traverse the branches of the tree and updating the string s. If it reaches a leaf node,
    then the current string s will be pushed into the result vector. Else, it will traverse down the existing branches. 
*/