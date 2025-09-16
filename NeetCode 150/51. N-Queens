class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        backtrack(board, 0);
        return ans;
    }

    void backtrack(vector<string>& board, int row){
        if(row == board.size()) {
            ans.push_back(board);
            return;
        }

        for(int j=0; j<board.size(); j++) {
            if(isSafe(board, row, j)) {
                board[row][j] = 'Q';
                backtrack(board, row + 1);
                board[row][j] = '.';
            }
        }
    }
    bool isSafe(vector<string>& board, int row, int col) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board.size(); j++) {
                if(board[i][j] == 'Q' && (i == row || j == col || i - row == j - col || i - row == col - j)) {
                    return false;
                }
            }
        }
        return true;
    }
};
