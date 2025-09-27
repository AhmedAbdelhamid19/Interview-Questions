class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        multiset<int, greater<int>> st;
        map<char,int> mp;
        for(auto &it: tasks) mp[it]++;
        for(auto it: mp) st.insert(it.second);

        int ans = 0;
        while(st.size() >= n + 1) {
            auto it = st.begin();
            vector<int> v;
            for(int i=0; i<n+1; i++) {
                if(*it - 1 > 0)
                    v.push_back(*it - 1);
                it++;
            }
            for(int i=0; i<n+1; i++) {
                st.erase(st.begin());
            }
            while(v.size()) {
                st.insert(v.back());
                v.pop_back();
            }
            ans += n + 1;
        }

        if(st.size())
            ans += (*st.begin() - 1) * (n + 1) + st.count(*st.begin());
        return ans;
    }
};
