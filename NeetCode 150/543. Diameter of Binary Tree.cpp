class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
    int dfs(TreeNode* node, int len) {
        int left = node->left == nullptr ? 0 : dfs(node->left, 1);
        int right = node->right == nullptr ? 0 : dfs(node->right, 1);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
};
