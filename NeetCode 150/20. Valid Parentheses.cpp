class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') stk.push(s[i]);
            else if(stk.size()==0) return 0;
            else {
                if((stk.top()=='(' && s[i]==')') || (stk.top()=='[' && s[i]==']') || (stk.top()=='{' && s[i]=='}')) {
                    stk.pop();
                } else {
                    return 0;
                }
            }
        }
        return stk.size() == 0;
    }
};
