class WordDictionary {
public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
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
        return dfs(root, word, 0);
    }
private:
    class Node {
    public:
        Node() {
            nxt.resize(26, nullptr);
            end = false;
        }
        bool end;
        vector<Node*> nxt;
    };
    Node* root;
    bool dfs(Node *node, string& word, int i) {
        if(i == word.size()) return node->end;

        if(word[i] == '.') {
            for(auto ptr: node->nxt) {
                if(ptr != nullptr && dfs(ptr, word, i + 1))
                    return true;
            }
        } else {
            Node* nxt = node->nxt[word[i] - 'a'];
            if(nxt != nullptr && dfs(nxt, word, i + 1))
                return true;
        }
        return false;
    }
};
