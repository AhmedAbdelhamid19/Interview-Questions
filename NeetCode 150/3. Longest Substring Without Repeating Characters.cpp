class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = min(1, n);
        for(int i=0; i<n && n-i>ans; i++) {
            int l=0, r=n-i, curAns = 1;
            while(r >= l) {
                int m = (r + l) >> 1;
                if(valid(i, m, s)) {
                    curAns = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            ans = max(ans, curAns);
        }
        return ans;
    }
private:
    bool valid(int ind, int len, string &s) {
        vector<bool> chars(256, 0);
        for(int i=ind; i<ind+len; i++) {
            if(chars[(int) s[i]])
                return false;
            chars[(int) s[i]] = true;
        }
        return true;
    }
};
