class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto& [num, v] : mp) {
            if (num * 2 == target && v.size() > 1) {
                return vector<int>{v[0], v[1]};
            } else {
                int rm = target - num;
                if (mp.count(rm)) {
                    return vector<int>{v[0], mp[rm][0]};
                }
            }
        }
        return vector<int>{};
    }
};
