class Solution {
public:
    vector<string> v = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        string s = "";
        rec(0, s, digits);
        return ans;
    }
    void rec(int i, string &s, string &digits) {
        if(i == digits.size()) {
            ans.push_back(s);
            return;
        }
        for(int cur=0; cur<v[digits[i]-'0'-2].size(); cur++) {
            s.push_back(v[digits[i]-'0'-2][cur]);
            rec(i+1, s, digits);
            s.pop_back();
        }
    }
};
