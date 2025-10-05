
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size(), m = board[0].size();
        vis.resize(n, vector<bool>(m, false));

        root = new Node();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(root->nxt[board[i][j] - 'a'] == nullptr) {
                    root->nxt[board[i][j] - 'a'] = new Node();
                }
                backtrack(i, j, root->nxt[board[i][j] - 'a'], board, 1);
            }
        }

        vector<string> ans;
        for(auto &word: words) {
            if(exit(word)) ans.push_back(word);
        }
        return ans;
    }
private:
    int n, m;
    vector<vector<bool>> vis;
    vector<int> dx {+1, -1, +0, +0};
    vector<int> dy {+0, +0, +1, -1};
    class Node {
    public:
        Node() {
            nxt.resize(30, nullptr);
        }
        vector<Node*> nxt;
    };
    Node* root;

    void backtrack(int i, int j, Node* cur,vector<vector<char>>& board, int len) {
        if(len == 10) return;
        vis[i][j] = true;

        for(int d=0; d<4; d++) {
            int newI = i + dx[d];
            int newJ = j + dy[d];
            if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && !vis[newI][newJ]) {
                if(cur->nxt[board[newI][newJ] - 'a'] == nullptr) {
                    cur->nxt[board[newI][newJ] - 'a'] = new Node();
                }
                backtrack(newI, newJ, cur->nxt[board[newI][newJ] - 'a'], board, len + 1);
            }
        }

        vis[i][j] = false;
    }
    bool exit(string &word) {
        Node* cur = root;
        for(auto &c: word) {
            if(cur->nxt[c - 'a'] != nullptr) {
                cur = cur->nxt[c - 'a'];
            } else {
                return false;
            }
        }
        return true;
    }

};
