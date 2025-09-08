class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 1, idx = 0;
        for(int i=0; i<n; i++) {
            int curLen = 1, curIdx=i;
            int l=i-1, r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                curLen += 2;
                curIdx = l;
                l--, r++;
            }
            if(curLen > len) {
                len = curLen;
                idx = curIdx;
            }
        }
        for(int i=0; i<n; i++){
            int curLen = 0, curIdx = i;
            int l=i, r=i+1;
            while(l>=0 && r<n && s[l]==s[r]) {
                curLen +=2;
                curIdx = l;
                l--, r++;
            }
            if(curLen > len) {
                len = curLen;
                idx = curIdx;
            }
        }
        string ans = "";
        while(len--) {
            ans.push_back(s[idx++]);
        }
        return ans;
    }
};
