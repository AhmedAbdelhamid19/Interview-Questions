class Solution {
public:
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        vis.resize(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                    bfs(board, i, j);
                }
            }
        }
    }
private:
    int n, m;
    vector<vector<bool>> vis;
    vector<int> dx{+1, -1, +0, +0};
    vector<int> dy{+0, +0, +1, -1};
    void bfs(vector<vector<char>>& board, int i, int j) {
        bool surrounded = true;
        vector<pair<int,int>> group;
        
        queue<pair<int,int>> q;
        q.push({i, j});
        while(q.size()) {
            auto [curI, curJ] = q.front();
            group.push_back({curI, curJ});
            if(curI == 0 || curI == n-1 || curJ == 0 || curJ == m-1) {
                surrounded = false;
            }
            q.pop();
            
            for(int dir=0; dir<4; dir++) {
                int nxtI = curI + dx[dir];
                int nxtJ = curJ + dy[dir];
                if(nxtI>=0 && nxtI<n && nxtJ>=0 && nxtJ<m) {
                    if(!vis[nxtI][nxtJ] && board[nxtI][nxtJ] == 'O') {
                        q.push({nxtI, nxtJ});
                        vis[nxtI][nxtJ] = true;
                    }
                }
            }
        }
        if(surrounded) {
            for(auto &[curI, curJ]: group) {
                board[curI][curJ] = 'X';
            }
        }
    }
};
