class Solution {
public:
    long long nCr(int n, int r) {
        if (r > n - r) r = n - r; // take smaller r
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

    int uniquePaths(int m, int n) {
        return nCr(m + n - 2, m - 1);
    }
};
