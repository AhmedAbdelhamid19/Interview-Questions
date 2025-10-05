class Trie {
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* cur = root;
        for(auto &it: word) {
            if(cur->nxt[it - 'a'] == nullptr) {
                cur->nxt[it - 'a'] = new Node();
            }
            cur = cur->nxt[it - 'a'];
        }
        cur->end = true;
    }

    bool search(string word) {
        Node* cur = root;
        for(auto &it: word) {
            if(cur->nxt[it - 'a'] == nullptr) {
                return false;
            }
            cur = cur->nxt[it - 'a'];
        }
        return cur->end;
    }

    bool startsWith(string prefix) {
        Node* cur = root;
        for(auto &it: prefix) {
            if(cur->nxt[it - 'a'] == nullptr) {
                return false;
            }
            cur = cur->nxt[it - 'a'];
        }
        return true;
    }
private:
    class Node {
    public:
        Node() {
            nxt.resize(26, nullptr);
            end = false;
        }
        vector<Node*> nxt;
        bool end;
    };
    Node* root;
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
