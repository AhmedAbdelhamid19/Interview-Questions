class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for(auto &it: nums) st.insert(it);
        this->k = k;
        while(st.size() > k) st.erase(st.begin());
    }

    int add(int val) {
        st.insert(val);
        if(st.size() > k) st.erase(st.begin());
        return *st.begin();
    }
private:
    int k;
    multiset<int> st;
};
