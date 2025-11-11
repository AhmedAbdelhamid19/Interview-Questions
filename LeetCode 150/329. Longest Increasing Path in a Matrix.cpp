class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        for(int i=0; i<205; i++) {
            for(int j=0; j<205; j++) dp[i][j] = -1;
        }
        n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, run(i, j, matrix));
            }
        }
        return ans;
    }
private:
    int dp[205][205], n, m;
    vector<int> dx{0,0,1,-1};
    vector<int> dy{1,-1,0,0};
    int run(int i, int j, vector<vector<int>>& matrix) {
        int &ret = dp[i][j];
        if(~ret) return ret;
        ret = 1;
        for(int d=0; d<4; d++) {
            int newI = i + dx[d], newJ = j + dy[d];
            if(newI < 0 || newJ < 0 || newI >= n || newJ >= m) continue;
            if(matrix[newI][newJ] > matrix[i][j]) {
                ret = max(ret, 1 + run(newI, newJ, matrix));
            }
        }
        return ret;
    }
};
