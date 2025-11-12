class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        for(auto it: tickets) {
            mp[it[0]].insert(it[1]);
        }

        Node *head = new Node("JFK");
        dfs("JFK",head);
        while(head != nullptr) {
            ans.push_back(head->val);
            head = head->nxt;
        }
        return ans;
    }
private:
    map<string, multiset<string>> mp;
    class Node {
    public:
        string val;
        Node *nxt, *pre;
        Node(string val) {
            this->val = val;
            this->nxt = nullptr;
            this->pre = nullptr;
        }
        void addNext(Node *node) {
            Node *oldNxt = nxt;

            this->nxt = node;
            node->pre = this;
            if(oldNxt != nullptr) {
                node->nxt = oldNxt;
                oldNxt->pre = node;
            }
        }
    };
    void dfs(string cur, Node *curNode) {
        while(mp[cur].size()) {
            string nxt = *mp[cur].begin();
            mp[cur].erase(mp[cur].find(nxt));
            Node *nxtNode = new Node(nxt);
            curNode->addNext(nxtNode);
            dfs(nxt, nxtNode);
        }
    }
};
