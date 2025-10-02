class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), curMx = 0, ans = 0;
        for(int i=n-1; i>=0; i--) {
            ans = max(ans, curMx - prices[i]);
            curMx = max(curMx, prices[i]);
        }
        return ans;
    }
};
