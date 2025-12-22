class Solution {
public:
    int findTargetSumWays(vector<int> nums, int target) {
        backtrack(nums, target, 0, 0);
        return ans;
    }
private:
    int ans = 0;
    void backtrack(vector<int>& nums, int target, int idx, int curSum) {
        if (idx == nums.size()) {
            ans += (curSum == target);
            return;
        }
        backtrack(nums, target, idx + 1, curSum + nums[idx]);
        backtrack(nums, target, idx + 1, curSum - nums[idx]);
    }
};
