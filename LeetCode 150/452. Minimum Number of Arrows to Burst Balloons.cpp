
class Solution {
public:
    int findMinArrowShots(vector<vector<int>> points) {
        int n = points.size();
        vector<bool> taken(n);
        vector<pair<int,pair<int,int>>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({points[i][0], {i, 0}});
            v.push_back({points[i][1], {i, 1}});
        }
        sort(v.begin(), v.end(), [&] ( const pair<int, pair<int,int>>&l, const pair<int, pair<int,int>>&r) {
            return l.first == r.first ? l.second.second < r.second.second : l.first < r.first;
        });

        int ans = 0;
        vector<int> curSegments;
        for (auto [x, it]:v) {
            auto [idx, typ] = it;
            if (typ == 0) {
                curSegments.push_back(idx);
            } else if (!taken[idx]) {
                ans++;
                for (auto it2: curSegments) {
                    taken[it2] = true;
                }
                curSegments.clear();
            }
        }
        return ans;
    }
};
