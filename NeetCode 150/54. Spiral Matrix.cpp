class Solution {
#define MARKED 1e9
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans;
        if(n == 1) return matrix[0];
        if(m == 1) {
            for(int i=0; i<n; i++) ans.push_back(matrix[i][0]);
            return ans;
        }

        int dx[4] = {+0, +1, +0, -1};
        int dy[4] = {+1, +0, -1, +0};
        int d = 0, i=0, j=0, cnt = 0;
        while(cnt != 2) {
            if(!cnt) {
                ans.push_back(matrix[i][j]);
                matrix[i][j] = MARKED;
            }

            int newI = i + dx[d], newJ = j + dy[d];
            if(newI >= 0 && newI < n && newJ >= 0 && newJ < m && matrix[newI][newJ] != MARKED) {
                i = newI, j = newJ;
                cnt = 0;
            } else {
                cnt++;
                d = (d + 1) % 4;
            }
        }

        return ans;
    }
};
