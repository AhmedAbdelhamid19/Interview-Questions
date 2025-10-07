class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k, 0);
        return ans;
    }
private:
    int ans;
    int dfs(TreeNode *node, int k, int pre) {
        int curIdx = 1 + (node->left == nullptr ? pre : dfs(node->left, k, pre));
        if(curIdx == k) ans = node->val;

        return node->right == nullptr ? curIdx : dfs(node->right, k, curIdx);
    }
};
