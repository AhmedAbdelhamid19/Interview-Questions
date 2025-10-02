class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        map<Node*, int> mp1;
        map<int, Node*> mp2;
        Node* ans = new Node(head->val), *originalPtr = head, *clonedPtr = ans;
        int idx = 0;

        while(originalPtr->next != nullptr) {
            mp1[originalPtr] = idx;
            mp2[idx] = clonedPtr;

            clonedPtr->next = new Node(originalPtr->next->val);
            originalPtr = originalPtr->next;
            clonedPtr = clonedPtr->next;
            idx++;
        }
        mp1[originalPtr] = idx;
        mp2[idx] = clonedPtr;

        clonedPtr = ans, originalPtr = head;
        
        while(originalPtr != nullptr) {
            if(originalPtr->random == nullptr) {
                clonedPtr->random = nullptr;
            } else {
                clonedPtr->random = mp2[mp1[originalPtr->random]];
            }
            originalPtr = originalPtr->next;
            clonedPtr = clonedPtr->next;   
        }

        return ans;
    }
};
