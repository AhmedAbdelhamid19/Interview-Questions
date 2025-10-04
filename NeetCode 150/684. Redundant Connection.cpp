class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        vector<int> ans;
        for(auto &it: edges) {
            if(!dsu.join(it[0], it[1])) {
                ans = it;
                break;
            }
        }
        return ans;
    }
private:
    struct DSU {
        int n,comp;
        vector<int> sz , rep ;
        DSU(int size) {
            n = comp = size;
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

            comp--;
            rep[a] = b;
            return 1;
        }
    };
};
