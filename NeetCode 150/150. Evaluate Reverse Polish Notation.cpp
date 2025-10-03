class Solution {
public:
    int evalRPN(vector<string> tokens) {
        stack<int> stk;
        for(auto &it: tokens) {
            if((it[0] >= '0' && it[0] <= '9') || it.size() > 1) {
                stk.push(stoi(it));
            } else {
                int num2 = stk.top(); stk.pop();
                int num1 = stk.top(); stk.pop();
                int res;
                if(it == "*") res = num1 * num2;
                else if(it == "-") res = num1 - num2;
                else if(it == "+") res = num1 + num2;
                else res = num1 / num2;
                stk.push(res);
            }
        }
        return stk.top();
    }
};
