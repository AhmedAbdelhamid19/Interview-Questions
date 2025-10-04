class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for(int i=0; i<n; i++) {
            dp[i] = nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0);
            if(i - 1 >= 0) dp[i] = max(dp[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
};
