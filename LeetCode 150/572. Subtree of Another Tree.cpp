class Solution {
public:
    bool catched = false;
    vector<int> rootNodes,subRootNodes;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root, rootNodes), dfs(subRoot, subRootNodes);
        
        bool ans = false;
        int l=0, r=subRootNodes.size() - 1;
        while(r < rootNodes.size()) {
            bool test = true;
            for(int i=l, j=0; i<=r; i++,j++) {
                if(rootNodes[i] != subRootNodes[j]) {
                    test = false;
                    break;
                }
            }
            if(test) return true;
            l++, r++;
        }
    }

    void dfs(TreeNode* node, vector<int>& v) {
        if(node == nullptr) {
            v.push_back(1e5);
            return;
        }
        v.push_back(node->val);
        dfs(node->left, v), dfs(node->right, v);
        v.push_back(node->val);
    }
};
