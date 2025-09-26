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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) {
            return true;
        }
        if(p == nullptr || q == nullptr) {
            return false;
        }
        if(p->val != q->val)
            return false;
        if((p->left == nullptr && q->left != nullptr) || (q->left == nullptr && p->left != nullptr))
            return false;
        if((p->right == nullptr && q->right != nullptr) || (q->right == nullptr && p->right != nullptr))
            return false;
        return (p->left == nullptr || isSameTree(p->left, q->left)) &&
               (p->right == nullptr || isSameTree(p->right, q->right));
    }
};
