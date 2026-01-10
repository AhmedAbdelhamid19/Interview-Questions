class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        string s2 = "";
        for (int i=0; i<n; i++) {
            if (s[i] == ' ') continue;
            s2.push_back(s[i]);
        }
        s = s2;
        n = s.size();

        v.resize(n);
        stack<int> stk;
        for (int i=0; i<n; ++i) {
            if (s[i] == '(') stk.push(i);
            else if (s[i] == ')') {
                v[stk.top()] = i;
                stk.pop();
            }
        }
        return recursion(s, 0, n - 1);
    }
private:
    vector<int> v;
    int recursion(string &s, int l, int r) {
        if (l > r) return 0;
        if (s[l]=='+') l++;

        bool sign = 0;
        string cur = "";
        if (l <= r && s[l] == '-') {
            sign ^= 1, l++;
        }
        if (l <= r && s[l] == '(') {
            return recursion(s, l+1, v[l]-1) * (sign ? -1 : 1) + recursion(s, v[l] + 1, r);
        }
        while (l <= r && isdigit(s[l])) {
            cur.push_back(s[l]);
            l++;
        }

        int curNum = stoll(cur) * (sign ? -1 : 1);
        return curNum + recursion(s, l, r);
    }
};
