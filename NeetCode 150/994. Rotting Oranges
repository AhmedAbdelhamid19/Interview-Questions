int dx[] = {+0, +0, -1, +1, -1, -1, +1, +1};
int dy[] = {+1, -1, +0, +0, +1, -1, +1, -1};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0, cnt = 0;
        queue<pair<int,int>> q;
        vector<vector<int>> dis(n, vector<int>(m, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    dis[i][j] = 0;
                }
                cnt += grid[i][j] == 1;
            }
        }

        while(q.size()) {
            auto &[x, y] = q.front();
            q.pop();
            for(int i=0; i<4; i++) {
                int newX = x+dx[i], newY=y+dy[i];
                if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]==1 && dis[newX][newY]==-1){
                    q.push({newX, newY});
                    dis[newX][newY] = dis[x][y] + 1;
                    ans = dis[newX][newY];
                    cnt--;
                }
            }
        }
        return !cnt ? ans : -1;
    }
};
