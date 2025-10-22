class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sFreq(30), tFreq(30);
        for(auto &it: s) {
            sFreq[it - 'a']++;
        }
        for(auto &it: t) {
            tFreq[it - 'a']++;
        }
        for(int i=0; i<30; i++) {
            if(sFreq[i] != tFreq[i]) {
                return false;
            }
        }
        return  true;
    }
};
