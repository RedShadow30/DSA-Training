/*  Day 30: Problem 872 - Leaf-Similar Tree
 *  Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
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
    void dfs(TreeNode* node, vector<int>& tree) {
        // if current node is null then return
        if(node == NULL) return;
        // go down left branch if exists
        dfs(node->left, tree);
        // check if leaf
        if(node->left == NULL && node->right == NULL)
            // add to tree if leaf
            tree.push_back(node->val);
        // go down right branch if exists
        dfs(node->right, tree);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // store all leaves into vectors
        vector<int> tree1, tree2;

        // do dfs search on both roots to get the leaves into their vectors
        dfs(root1, tree1);
        dfs(root2, tree2);

        // compare vectors and returning true/false based on similarity 
        return tree1 == tree2;   
    }
};

/*  Time Complexity: O(N)    Space Complexity: O(N) since we are storing nums in vectors. N would be number of leaf nodes.
    Explanation: We create a helper function called dfs to traverse the binary tree. We add the node's val to it's respective list IFF
    the node points to null on left and right. If the current node is null then we are done traversing that branch. The two
    vectors are compared at the end.
*/
