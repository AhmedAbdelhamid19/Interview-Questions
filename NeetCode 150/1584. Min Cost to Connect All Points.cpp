
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>> points) {
        if(points.size() == 1) return 0;
        vector<pair<int,pair<int,int>>>edges,mst;
        int n = points.size(), ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i == j) continue;
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        DSU dsu(n);
        for(auto &[w,edg] : edges) {
            auto &[u,v] = edg;
            if(dsu.join(u,v)) ans += w;
            if(dsu.comp == 1) break;
        }
        return ans;
    }
private:
    struct DSU {
        int n,comp;
        vector<int> rep ;
        DSU(int size) {
            n = comp = size;
            rep = vector<int>(n+5, 1);
            iota(rep.begin(), rep.end(), 0);
        }
        int find(int a) {
            return rep[a]==a ? a : rep[a]=find(rep[a]);
        }
        bool isConnected(int a,int b) {
            return find(a) == find(b);
        }
        bool join(int a, int b) {
            a = find(a), b = find(b);
            if(a == b) return false;

            comp--;
            rep[a] = b;
            return true;
        }
    };

};
