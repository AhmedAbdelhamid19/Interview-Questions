
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> heights) {
        n = heights.size(), m = heights[0].size();
        vector<pair<int,int>> pac, atl;
        vector<vector<int>> ans;
        vector<vector<bool>> pacFlag(n, vector<bool>(m)), atlFlag(n, vector<bool>(m));
        for(int i=0; i<n; i++) pac.push_back({i, 0}), atl.push_back({i, m - 1});
        for(int i=0; i<m; i++) pac.push_back({0, i}), atl.push_back({n - 1, i});

        bfs(heights, pac, pacFlag);
        bfs(heights, atl, atlFlag);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(pacFlag[i][j] && atlFlag[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
private:
    vector<int> dx {1, -1, 0, 0};
    vector<int> dy {0, 0, 1, -1};
    int n,m;
    void bfs(vector<vector<int>>& heights, vector<pair<int,int>> &start, vector<vector<bool>> &flag) {
        queue<pair<int,int>> q;
        for(auto [x,y]: start) {
            q.push({x, y});
            flag[x][y] = true;
        }
        while(q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for(int i=0; i<4; i++) {
                int newX = x + dx[i], newY = y + dy[i];
                if(newX < 0 || newY < 0 || newX >= n || newY >= m) continue;
                if(flag[newX][newY] || heights[newX][newY] < heights[x][y]) continue;
                flag[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
};
