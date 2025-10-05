
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        adj.resize(n);
        vis.resize(n, -1);
        vector<int> in(n);
        for(auto &it: prerequisites) {
            adj[it[0]].push_back(it[1]);
            in[it[1]]++;
        }
        for (int i = 0; i < n; ++i) {
            if(!in[i]) {
                if(!dfs(i)) return {};
            }
        }

        return ans.size() == n ? ans : vector<int>();
    }
private:
    int n;
    vector<vector<int>> adj;
    vector<int> vis;
    vector<int> ans;
    bool dfs(int u) {
        vis[u] = 1;
        for(auto &v: adj[u]) {
            if(vis[v] == 1) return false;
            if(vis[v] == 2) continue;
            if(!dfs(v)) return false;
        }
        vis[u] = 2;
        ans.push_back(u);
        return true;
    }
};
