
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for (int i = 0; i < 101; ++i) {
            for (int j = 0; j < 101; ++j) {
                dp[i][j] = 1e9;
            }
        }
        adj.resize(n);
        bool test = false;
        for(auto edg: flights) {
            adj[edg[0]].push_back({edg[1], edg[2]});
            if(edg[1] == dst) test = true;
        }

        if(!test) return -1;
        int ans = run(src, k + 1, dst, 0);
        return ans == 1e9 ? -1 : ans;
    }
private:
    int dp[101][101];
    vector<vector<pair<int,int>>> adj;
    int run(int i, int rem, int dst, int curCost) {

        if(i == dst) return dp[i][rem] = 0;
        if(rem == 0) return 1e9;

        int &ret = dp[i][rem];
        if(ret != 1e9) return ret;

        for(auto [j, c]: adj[i]) {
            ret = min(ret, c + run(j, rem - 1, dst, curCost + c));
        }
        return ret;
    }
};
