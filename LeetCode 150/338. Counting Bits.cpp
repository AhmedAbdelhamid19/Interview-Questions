class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1);
        int cnt = 0;
        for(int i=0; i<n+1; i++) {
            for(int j=0; j<=17; j++) {
                if((i >> j) & 1) cnt++;
            }
            v[i] = cnt;
            cnt = 0;
        }
        return v;
    }
};
