#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


class MedianFinder {
public:
    MedianFinder() {
    }

    void addNum(int num) {
        st.insert(num);
    }

    double findMedian() {
        int n = st.size();
        float num = *st.find_by_order(n / 2);
        if(n & 1) return num;
        float num2 = *st.find_by_order(n / 2 - 1);
        return (num + num2) / 2;
    }
private:
    ordered_multiset<float> st;
};
