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
