class Solution {
public:
    int canCompleteCircuit(vector<int> gas, vector<int> cost) {
        int n = gas.size(), ans = -1;
        vector<int> freq(n + 1);
        multiset<int> nxt, prev;
        for(int i=1; i<=n; i++) {
            freq[i] = (gas[i - 1] - cost[i - 1]) + freq[i - 1];
            nxt.insert(freq[i]);
        }

        for(int i=1; i<=n; i++) {
            int mnNxt = *nxt.begin();
            int mnPre = prev.size() ? *prev.begin() : 0;

            if(mnPre + freq[n] - freq[i - 1] >= 0 && mnNxt - freq[i - 1] >= 0) {
                ans = i - 1;
                break;
            }
            nxt.erase(nxt.find(freq[i]));
            prev.insert(freq[i]);
        }
        return ans;
    }
};
