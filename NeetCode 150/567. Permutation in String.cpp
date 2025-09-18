class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<char> ch1(30), ch2(30);
        for(auto &c: s1) ch1[c - 'a']++;
        for(int i=0; i<s1.size() - 1; i++) {
            ch2[s2[i] - 'a']++;
        }

        int l = 0, r = s1.size() - 1;
        while(r < s2.size()) {
            ch2[s2[r] - 'a']++;
            if(ch1 == ch2) return true;
            ch2[s2[l] - 'a']--;
            l++, r++;
        }
        return false;
    }
};
