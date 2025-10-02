class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &it: wordDict) mp[it] = true;
        memset(dp, -1, sizeof(dp));

        return run(0, s);
    }
private:
    map<string, bool> mp;
    short dp[1005];

    bool run(short i, string& s) {
        if(i == s.size()) return true;

        short &ret = dp[i];
        if(~ret) return ret;

        ret = false;
        for(int len=1; len<=20; len++) {
            if(mp[s.substr(i, len)]) {
                ret = run(i + len, s);
                if(ret) break;
            }
        }
        return ret;
    }
};
