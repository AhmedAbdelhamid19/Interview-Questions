class Solution {
public:
    int minSubArrayLen(int target, vector<int> nums) {
        int l=0, r=0, sum=0, ans = INT_MAX;
        while (l<nums.size() && r<nums.size()) {
            while (r<nums.size() && sum<target) {
                sum += nums[r++];
            }
            while (sum >= target && l<=r && l < nums.size()) {
                ans = min(ans, r-l);
                sum -= nums[l++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
