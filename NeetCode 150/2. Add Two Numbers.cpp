class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur = new ListNode();
        ListNode* ans = cur;
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

            cur->val = remain;
            if(l1 != nullptr || l2 != nullptr || sum) {
                cur->next = new ListNode();
                cur = cur->next;
            }
        }
        return ans;
    }
};
