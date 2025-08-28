class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans;
        ListNode* cur;
        bool assigned = false;

        int sum = 0;
        while(l1 != nullptr || l2 != nullptr || sum) {
            int cur1 = 0, cur2 = 0;
            if(l1 != nullptr) {
                cur1 = l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                cur2 = l2->val;
                l2 = l2->next;
            }
            sum += cur1 + cur2;
            int remain = sum % 10;
            sum /= 10;

            if(!assigned) {
                assigned = true;
                if(l1 != nullptr || l2 != nullptr || sum) {
                    cur = ans = new ListNode(remain);
                    cur->next = new ListNode();
                    cur = cur->next;
                } else {
                    cur = ans = new ListNode(remain);
                }
            } else {
                if(l1 != nullptr || l2 != nullptr || sum) {
                    cur->val = remain;
                    cur->next = new ListNode();
                    cur = cur->next;
                } else {
                    cur->val = remain;
                }
            }
        }
        return ans;
    }
};
