class Solution {
public:
    bool checkValidString(string s) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return run(0, 0, s);
    }
private:
    int dp[105][105], n;
    bool run(int i, int open, string &s) {
        if(i == n) return open == 0;

        int &ret = dp[i][open];
        if(~ret) return ret;

        ret = false;
        if(s[i] == '(') {
            ret |= run(i + 1, open + 1, s);
        } else if (s[i] == ')' && open) {
            ret |= run(i + 1, open - 1, s);
        } else if(s[i] == '*') {
            ret |= run(i + 1, open, s);
            ret |= run(i + 1, open + 1, s);
            if(open) ret |= run(i + 1, open - 1, s);
        }
        return ret;
    }
};
