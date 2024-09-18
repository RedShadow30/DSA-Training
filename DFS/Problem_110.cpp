/* Day 38: Problem 110 - Balanced Binary Tree
 * Given a binary tree, determine if it is height-balanced.
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
    int count(TreeNode* root, bool& res) {
        if(root == nullptr) return 0;

        // recursively count the height of left and right subtree till end
        int l = count(root->left, res);
        int r = count(root->right, res);

        // check if the current subtree has a difference in height > 1
        if(abs(l-r) > 1) res = false;

        // Return the height including the current node
        return (max(l+1, r+1));

    }

    bool isBalanced(TreeNode* root) {
        bool result = true;
        count(root, result);
        return result;
    }
};

/*  Time Complexity: O(N) because we are traversing the tree once and through N nodes. Space Complexity: O(N) since this is a recursive function
    that could store N nodes in the stack space.
    Explanation: We use the postorder tree traversal to travel through the tree and count the height at each node to compare the left and right subtree first.
    Then the difference is calculated at the current node where > 1 means false is stored in the variable res passed by reference. The res 
    variable will never be updated to true. 
*/