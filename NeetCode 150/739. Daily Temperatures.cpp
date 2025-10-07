class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        int n = temperatures.size();

        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            while(stk.size() && temperatures[i] > stk.top().first) {
                ans[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.push({temperatures[i], i});
        }
        return ans;
    }
};
