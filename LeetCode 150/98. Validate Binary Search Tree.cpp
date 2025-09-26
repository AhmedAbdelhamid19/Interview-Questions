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
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
    bool dfs(TreeNode* node, long long l, long long r) {
        if(node->val < l || node->val > r) {
            return false;
        }
        
        bool res = true;
        if(node->left != nullptr) {
            long long newL = l, newR = (long long) node->val - 1;
            res &= dfs(node->left, newL, newR);
        }
        if(node->right != nullptr) {
            long long newL = (long long) node->val + 1, newR = r;
            res &= dfs(node->right, newL, newR);
        }
        
        return res;
    }
};
