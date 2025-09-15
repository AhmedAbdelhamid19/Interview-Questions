class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r=n-1, ans = -1;
        while(l <= r) {
            int m = (l + r) / 2;
            int mVal = nums[m], lVal = nums[l], rVal = nums[r];

            if(target == mVal) {
                ans = m;
                break;
            } else if((target >= lVal && (target < mVal || mVal < lVal))) {
                r = m - 1;
            } else if (target < mVal && mVal < lVal) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
