class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l=0, r=0, n = nums.size();
        while(r < n) {
            int mxR = r;
            for(int i=l; i<=r; i++) {
                mxR = max(mxR, i + nums[i]);
            }
            if(mxR == r) {
                r = mxR;
                break;
            }
            l = r + 1;
            r = mxR;
        }
        return r >= n - 1;
    }
};
