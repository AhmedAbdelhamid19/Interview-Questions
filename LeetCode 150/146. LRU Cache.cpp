class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        valOf.resize(1e4 + 5, -1);
    }

    int get(int key) {
        if(valOf[key] == -1) return -1;

        shift(key);
        return valOf[key];
    }

    void put(int key, int value) {
        if(valOf[key] != -1) {
            shift(key);
            valOf[key] = value;
        } else {
            if(mp.size() == capacity) {
                mp.erase(head->key);
                valOf[head->key] = -1;
                head = head->nxt;

                mp.insert({key, add(key)});
                valOf[key] = value;
            } else {
                mp.insert({key, add(key)});
                valOf[key] = value;
            }
        }
    }

    int capacity;
    vector<int> valOf;
    class Node {
    public:
        int key;
        Node *nxt, *pre;
        Node(int key) {
            this->key = key;
            nxt = nullptr;
            pre = nullptr;
        }
    };
    unordered_map<int,Node*> mp;
    Node *leaf = nullptr, *head = nullptr;
    
    void shift(int key) {
        if(mp.size() == 1) return;

        Node* node = mp[key];
        if(node == head) {
            head = node->nxt;
        }
        if(node == leaf) {
            return;
        }
        if(node->pre != nullptr)
            node->pre->nxt = node->nxt;
        if(node->nxt != nullptr) 
            node->nxt->pre = node->pre;
        node->nxt = nullptr;
        node->pre = leaf;
        leaf->nxt = node;
        leaf = node;
    }
    Node* add(int key) {
        Node *cur = new Node(key);
        if(head == nullptr) {
            head = leaf = cur;
        } else {
            cur->pre = leaf;
            leaf->nxt = cur;
            leaf = cur;
        }

        return cur;
    }
};
