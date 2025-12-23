class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            int j = i + 1;
            while (j < n && nums[j] == nums[j-1] + 1) j++;
            j--;
            if (i == j) ans.push_back(to_string(nums[i]));
            else {
                ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            }
            i = j;
        }
        return ans;
    }
};
