class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size(), matches = 0, uniqueChars = 0;
        pair<int,int> ans = {-1, -1};
        vector<int>tFreq(100), curFreq(100);
        for(auto &it: t) tFreq[it - 'A']++;
        uniqueChars = 100 - std::count(tFreq.begin(), tFreq.end(), 0);

        int l=0, r=0;
        while(r < n) {
            while (r < n && matches != uniqueChars) {
                curFreq[s[r] - 'A']++;
                if(curFreq[s[r] - 'A'] == tFreq[s[r] - 'A']) {
                    matches++;
                }
                r++;
            }
            if(matches == uniqueChars) {
                ans = ans.first == -1 || ans.second - ans.first + 1 > r - l ? make_pair(l, r - 1) : ans;
            }

            if(curFreq[s[l] - 'A'] == tFreq[s[l] - 'A']) {
                matches--;
            }
            curFreq[s[l] - 'A']--;
            l++;
            while(l < r && (tFreq[s[l] - 'A'] == 0 || curFreq[s[l] - 'A'] > tFreq[s[l] - 'A'])) {
                curFreq[s[l] - 'A']--;
                l++;
            }
            if(matches == uniqueChars) {
                ans = ans.first == -1 || ans.second - ans.first + 1 > r - l ? make_pair(l, r - 1) : ans;
            }
        }

        return ans.first == -1 ? "" : s.substr(ans.first, ans.second - ans.first + 1);
    }
};
