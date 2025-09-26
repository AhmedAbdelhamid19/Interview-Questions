class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> st(stones.begin(), stones.end());
        while(st.size() >= 2) {
            int y = *st.rbegin();
            st.erase(--st.end());
            int x = *st.rbegin();
            st.erase(--st.end());
            
            y -= x;
            if(y) st.insert(y);
        }
        if(st.size()) return *st.rbegin();
        return 0;
    }
};
