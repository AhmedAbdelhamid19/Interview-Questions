class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 2, 1), suf(n + 2, 1), ans(n);
        for(int i=0; i<n - 1; i++) {
            pre[i + 1] = nums[i] * pre[i];
        }
        for(int i=n-1; i>0; i--) {
            suf[i + 1] = nums[i] * suf[i + 2];
        }
        for(int i=0; i<n; i++) {
            ans[i] = pre[i] * suf[i + 2];
        }
        return ans;
    }
};
