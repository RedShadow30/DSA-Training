/*  Day 42: Problem 144 - Binary Tree Preorder Traversal
 *  Given the root of a binary tree, return the preorder traversal of its nodes' values.
 *  Time taken: 6m 14s
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
    void dfs(TreeNode* root, vector<int>& res) {
        // base case - no child nodes then return
        if(root == nullptr) return;

        // add current node value to res
        res.push_back(root->val);

        // traverse left subtree
        dfs(root->left, res);

        // traverse right subtree
        dfs(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};

/*  Time Complexity: O(N) were all N nodes of the tree are visited.    Space Complexity: O(N) since all N nodes of the tree
    are stored in the vector of ints.
    Explanation: For preorder traversal, we want to store the current node. Then we keep going down the left subtree to see if
    there are more nodes to visit. If all left nodes are visited then we go to check the right subtree. The order of visiting nodes
    is current -> left -> right. The base case is to keep visiting until we reach a leaf node, in which case, we return to predecessor.
    The ans vector is passed by reference to dfs() store all node values, then this vector is returned by preorderTraversal() after all recursive calls.
*/