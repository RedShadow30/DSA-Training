/* Day 34: Problem 112 - Path Sum
 * Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
 * A leaf is a node with no children.
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
    void dfs(TreeNode* node, int targetSum, int& currSum) {
        // base case: leaf node and sum not target
        if(node==nullptr) return; 
        
        // update sum
        currSum += node->val;
        cout << "sum: " << currSum << endl;

        // traverse to the next node
        dfs(node->left, targetSum, currSum);

        // update sum before moving to next branch
        currSum -= node->val;
        dfs(node->right, targetSum, currSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        // base case is no node
        if(root==nullptr) return false;
        // check if leaf node, if yes then return true if target sum reached
        if(root->left == nullptr && root->right == nullptr) return root->val == targetSum;
        // recursively call with updated sum checking both existing branch
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

/*  Time Complexity: O(N) since we visit each of the N nodes.   Space Complexity: O(1) since we are updating given variables.
    Explanation: We use DFS (depth first search) to go through each branch to reach a leaf node. Once we reach a leaf, we compare
    the leaf's value to the target sum (their difference should be 0 meaning that we have found our target sum). This return true/false
    the base case is for nodes that do not exist (nullptr). The last thing returned is where we travel down the left and right branch with
    the updated target sum. 
*/