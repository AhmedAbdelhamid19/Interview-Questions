class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "0";
        for(int i=num1.size() - 1; i>=0; i--) {
            string mulRes = mul(num1[i] - '0', num2);
            mulRes += string(num1.size() - 1 - i, '0');
            res = add(res, mulRes);
        }
        int i = 0;
        while(i<res.size() && res[i] == '0') i++;
        if(i == res.size()) return "0";
        return res.substr(i);
    }

    string mul(int d, string num) {
        reverse(num.begin(), num.end());
        string res = "";
        int rem = 0, cur, mul;
        for(int i=0; i<num.size(); i++) {
            cur = num[i] - '0';
            mul = cur * d + rem;
            cur = mul % 10;
            rem = mul / 10;
            res.push_back(char('0' + cur));
        }
        res.push_back(char('0' + rem));
        reverse(res.begin(), res.end());
        return res;
    }
    string add(string num1, string num2) {

        if(num1.size() > num2.size()) {
            num2 = string(num1.size() - num2.size(), '0') + num2;

        }
        while(num2.size() > num1.size()) {
            num1 = string(num2.size() - num1.size(), '0') + num1;
        }

        string res = "";
        int rem = 0, cur = 0;
        for(int i=num1.size() - 1; i>=0; i--) {
            int d1 = num1[i] - '0', d2 = num2[i] - '0';
            cur = d1 + d2 + rem;
            res.push_back(char('0' + cur % 10));
            rem = cur/10;
        }
        res.push_back(char('0' + rem));
        reverse(res.begin(), res.end());

        return res;
    }
};
