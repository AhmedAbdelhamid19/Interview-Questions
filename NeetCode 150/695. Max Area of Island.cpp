

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), curId = 0;
        id.resize(n + 5, vector<int>(m + 5));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]) id[i][j] = curId++;
            }
        }
        DSU dsu(curId);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(j+1<m && grid[i][j] && grid[i][j+1]) {
                    dsu.join(id[i][j], id[i][j+1]);
                }
                if(i+1<n && grid[i][j] && grid[i+1][j]) {
                    dsu.join(id[i][j], id[i+1][j]);
                }
            }
        }
        return curId ? dsu.mxs : 0;
    }
private:
    vector<vector<int>> id;
    struct DSU {
        int n,mxs;
        vector<int> sz , rep ;
        DSU(int size) {
            mxs = 1;
            n =  size;
            rep = sz = vector<int>(n+5,1);
            iota(rep.begin(), rep.end(),0);
        }
        int find(int a) {
            return rep[a]==a ? a : rep[a]=find(rep[a]);
        }
        bool join(int a, int b) {
            a = find(a);
            b = find(b);
            if(a == b) return 0;

            if(sz[a] > sz[b]) swap(a, b);
            rep[a] = b;
            sz[b] += sz[a];
            mxs = max(mxs, sz[b]);
            return 1;
        }
    };
};
