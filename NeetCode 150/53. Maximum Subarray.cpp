class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> v{nums[0]};
        for(int i=1; i<nums.size(); i++) {
            if(1LL * nums[i] * v.back() >= 0) v.back() += nums[i];
            else v.push_back(nums[i]);
        }
        if(v.size() == 1) {
            return v[0] < 0 ? *max_element(nums.begin(), nums.end()) : v[0];
        }

        int i = v[0] < 0, cur = v[i];
        vector<int> res{cur};
        while(i + 2 < v.size()) {
            int takeNext = cur + v[i + 1] + v[i + 2];
            if(takeNext > v[i + 2]) {
                cur += v[i + 1] + v[i + 2];
            } else {
                res.push_back(cur);
                cur = v[i + 2];
            }
            res.push_back(cur);
            i += 2;
        }
        res.push_back(cur);
        return *max_element(res.begin(), res.end());
    }
};
