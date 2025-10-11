
class Solution {
public:
    int swimInWater(vector<vector<int>> grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dis(n, vector<int>(n, 1e8));
        int dx[] {1, -1, 0, 0};
        int dy[] {0, 0, 1, -1};

        pq.push({grid[0][0], {0, 0}});
        dis[0][0] = grid[0][0];
        while(pq.size()) {
            auto [mx, cur] = pq.top();
            auto [i, j] = cur;
            if(i == n-1 && j == n-1) break;
            pq.pop();

            if(mx != dis[i][j]) continue;
            for(int dir=0; dir<4; dir++) {
                int nxtI = i + dx[dir];
                int nxtJ = j + dy[dir];
                if(nxtI < 0 || nxtJ < 0 || nxtI >= n || nxtJ >= n) continue;
                int nxtMx = max(mx, grid[nxtI][nxtJ]);
                if(nxtMx >= dis[nxtI][nxtJ]) continue;

                pq.push({nxtMx, {nxtI, nxtJ}});
                dis[nxtI][nxtJ] = nxtMx;
            }
        }

        return dis[n-1][n-1];
    }
};
