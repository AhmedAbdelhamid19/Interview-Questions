class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        return (s1.size() + s2.size() == s3.size()) && run(0, 0, 0, s1, s2, s3);
    }
    bool run(int i, int j, int k, string& s1, string& s2, string& s3) {
        if(k == s3.size()) {
            return 1;
        }
        short &ret = dp[i][j][k];
        if(~ret) return ret;

        ret = 0;
        if(i < s1.size() && s1[i] == s3[k]) {
            ret |= run(i+1, j, k+1, s1, s2, s3);
            if(ret) return ret;
        }
        if(j < s2.size() && s2[j] == s3[k]) {
            ret |= run(i, j+1, k+1, s1, s2, s3);
            if(ret) return ret;
        }

        return ret;
    }
private:
    short dp[101][101][201];
};
