class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> freq(2e4 + 5);
        for(auto &it: nums) {
            freq[it + 1e4]++;
        }
        
        int ans = -1;
        for(int i=2e4; i>=0; i--) {
            if(freq[i]) {
                k -= freq[i];
            }
            if(k <= 0) {
                ans = i - 1e4;
                break;
            }
        }
        return ans;
    }
};
