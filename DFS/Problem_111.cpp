/*  Day 36: Problem 111 - Minimum Depth of Binary Tree
 *  Given a binary tree, find its minimum depth.
 *  The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode* root) {
        // base case 1 - no nodes exist
        if(root == nullptr) return 0;
        // base case 2 - node has no children then return 1
        else if(root->left == nullptr && root->right == nullptr) return 1;
        // both branches exist then traverse through both of them and store the min node depth
        else if(root->left && root->right) return 1 + min(minDepth(root->left), minDepth(root->right));
        // if left branch exists only then traverse until no children condition met
        else if(root->left) return 1 + minDepth(root->left);
        // if right branch exists only then traverse until no children condition met
        else return 1 + minDepth(root->right);
    }
};

/*  Time Complexity: O(N) since we would need to traverse all the nodes if one branch exists with N nodes. That branch is the minDepth.
    Space Complexity: O(N) since this is a recursive function and it will store the N nodes in the stack space.
    Explanation: The way the tree is traversed is it checks if the current node is empty if so then 0 is returned. The next cases are only
    checked the previous cases were not met. The goal is to continue down a branch until we hit a leaf node. In that case we return 1
    back up the stack and find the min of the branches (if branches existed).
*/