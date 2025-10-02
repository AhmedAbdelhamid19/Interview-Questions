
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> freq(1e5, 0);
        for(auto &it: nums) {
            freq[it + 3e4]++;
        }
        int ans = -1;
        for(int i=0; i<1e5; i++) {
            if(freq[i] == 1) {
                ans =  i - 3e4;
                break;
            } 
        }
        return ans;
    }
};
