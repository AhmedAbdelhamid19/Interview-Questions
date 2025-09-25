class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++) {
            for (int j = 0; j < m; ++j) {
                if(board[i][j] == word[0]) {
                    vector<vector<bool>> vis(n, vector<bool>(m, false));
                    if(dfs(board, vis, word, 0, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
private:
    vector<int> dx{+0, +0, +1, -1};
    vector<int> dy{+1, -1, +0, +0};
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, string& word, int curLen, int i, int j) {
        int n = board.size(), m = board[0].size();
        if(board[i][j] == word[curLen]) {
            curLen++;
        }
        vis[i][j] = true;
        if(curLen == word.size()) {
            return true;
        }

        for(int d=0; d<4; d++) {
            int newI = i + dx[d], newJ = j + dy[d];
            if(newI>=0 && newI<n && newJ>=0 && newJ<m) {
                if(board[newI][newJ] == word[curLen] && !vis[newI][newJ]) {
                    bool ans = dfs(board, vis, word, curLen, newI, newJ);
                    if(ans) return true;
                }
            }
        }
        vis[i][j] = false;
        return false;
    }
};
