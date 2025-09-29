class Solution {
public:
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return run(0, 0, s, t);
    }
    int run(int i, int j, string& s, string& t) {
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        int &ret = dp[i][j];
        if(~ret) return ret;

        ret = run(i+1, j, s, t);
        if(s[i] == t[j]) {
            ret += run(i+1, j+1, s, t);
        }

        return ret;
    }
private:
    int dp[1001][1001];
};
