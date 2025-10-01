class Solution {
public:
    int countSubstrings(string s) {
        bool dp[1005][1005];
        int n = s.size();
        int ans = 0;
        for(int r=0; r<n; r++) {
            dp[r][r] = true;
            ans++;
            for(int l=0; l<r; l++) {
                dp[l][r] = s[l] == s[r] && (l == r - 1 || dp[l+1][r-1]);
                ans += dp[l][r];
            }
        }
        return ans;
    }
};
