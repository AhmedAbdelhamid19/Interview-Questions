struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* ptr = head;
        while(ptr != nullptr) {
            v.push_back(ptr);
            ptr = ptr->next;
        }
        int l=0, r=v.size() - 1;
        while(l <= r) {
            if(l == r - 1 || l == r) {
                v[r]->next = nullptr;
                return;
            }
            v[r]->next = v[l]->next;
            v[l]->next = v[r];
            l++, r--;
        }
    }
};
