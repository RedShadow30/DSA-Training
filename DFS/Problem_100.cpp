/*  Day 35: Problem 100 - Same Tree
 *  Given the roots of two binary trees p and q, write a function to check if they are the same or not.
 *  Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case - one of nodes are empty then make sure both match in structure
        if(p == nullptr || q == nullptr) return p == q;

        // nodes must exist, so check value equality and both branches
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/*  Time Complexity: O(N) because we have to traverse the bigger tree with N nodes.      Space Complexity: O(N) since recursive and we
    are storing node info in the stack space.
    Explanation: We need to check the structure and values of the tree. Considering the empty tree, our base case is to check whether
    one of the nodes are empty at any point. If either of them are empty then we check to make sure the trees' structure is the same.
    Return true / false depending on the structure. Next, we know that the nodes must exist so we check the values of the nodes and the
    branches of left and right. Return true / false depending on whether the current nodes' values are the same or not and whether the
    following branches returned true or false. 
*/