class Solution {
public:
    int numIslands(vector<vector<char>> grid) {
        n = grid.size(), m = grid[0].size();
        vis.resize(n + 5, vector<bool>(m + 5));

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == '1')
                    ans++, bfs(i, j, grid);
            }
        }

        return ans;
    }
private:
    int n, m;
    vector<vector<bool>> vis;
    void bfs(int i, int j, vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        q.push({i, j});
        while(q.size()) {
            auto [curI, curJ] = q.front();
            q.pop();

            if(curI + 1 < n && !vis[curI + 1][curJ] && grid[curI + 1][curJ] == '1') {
                q.push({curI + 1, curJ});
                vis[curI + 1][curJ] = true;
            }
            if(curJ + 1 < m && !vis[curI][curJ + 1] && grid[curI][curJ + 1] == '1') {
                q.push({curI, curJ + 1});
                vis[curI][curJ + 1] = true;
            }
            if(curI - 1 >= 0 && !vis[curI - 1][curJ] && grid[curI - 1][curJ] == '1') {
                q.push({curI - 1, curJ});
                vis[curI - 1][curJ] = true;
            }
            if(curJ - 1 >= 0 && !vis[curI][curJ - 1] && grid[curI][curJ - 1] == '1') {
                q.push({curI, curJ - 1});
                vis[curI][curJ - 1] = true;
            }
        }
    }
};
