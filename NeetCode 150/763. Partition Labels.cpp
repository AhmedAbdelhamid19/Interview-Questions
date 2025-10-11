class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> lIndx(30, -1), mx(n), ans;

        for (int i = 0; i < n; ++i) {
            lIndx[s[i] - 'a'] = i;
        }
        for(int i=0; i<n; i++) {
            mx[i] = lIndx[s[i] - 'a'];
        }
        for(int i=0; i<n; i++) {
            if(i) mx[i] = max(mx[i], mx[i - 1]);
        }

        int l=0, r=0;
        while(r < n) {
            while(mx[r] != r) r = mx[r];
            ans.push_back(r - l + 1);
            l = r = r + 1;
        }
        return ans;
    }
};
