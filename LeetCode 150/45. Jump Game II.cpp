class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0, l=0, r=0, jumps = 0, n = nums.size();
        while(r < nums.size() - 1) {
            int preR = r, nxtR = r;
            for(int cur=l; cur<=r; cur++) {
                nxtR = max(nxtR, cur + nums[cur]);
            }
            jumps++;
            r = nxtR;
            l = preR + 1;
        }

        return jumps;
    }
};
