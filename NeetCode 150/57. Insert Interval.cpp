class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> intervals, vector<int> newInterval) {
        set<pair<int,int>> st;
        for(auto &it: intervals) st.insert({it[0], it[1]});
        st.insert({newInterval[0], newInterval[1]});

        auto it = st.find({newInterval[0], newInterval[1]});

        bool pre = true, nxt = true;
        while(pre || nxt) {
            if(it == st.begin()) pre = false;
            else if(pre) {
                auto preIt = it; preIt--;
                if(preIt->second >= it->first) {
                    pair<int,int> cur = {min(it->first, preIt->first), max(it->second, preIt->second)};
                    st.erase(it), st.erase(preIt), st.insert(cur);
                    it = st.find(cur);
                } else {
                    pre = false;
                }
            }

            if(it == --st.end()) nxt = false;
            else if(nxt) {
                auto nxtIt = it; nxtIt++;
                if(it->second >= nxtIt->first) {
                    pair<int,int> cur = {min(it->first, nxtIt->first), max(it->second, nxtIt->second)};
                    st.erase(it), st.erase(nxtIt), st.insert(cur);
                    it = st.find(cur);
                } else {
                    nxt = false;
                }
            }
        }

        vector<vector<int>> ans;
        for(auto p: st) ans.push_back({p.first, p.second});

        return ans;
    }
};
