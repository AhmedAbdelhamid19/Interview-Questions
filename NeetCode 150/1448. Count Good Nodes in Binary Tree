class Solution {
public:
    int goodNodes(TreeNode* root) {
        return recursion(root, root->val);
    }
private:
    int recursion(TreeNode* node, int mx) {
        int ans = (mx <= node->val);
        if(node->left != nullptr)
            ans += recursion(node->left, max(mx, node->left->val));
        if(node->right != nullptr)
            ans += recursion(node->right, max(mx, node->right->val));
        return ans;
    }
};
