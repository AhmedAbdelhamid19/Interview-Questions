class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        for(int r=0; r<n; r++) {
            dp[r][r] = true;
            for(int l=0; l<r; l++) {
                dp[l][r] = s[l]==s[r] && (dp[l+1][r-1] || l == r-1);
            }
        }

        vector<vector<string>> ans;
        vector<string> cur;
        rec(0, s, cur, ans);
        return ans;
    }
private:
    bool dp[20][20];

    void rec(int l, string& s, vector<string>& cur, vector<vector<string>>& tot) {
        if(l == s.size()) {
            tot.push_back(cur);
            return;
        }

        for(int r=l; r<s.size(); r++) {
            if(dp[l][r]) {
                cur.push_back(s.substr(l, r-l+1));
                rec(r + 1, s, cur, tot);
                cur.pop_back();
            }
        }
    }
};
