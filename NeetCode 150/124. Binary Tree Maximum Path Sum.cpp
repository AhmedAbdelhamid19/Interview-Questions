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
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    int ans = INT_MIN;
    int dfs(TreeNode* node) {
        if(node == nullptr) return 0;
        int cur = node->val;
        int mxL = dfs(node->left);
        int mxR = dfs(node->right);
        
        ans = max({ans, cur, cur + mxL, cur + mxR, cur + mxL + mxR});
        return max({cur, cur + mxL, cur + mxR});
    }
};
