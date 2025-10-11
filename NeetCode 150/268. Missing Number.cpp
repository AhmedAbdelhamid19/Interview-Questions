class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        vector<bool> exist(n + 1, false);
        for(auto &num: nums) {
            exist[num] = true;
        }
        
        
        for(int i=0; i<=n; i++) {
            if(!exist[i]) {
                ans = i;
                break;
            } 
        }
        return ans;
    }
};
