class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp, token;
        for(auto &it: nums) mp[it]++;
        
        int ans = 0;
        for(auto &cur: nums) {
            if(token[cur]) continue;
            
            token[cur]++;
            int l = cur - 1, r = cur + 1, curAns = 1;
            while(mp.count(l) || mp.count(r)) {
                if(mp.count(l)) curAns++, token[l]++, l--;
                if(mp.count(r)) curAns++, token[r]++, r++;
            }
            ans = max(ans, curAns);
        }
        return ans;
    }
};
