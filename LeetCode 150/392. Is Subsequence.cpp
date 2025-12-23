class Solution {
public:
    bool isSubsequence(string s, string t) {
        int it1=0, it2=0;
        while (it1 < s.size() && it2 < t.size()) {
            if (s[it1] == t[it2]) {
                it1++, it2++;
                continue;
            } else {
                it2++;
            }
        }
        return it1 == s.size();
    }
};
