class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        int mxLen = run(0, 0, text1, text2);
        
        return mxLen;
    }
private:
    short dp[1001][1001];
    short run(short i, short j, string& txt1, string& txt2) {
        if(i == txt1.size() || j == txt2.size()) return 0;
        
        short &ret = dp[i][j];
        if(~ret) return ret;
        
        if(txt1[i] == txt2[j]) {
            ret = 1 + run(i + 1, j + 1, txt1, txt2);
        } else {
            ret = run(i + 1, j, txt1, txt2);
            ret = max(ret, run(i, j + 1, txt1, txt2));
        }
        
        return ret;
    }
    void generate(int i, int j, string &txt1, string &txt2, int len, string &ans) {
        if(i == txt1.size() || j == txt2.size()) return;
        
        if(txt1[i] == txt1[j]) {
            ans.push_back(txt1[i]);
            generate(i + 1, j + 1, txt1, txt2, len - 1, ans);
        } else {
            if(dp[i + 1][j] == len) {
                generate(i + 1, j, txt1, txt2, len, ans);
            } else {
                generate(i, j + 1, txt1, txt2, len, ans);
            }
        }
    }
};
