class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = nullptr;
        ListNode* nxt = head;
        ListNode* cur = head;
        while(n--) nxt = nxt->next;

        while(nxt != nullptr) {
            if(pre == nullptr) {
                pre = cur;
            } else {
                pre = pre->next;
            }
            nxt = nxt->next;
            cur = cur->next;
        }
        if(pre == nullptr) return cur->next;
        pre->next = cur->next;
        return head;
    }
};
