class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1, ans = 0;
        while(l<r) {
            int w = r - l;
            int h = min(height[l], height[r]);
            ans = max(ans, w * h);

            if(height[l] < height[r]) {
                l++;
            } else if(height[r] < height[l]) {
                r--;
            } else {
                if(height[r-1] > height[l+1]) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};
