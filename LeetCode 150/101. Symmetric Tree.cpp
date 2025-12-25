class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }
private:
    bool dfs(TreeNode* left, TreeNode* right) {
        if (left == nullptr) return right == nullptr;
        if (right == nullptr) return left == nullptr;
        if (left->val != right->val) return false;

        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};
