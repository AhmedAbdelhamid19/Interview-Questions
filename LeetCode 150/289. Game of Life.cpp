class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int cnt = 0;
                if (i - 1 >= 0) {
                    cnt += board[i-1][j];
                    if (j - 1 >= 0) cnt += board[i-1][j-1];
                    if (j + 1 < m) cnt += board[i-1][j+1];
                }
                if (i + 1 < n) {
                    cnt += board[i+1][j];
                    if (j - 1 >= 0) cnt += board[i+1][j-1];
                    if (j + 1 < m) cnt += board[i+1][j+1];
                }
                if (j - 1 >= 0) cnt += board[i][j-1];
                if (j + 1 < m) cnt += board[i][j+1];
                
                if (board[i][j]) {
                    ans[i][j] = cnt == 2 || cnt == 3;
                }
                else {
                    ans[i][j] = cnt == 3;
                }
            }
        }
        board = ans;
    }
};
