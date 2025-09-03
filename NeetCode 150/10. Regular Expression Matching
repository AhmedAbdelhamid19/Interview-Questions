class Solution {
public:
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return run(0, 0, s, p);
    }
private:
    int dp[22][22];
    bool run(int sPtr, int pPtr, string& s, string& p) {
        int &ret = dp[sPtr][pPtr];
        if(~ret) return ret;
        ret = 0;

        if(pPtr + 1 < p.size() && p[pPtr + 1] == '*') {
            ret |= run(sPtr, pPtr+2, s, p); // take 0 char
            if(sPtr < s.size() && (s[sPtr] == p[pPtr] || p[pPtr] == '.')) {
                ret |= run(sPtr + 1, pPtr+2, s, p); // take 1 and skip
                ret |= run(sPtr + 1, pPtr, s, p); // take 1 or more
            }
        }

        if(sPtr == s.size() || pPtr == p.size()) {
            return (ret |= (sPtr == s.size() && pPtr == p.size()));
        }

        if(p[pPtr] == '.') {
            ret |= run(sPtr + 1, pPtr + 1, s, p);
        } else {
            ret |= (s[sPtr] != p[pPtr] ? 0 : run(sPtr + 1, pPtr + 1, s, p));
        }
        return ret;
    }
};
