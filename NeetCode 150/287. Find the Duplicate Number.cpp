class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1, ans = -1;
        while(l <= r) {
            int m = (l + r) / 2;
            int less = 0;
            for(auto &it: nums) less += (it <= m);

            if(less > m) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
