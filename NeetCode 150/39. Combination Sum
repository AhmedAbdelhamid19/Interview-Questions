class Solution {
public:
    vector<int> cur;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        rec(candidates, target, 0, 0);
        return ans;
    }

    void rec(vector<int>& candidates, int target, int sum, int i) {
        if(sum == target) {
            ans.push_back(cur);
            return;
        }
        if(i == candidates.size()) {
            return;
        }


        if(candidates[i] + sum <= target) {
            int cnt = 0;
            while(candidates[i] * (cnt + 1) + sum <= target) {
                cnt++;
                cur.push_back(candidates[i]);
                rec(candidates, target, sum + candidates[i] * cnt, i + 1);
            }
            while(cnt--) cur.pop_back();
        }
        
        rec(candidates, target, sum, i + 1);
        return;
    }
};
