class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(x == 0 || x == 1) return x;

        double ans = 1;
        while(n > 1 || n < -1) {
            if(n & 1) ans *= x;
            x *= x;
            n /= 2;
        }
        ans *= x;
        return n < 0 ? 1 / ans : ans;
    }
};
