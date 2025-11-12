class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> freq(2e4 + 5), ans;
        vector<pair<int,int>> sorted;
        vector<vector<int>> sortedFreq(1e4 + 1);
        
        for(auto &it: nums) freq[it + 1e4]++;
        for(int i=0; i<2e4+5; i++) {
            if(freq[i]) {
                sorted.push_back({i - 1e4, freq[i]});
            }
        }
        for(auto it: sorted) {
            sortedFreq[it.second].push_back(it.first);
        }
        for(int i=1e4; i>=0; i--) {
            if(!k) break;
            while(sortedFreq[i].size() && k--) {
                ans.push_back(sortedFreq[i].back());
                sortedFreq[i].pop_back();
            }
        }
        return ans;
    }
};
