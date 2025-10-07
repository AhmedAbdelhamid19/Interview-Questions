class Solution {
public:
    int networkDelayTime(vector<vector<int>> times, int n, int k) {
        dis.resize(n, 1e9);
        adj.resize(n);
        k--;

        for(auto &it: times) {
            int u = it[0] - 1, v = it[1] - 1, w = it[2];
            adj[u].push_back({v, w});
        }

        pq.push({0, k});
        dis[k] = 0;
        while(pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();

            if(d != dis[u]) continue;
            for(auto [v, w]: adj[u]) {
                int vDis = w + d;
                if(vDis < dis[v]) {
                    dis[v] = vDis;
                    pq.push({dis[v], v});
                }
            }
        }

        int ans = *max_element(dis.begin(), dis.end());
        return ans == 1e9 ? -1 : ans;
    }
private:
    vector<vector<pair<int,int>>> adj;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dis;
};
