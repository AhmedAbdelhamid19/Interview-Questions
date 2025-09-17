class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> seg;
        for(auto &it: intervals) {
            seg.push_back({it[0], it[1]});
        }
        sort(seg.begin(), seg.end(), [](const pair<int,int>& l, const pair<int,int>& r) {
            return l.first == r.first ? l.second >= r.second : l.first < r.first;
        });

        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            auto [l, r] = seg[i];
            while(i < n && r >= seg[i].first) {
                r = max(r, seg[i].second);
                i++;
            }
            ans.push_back({l, r});
            i--;
        }

        return ans;
    }
};
