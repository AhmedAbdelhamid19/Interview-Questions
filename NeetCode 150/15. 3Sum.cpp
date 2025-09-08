class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n-2; i++) {
            int l=i+1, r=n-1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[r-1] == nums[r]) r--;
                    while(l<r && nums[l+1] == nums[l]) l++;
                    r--;
                } else if (sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }
            while(i<n-1 && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};
