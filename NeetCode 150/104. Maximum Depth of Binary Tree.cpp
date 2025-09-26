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
    int maxDepth(TreeNode* root) {
        return root == nullptr ? 0 : dfs(root, 1);
    }
    int dfs(TreeNode* node, int curDep) {
        int ans = curDep;
        if(node->left != nullptr) 
            ans = max(ans, dfs(node->left, curDep + 1));
        if(node->right != nullptr) {
            ans = max(ans, dfs(node->right, curDep + 1));
        }
        return ans;
    }
};
