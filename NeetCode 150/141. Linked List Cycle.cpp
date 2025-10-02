/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool> mp;
        bool ans = false;
        while(head != nullptr) {
            if(mp.count(head)) {
                ans = true;
                break;
            }
            mp[head] = true;
            head = head->next;
        }
        return ans;
    }
};
