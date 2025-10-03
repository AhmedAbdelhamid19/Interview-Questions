class Solution {
public:
    int maxProduct(vector<int> nums) {
        int n = nums.size(), dp[n + 5][2], ans;
        dp[0][0] = (nums[0] > 0) * nums[0];
        dp[0][1] = (nums[0] < 0) * nums[0];
        ans = dp[0][0];
        for(int i=1; i<n; i++) {
            if(nums[i] == 0) {
                dp[i][0] = dp[i][1] = 0;
            } else if(nums[i] > 0) {
                dp[i][0] = max(nums[i], nums[i] * dp[i - 1][0]);
                dp[i][1] = nums[i] * dp[i - 1][1];
            } else {
                dp[i][1] = min(nums[i], nums[i] * dp[i - 1][0]);
                dp[i][0] = nums[i] * dp[i - 1][1];
            }
            ans = max(ans, dp[i][0]);
        }
        if(ans == 0 && std::count(nums.begin(), nums.end(),0) == 0) {
            return *max_element(nums.begin(), nums.end());
        }
        return ans;
    }
};
