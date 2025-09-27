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
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        indexes.resize(6005);
        int n = inorder.size();
        for(int i=0; i<n; i++) {
            indexes[inorder[i] + 3000] = i;
        }

        return constructSubTree(preorder, inorder, 0, n-1, 0, n-1);
    }
    TreeNode* constructSubTree(vector<int>&pre, vector<int>& in, int preL, int preR, int inL, int inR) {
        int rootVal = pre[preL];
        TreeNode* curRoot = new TreeNode(rootVal);

        int rootIdx = indexOf(rootVal);
        int cntL = rootIdx - inL, cntR = inR - rootIdx;

        TreeNode* leftSubTree = cntL ? constructSubTree(pre, in, preL + 1, preR + cntL, inL, rootIdx - 1) : nullptr;
        TreeNode* rightSubTree = cntR ? constructSubTree(pre, in, preL + cntL + 1, preR, rootIdx + 1, inR) : nullptr;

        curRoot->left = leftSubTree;
        curRoot->right = rightSubTree;

        return curRoot;
    }
private:
    vector<int> indexes;
    int indexOf(int val) {
        return indexes[val + 3000];
    }
};
