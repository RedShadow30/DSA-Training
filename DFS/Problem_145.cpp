/* Day 41: Problem 145 - Binary Tree Post-Order Traversal
 * Given the root of a binary tree, return the postorder traversal of its nodes' values.
 * Time taken: 9m 16s
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
    void dfs(TreeNode* root, stack<int>& res) {
        // base case - no child nodes or visited (marked with -101)
        if(root == nullptr) return;
        
        // add current node
        res.push(root->val);
        // visit right subtree
        dfs(root->right, res);
        // visit left subtree
        dfs(root->left, res);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        stack<int> result;
        dfs(root, result);

        vector<int> ans;
       while(!result.empty()) {
            ans.push_back(result.top());
            result.pop();
        }

        return ans;
    }
};

/*  Time Complexity: O(N) where all N nodes are traversed. Space complexity: O(N) since all N nodes are stored in ans.
    Explanation: Post-order traversal so we need to add current node, right subtree, then left subtree. Our base case is to
    return if we visit a node with no child nodes. We can leverage the stack data structure to be able to mimic the order of
    which the nodes are visited. Most recently visited will stay at the front while the ones visited at the beginning at towards
    the end. This is converted into a vector and returned.
*/