/*  Day 21: Problem 543 - Diameter of Binary Tree
    Given the root of a binary tree, return the length of the diameter of the tree.
    The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
    The length of a path between two nodes is represented by the number of edges between them.
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
    int maxL = 0;
    int dfs(TreeNode* root) {
        if(!root) return 0;
        // travel through all of the left nodes and get max length
        int left = dfs(root->left);
        // travel through all the right nodes and get max length
        int right = dfs(root->right);
        // update max to bigger branch length
        maxL = max(maxL, left+right);
        // return max length of left or right branch plus 1 to include root
        return (1 + max(left, right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxL;
    }
};

/*  Time Complexity: O(N) since we are moving to all nodes.    Space Complexity: O(1) since storing in int variables.
    Explanation: We find each branches' length by traversing to til leaf node. When moving back the left branch, visit right node if exists
    and take the max between the current max and current sum of left node to right node branch length. Recursively call right nodes to update the 
    length of branches and update max. Finally return max of left to right length or right to left length +1 to include root.
*/