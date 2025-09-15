class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode* ans = head, *cur = head, *pre = nullptr;
        ListNode *prevSegEnd = nullptr, *nextSegStart, *curSegStart, *curSegEnd, *nextNode;
        bool first = true;
        while(true) {
            nextSegStart = cur;
            curSegStart = cur;
            bool flag = true;
            for(int i=0; i<k; i++) {
                if(nextSegStart == nullptr) {
                    flag = false;
                    break;
                }
                if(i == k - 1) curSegEnd = nextSegStart;
                nextSegStart = nextSegStart->next;
            }
            if(pre == nullptr) ans = curSegEnd;
            if(!flag) break;

            while(cur != nextSegStart) {
                nextNode = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nextNode;
            }

            curSegStart->next = nextSegStart;
            if(prevSegEnd != nullptr)
                prevSegEnd->next = curSegEnd;
            prevSegEnd = curSegStart;
        }
        return ans;
    }
};
