class Solution {
public:
    int dp[505][505];
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return run(0, 0, word1, word2);
    }
    int run(int i, int j, string& word1, string& word2) {
        int &ret = dp[i][j];
        if(~ret) return ret;

        if(i == word1.size()) return ret = word2.size() - j;
        if(j == word2.size()) return ret = word1.size() - i;

        ret = (word1[i] != word2[j]) + run(i+1, j+1, word1, word2);
        ret = min(ret, 1 + run(i+1, j, word1, word2));
        ret = min(ret, 1 + run(i, j+1, word1, word2));

        return ret;
    }
};
