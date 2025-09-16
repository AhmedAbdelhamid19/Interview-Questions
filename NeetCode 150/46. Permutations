class Solution {
public:

    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        backtrack(nums, cur);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& cur) {
        if(cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!exist(nums[i], cur)) {
                cur.push_back(nums[i]);
                backtrack(nums, cur);
                cur.pop_back();
            }
        }
    }

    bool exist(int num, vector<int>& v) {
        for(int i=0; i<v.size(); i++) {
            if(num == v[i]) return 1;
        }
        return 0;
    }
};
