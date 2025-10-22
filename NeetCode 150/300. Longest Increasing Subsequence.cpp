class Solution {
public:
    int lengthOfLIS(vector<int> nums) {
        int n = nums.size();
        vector<int>lis;
        for(int i=0; i<n; i++) {
            int idx = std::lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            if(idx == lis.size()) {
                lis.push_back(nums[i]);
            } else {
                lis[idx] = nums[i];
            }
        }
        return lis.size();
    }
};
