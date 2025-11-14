
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, r = *max_element(piles.begin(), piles.end()), ans = r;
        while(l <= r) {
            long long m = (l + r) / 2;
            
            long long cntHours = 0;
            for(auto &it: piles) {
                cntHours += (it / m) + !!(it % m);
            }
            
            if(cntHours > h) {
                l = m + 1;
            } else {
                ans = m;
                r = m - 1;
            }
        }
        
        return ans;
    }
};
