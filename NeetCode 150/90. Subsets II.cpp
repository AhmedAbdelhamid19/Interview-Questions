class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<(1 << n); i++) {
            vector<int> cur;
            bool test = true;
            for(int b=0; b<n; b++) {
                if((i >> b) & 1) {
                    if(b && ((i >> (b - 1)) & 1) == 0 && nums[b - 1] == nums[b]) {
                        test = false;
                        break;
                    }
                    cur.push_back(nums[b]);
                }
            }
            if(test)
                ans.push_back(cur);
        }
        return ans;
    }
};
