class Solution {
public:
    int largestRectangleArea(vector<int> heights) {
        int n = heights.size(), ans = 0;
        vector<int> mxR(n), mnL(n);
        generate(heights, mxR, true);
        generate(heights, mnL, false);

        for(int i=0; i<n; i++) {
            ans = max(ans, heights[i] * (mxR[i] - mnL[i] - 1));
        }
        return ans;
    }
private:
    void generate(vector<int>& heights, vector<int>& mxIdx, bool right) {
        int n = heights.size();
        stack<pair<int,int>> stk, stk2;
        for(int i=(right ? 0 : n-1); (right ? i<n : i>=0); (right ? i++ : i--)) {
            while(!stk.empty() && heights[i] < stk.top().first) {
                auto [val, idx] = stk.top();
                stk.pop();
                mxIdx[idx] = i;
            }
            stk.push({heights[i], i});
        }
        while (stk.size()) {
            auto [val, idx] = stk.top();
            stk.pop();
            mxIdx[idx] = right ? n : -1;
        }
    }
};
