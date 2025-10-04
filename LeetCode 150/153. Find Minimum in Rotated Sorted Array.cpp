class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, ans = -1;
        while(l<=r) {
            int m = (l + r) / 2;
            if(nums[m] > nums.back()) {
                l = m + 1;
            } else  {
                ans = nums[m];
                r = m - 1;
            }
        }
        return ans;
    }
};
