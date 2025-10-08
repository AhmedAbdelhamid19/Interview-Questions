class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0;
        deque<int> dq;
        vector<int> ans;
        while(r < k) {
            while(dq.size() && nums[r] > dq.back()) 
                dq.pop_back();
            
            dq.push_back(nums[r++]);
        }
        
        ans.push_back(dq.front());
        while(r < n) {
            if(dq.front() == nums[l++])
                dq.pop_front();
            while(dq.size() && nums[r] > dq.back()) 
                dq.pop_back();
            dq.push_back(nums[r++]);
            
            ans.push_back(dq.front());
        }
        return ans;
    }
};

/*
// nlog(n) solution

*/
