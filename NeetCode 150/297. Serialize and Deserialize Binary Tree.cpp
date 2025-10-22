class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return dfs1(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return dfs2(data, idx);
    }
private:
    string dfs1(TreeNode *node) {
        if(node == nullptr) {
            return "[]";
        }
        string cur = "[" + to_string(node->val);
        cur += dfs1(node->left);
        cur += dfs1(node->right);
        cur += "]";

        return cur;
    }
    TreeNode* dfs2(string &s, int &i) {
        if(i >= s.size()) return nullptr;

        while(s[i] == ']') i++;
        if(s[i + 1] == ']') {
            i += 2;
            return nullptr;
        }

        i++;
        string curNum = "";
        if(s[i] == '-') curNum += s[i++];
        while(i < s.size() && s[i] != ']' && s[i] != '[') {
            curNum += s[i++];
        }
        TreeNode *cur = new TreeNode(stoi(curNum));
        cur->left = dfs2(s, i);
        cur->right = dfs2(s, i);

        return cur;
    }
};
