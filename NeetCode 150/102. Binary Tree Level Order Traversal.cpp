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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root != nullptr)
            dfs(root, 1);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void dfs(TreeNode* node, int level) {
        if(ans.size() < level) ans.push_back({node->val});
        else {
            ans[level - 1].push_back(node->val);
        }
        if(node->left != nullptr)
            dfs(node->left, level + 1);
        if(node->right != nullptr)
            dfs(node->right, level + 1);
    }
};
