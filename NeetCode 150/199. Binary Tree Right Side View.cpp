class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        level.resize(105, -200);

        int depth = dfs(root, 0);
        vector<int> ans(depth);
        for(int i=0; i<depth; i++) {
            ans[i] = level[i];
        }
        return ans;
    }
private:
    vector<int> level;
    int dfs(TreeNode* node, int depth) {
        if(node == nullptr) return depth;

        if(level[depth] == -200) {
            level[depth] = node->val;
        }
        return max(dfs(node->right, depth + 1), dfs(node->left, depth + 1));
    }
};
