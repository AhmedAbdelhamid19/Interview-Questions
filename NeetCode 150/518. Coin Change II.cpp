class Solution {
public:
    int dp[305][5005];
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return run(0, amount, coins);
    }
    int run(int i, int rem, vector<int>& coins) {
        if(i == coins.size()) return rem ==0;

        int &ret = dp[i][rem];
        if(~ret) return ret;

        ret = 0;
        ret = run(i+1, rem, coins);
        if(coins[i] <= rem) {
            ret += run(i, rem - coins[i], coins);
        }
        return ret;
    }
};
