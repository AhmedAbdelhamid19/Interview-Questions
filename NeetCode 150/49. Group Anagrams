class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        string s;
        for(auto &it: strs) {
            s = it;
            sort(s.begin(), s.end());
            mp[s].push_back(it);
        }
        vector<vector<string>> ans;
        for(auto &[str, vec]: mp) {
            ans.push_back(vec);
        }
        return ans;
    }
};
