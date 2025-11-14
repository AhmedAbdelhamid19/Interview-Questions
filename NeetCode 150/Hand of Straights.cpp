class Solution {
public:
    bool isNStraightHand(vector<int> hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize) return false;

        map<int,int> mp;
        for(auto &it: hand) mp[it]++;

        deque<pair<int,int>> dq(mp.begin(), mp.end());
        int i=0;
        while(i < dq.size()) {
            while(i<dq.size() && dq[i].second == 0) i++;
            if(i == dq.size()) break;
            if(i + groupSize > dq.size()) return false;

            for(int j=i+1; j<i+groupSize; j++) {
                if(dq[j].first != dq[j-1].first + 1 || dq[j].second<dq[i].second) return false;
                dq[j].second -= dq[i].second;
            }
            dq[i].second = 0;
        }
        return true;
    }
};
