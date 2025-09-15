class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), mx = 0, ans = 0;
        vector<int> mxL(n), mxR(n);

        for(int i=0; i<n; i++) {
            mxL[i] = mx;
            mx = max(mx, height[i]);
        }
        mx =0;
        for(int i=n-1; i>=0; i--) {
            mxR[i] = mx;
            mx = max(mx, height[i]);
        }

        for(int i=0; i<n; i++) {
            int mn = min(mxL[i], mxR[i]);
            if(mn > height[i]) {
                ans += mn - height[i];
            }
        }a
        return ans;
    }
};
