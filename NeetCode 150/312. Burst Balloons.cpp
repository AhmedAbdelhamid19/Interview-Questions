class Solution {
public:
    int maxCoins(vector<int>& nums) {
        for(auto &it: dp) memset(dp, -1, sizeof(dp));
        n = nums.size();
        return run(0, n-1, nums);
    }
private:
    int dp[301][301], n;
    int run(int i, int j, vector<int> &nums) {
        if(j < i) return 0;

        int &ret = dp[i][j];
        if(~ret) return ret;

        for(int k=i; k<=j; k++) {
            int cur = nums[k] * (i == 0 ? 1 : nums[i-1]) * (j == n-1 ? 1 : nums[j+1]);
            ret = max(ret, cur + run(i, k-1, nums) + run(k+1, j, nums));
        }
        return ret;
    }
};
