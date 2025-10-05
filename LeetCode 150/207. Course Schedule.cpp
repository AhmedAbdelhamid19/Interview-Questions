class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> prerequisites) {
        adj.resize(numCourses);
        vis.resize(numCourses, -1);
        cnt = 0;
        for(auto &it: prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0; i<numCourses; i++) {
            if(vis[i] == -1 && !dfs(i)) return 0;
            cnt++;
        }
        return 1;
    }
private:
    int cnt;
    vector<vector<short>> adj;
    vector<int> vis;
    bool dfs(int u) {
        vis[u] = 1;
        for(auto &v: adj[u]) {
            if(vis[v] == 1) return false;
            if(vis[v] == 2) continue;
            if(!dfs(v)) return false;
        }
        vis[u] = 2;
        return true;
    }
};
