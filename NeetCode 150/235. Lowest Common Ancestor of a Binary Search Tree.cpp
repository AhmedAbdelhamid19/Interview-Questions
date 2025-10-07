class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p->val, q->val);
    }
private:
    TreeNode* dfs(TreeNode* cur, int p, int q) {
        bool lp = exist(cur->left, p), rp = exist(cur->right, p);
        bool lq = exist(cur->left, q), rq = exist(cur->right, q);

        if(lp && lq) return dfs(cur->left, p, q);
        else if(rp && rq) return dfs(cur->right, p, q);

        return cur;
    }
    bool exist(TreeNode *cur, int val) {
        if(cur == nullptr) return false;
        if(cur->val == val) return true;

        return exist(cur->left, val) | exist(cur->right, val);
    }
};

/* 
// solution using pointers
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ListNode *pPtr = new ListNode(root->val);
        ListNode *qPtr = new ListNode(root->val);
        pPtr->treeNode = qPtr->treeNode = root;
        dfs(root, p->val, q->val, 0, pPtr, qPtr);

        while(pPtr->dep > qPtr->dep) {
            pPtr = pPtr->pre;
        }
        while(qPtr->dep > pPtr->dep) {
            qPtr = qPtr->pre;
        }

        while(qPtr->val != pPtr->val) {
            qPtr = qPtr->pre;
            pPtr = pPtr->pre;
        }

        return pPtr->treeNode;
    }
private:
    struct ListNode {
        int val, dep;
        ListNode *pre, *left, *right;
        TreeNode* treeNode;
        ListNode(int x): val(x), dep(0), pre(nullptr), left(nullptr), right(nullptr) {};
    };
    void dfs(TreeNode *&cur, int p, int q, int dep, ListNode *&pPtr, ListNode *&qPtr) {
        if(cur == nullptr) return;

        if(cur->left != nullptr) {
            if(pPtr->val != p) {
                pPtr->left = new ListNode(cur->left->val);
                pPtr->left->pre = pPtr;
                pPtr->left->dep = dep + 1;
                pPtr->left->treeNode = cur->left;
                pPtr = pPtr->left;
            }
            if(qPtr->val != q) {
                qPtr->left = new ListNode(cur->left->val);
                qPtr->left->pre = qPtr;
                qPtr->left->dep = dep + 1;
                qPtr->left->treeNode = cur->left;
                qPtr = qPtr->left;
            }
            dfs(cur->left, p, q, dep + 1, pPtr, qPtr);
            if(pPtr->val != p) pPtr = pPtr->pre;
            if(qPtr->val != q) qPtr = qPtr->pre;
        }
        if(cur->right != nullptr) {
            if(pPtr->val != p) {
                pPtr->right = new ListNode(cur->right->val);
                pPtr->right->pre = pPtr;
                pPtr->right->dep = dep + 1;
                pPtr->right->treeNode = cur->right;
                pPtr = pPtr->right;
            }
            if(qPtr->val != q) {
                qPtr->right = new ListNode(cur->right->val);
                qPtr->right->pre = qPtr;
                qPtr->right->dep = dep + 1;
                qPtr->right->treeNode = cur->right;
                qPtr = qPtr->right;
            }
            dfs(cur->right, p, q, dep + 1, pPtr, qPtr);
            if(pPtr->val != p) pPtr = pPtr->pre;
            if(qPtr->val != q) qPtr = qPtr->pre;
        }
    }
};
*/
