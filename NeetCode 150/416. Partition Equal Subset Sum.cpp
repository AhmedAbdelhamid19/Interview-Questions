class Solution {
public:
    bool canPartition(vector<int> nums) {
        int sum = 0;
        for(auto &it: nums) sum += it;
        if(sum & 1) return false;

        vector<bool> dp(sum/2 + 1);
        dp[0] = true;
        for(auto &num: nums) {
            for(int s=sum/2; s>=num; s--) {
                dp[s] = dp[s] || dp[s - num];
            }
        }
        return dp[sum/2];
    }
};
