class Solution {
public:
    int maxProfit(vector<int> prices) {
        for(int i=0; i<5001; i++) {
            memset(dp[i], -1, sizeof (dp[i]));
        }
        return run(0, 0, prices);
    }
private:
    int dp[5001][2];
    int run(int i, int tokenBefore, vector<int>& prices) {
        if(i >= prices.size()) return 0;

        int &ret = dp[i][tokenBefore];
        if(~ret) return ret;

        ret = 0;
        ret = max(ret, run(i+1, tokenBefore, prices));
        ret = max(ret, -prices[i] + run(i+1, 1, prices));
        if(tokenBefore) {
            ret = max(ret, prices[i] + run(i+2, 0, prices));
            ret = max(ret, run(i + 1, 1, prices));
        }
        return ret;
    }
};
