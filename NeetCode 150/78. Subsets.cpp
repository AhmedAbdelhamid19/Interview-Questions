class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0; i<(1 << n); i++) {
            vector<int> cur;
            for(int b=0; b<n; b++) {
                if((i >> b) & 1) {
                    cur.push_back(nums[b]);
                }
            }
            ans.push_back(cur);
        }

        return ans;
    }
};
