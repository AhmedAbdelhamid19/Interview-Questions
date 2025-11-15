class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<vector<int>> pref(n, vector<int>(30, 0));
        for(int i=0; i<n; i++) {
            if(i) pref[i] = pref[i - 1];
            pref[i][s[i] - 'A']++;
        }
        
        int ans = -1e9;
        for(int i=0; i<n; i++) {
            int l=i, r=n-1, mxIdx=i;
            while(l <= r) {
                int m = (l + r) / 2;
                int mnReplace = 1e9;
                for(char c='A'; c<='Z'; c++) {
                    int charCnt = pref[m][c - 'A'] - (i ? pref[i - 1][c - 'A'] : 0);
                    int curReplace = (m - i + 1) - charCnt;
                    mnReplace = min(mnReplace, curReplace);
                }
                
                if(mnReplace <= k) {
                    mxIdx = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            ans = max(ans, mxIdx - i + 1);
        }
        return ans;
    }
};
