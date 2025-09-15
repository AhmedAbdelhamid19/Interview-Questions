class Solution {
public:
    vector<int> cur;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int,int> mp;
        for(auto &it: candidates) mp[it]++;
        vector<pair<int,int>>v(mp.begin(), mp.end());

        rec(v, target, 0, 0);
        return ans;
    }

    void rec(vector<pair<int,int>>& candidates, int target, int sum, int i) {
        if(sum == target) {
            ans.push_back(cur);
            return;
        }
        if(i == candidates.size()) {
            return;
        }

        int cnt = 0;
        for(int j=0; j<candidates[i].second; j++) {
            int tot = sum + candidates[i].first * (j + 1);
            if(tot > target) break;

            cnt ++;
            cur.push_back(candidates[i].first);
            rec(candidates, target, sum + candidates[i].first * (j + 1), i + 1);
        }
        while(cnt--) {
            cur.pop_back();
        }

       // don't take the current element, and move next
        rec(candidates, target, sum, i + 1);
        return;
    }
};
