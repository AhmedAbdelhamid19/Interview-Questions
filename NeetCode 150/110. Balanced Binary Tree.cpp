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
    bool isBalanced(TreeNode* root) {
        return dfs(root) < 1e8;
    }
    int dfs(TreeNode* root) {
        if(root == nullptr) return -1;

        int lDep = dfs(root->left) + 1, rDep = dfs(root->right) + 1;

        if(abs(lDep - rDep) > 1) return 1e8;a

        return max(lDep, rDep);
    }
};
