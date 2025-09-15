vaclass Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n < 2)return n == 0 ? nullptr : lists[0];

        vector<ListNode*> res;
        if(n & 1) res.push_back(lists[0]);

        for(int i1=n&1, i2=1+(n&1); i1<n && i2<n; i1+=2, i2+=2) {
            res.push_back(merge(lists[i1], lists[i2]));
        }
        return mergeKLists(res);
    }

    ListNode* merge(ListNode* l, ListNode* r) {
        ListNode* result = nullptr, *ptr = nullptr;

        while(l != nullptr || r != nullptr) {
            ListNode* cur;
            if(l == nullptr) {
                cur = new ListNode(r->val), r = r->next;
            } else if(r == nullptr) {
                cur = new ListNode(l->val), l = l->next;
            } else if(l->val <= r->val) {
                cur = new ListNode(l->val), l = l->next;
            } else {
                cur = new ListNode(r->val), r = r->next;
            }

            if(ptr == nullptr) {
                ptr = cur;
                result = ptr;
            } else {
                ptr->next = cur;
                ptr = cur;
            }
        }
        return result;
    }
};
