class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* cur = nullptr;
        vis.resize(105, false);
        nodes.resize(105);

        dfs(node, cur);
        return cur;
    }
private:
    vector<bool> vis;
    vector<Node*> nodes;
    void dfs(Node* &node, Node* &cur) {
        if(node == nullptr) return;

        vis[node->val] = true;
        cur = new Node(node->val);
        nodes[cur->val] = cur;

        for(int i=0; i<node->neighbors.size(); i++) {
            if(vis[node->neighbors[i]->val]) {
                cur->neighbors.push_back(nodes[node->neighbors[i]->val]);
                continue;
            }

            Node* child = nullptr;
            dfs(node->neighbors[i], child);
            cur->neighbors.push_back(child);
        }

    }
};
