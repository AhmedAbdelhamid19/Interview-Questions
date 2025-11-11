class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(1e4 + 1, 1e5);
        dp[0] = 0;
        for(int i=1; i<=amount; i++) {
            for(auto num: coins) {
                long long curNum = num;
                int cnt = 1;
                while(i - curNum * cnt >= 0) {
                    dp[i] = min( dp[i], dp[i - curNum * cnt] + cnt);
                    cnt++;
                }
            }
        }
        return dp[amount] == 1e5 ? -1 : dp[amount];
    }
};
