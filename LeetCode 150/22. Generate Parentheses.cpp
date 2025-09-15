
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        vector<char> stk;
        backtrack(stk, 0, 0, n);

        return ans;
    }
    void backtrack(vector<char>& stk, int curOpen, int totOpen, int& n) {
        if(stk.size() == n * 2) {
            string s = "";
            while(s.size() != n * 2) {
                s.push_back(stk[s.size()]);
            }
            ans.push_back(s);
            return;
        }
        if(totOpen == n) {
            stk.push_back(')');
            backtrack(stk, curOpen - 1, totOpen, n);
            stk.pop_back();
            return;
        }

        stk.push_back('(');
        backtrack(stk, curOpen + 1, totOpen + 1, n);
        stk.pop_back();

        if(curOpen > 0) {
            stk.push_back(')');
            backtrack(stk, curOpen - 1, totOpen, n);
            stk.pop_back();
        }
        
        return;
    }
};
