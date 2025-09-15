class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> st1, st2;
        int cnt1 = 0, cnt2 = 0;
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] != '.') {
                    st1.insert(board[i][j]);
                    cnt1++;
                }
                if(board[j][i] != '.') {
                    st2.insert(board[j][i]);
                    cnt2++;
                }
            }
            if(cnt1 != st1.size() || (cnt2 != st2.size()))
                return 0;
            st1.clear(), st2.clear();
            cnt1 = cnt2 = 0;
        }
        for(int i=0; i<9; i+=3) {
            for(int j=0; j<9; j+=3) {
                for(int k=0; k<3; k++) {
                    for(int l=0; l<3; l++) {
                        if(board[i+k][j+l] != '.') {
                            st1.insert(board[i+k][j+l]);
                            cnt1++;
                        }
                    }
                }
                if(cnt1 != st1.size())
                    return 0;
                st1.clear();
                cnt1 = 0;
            }
        }
        return 1;
    }
};
