class Solution {
public:
    int reverse(int x) {
        string num, mx;
        if(x >= 0) {
            num = to_string(x);
            std::reverse(num.begin(), num.end());
            mx = to_string(INT_MAX);

            if(compare(num, mx) == 1) return 0;
            else return stoi(num);
        } else {
            num = to_string(x).substr(1);
            std::reverse(num.begin(), num.end());
            mx = to_string(INT_MIN).substr(1);

            if(compare(num, mx) == 1) return 0;
            else {
                num = "-" + num;
                return stoi(num);
            }
        }
    }
    int compare(string l, string r) {
        int ans = 0;
        if(l.size() > r.size()) return 1;
        if(r.size() > l.size()) return -1;
        for(int i=0; i<l.size(); i++) {
            if(l[i] > r[i]) return 1;
            if(r[i] > l[i]) return -1;
        }
        return 0;
    }
};
