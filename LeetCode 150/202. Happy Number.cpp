class Solution {
public:
    bool isHappy(int n) {
        map<int,int> mp;
        while(n != 1 && !mp.count(n)) {
            mp[n]++;
            int newNum = 0;
            while(n) newNum += (n % 10) * (n % 10), n /= 10;
            n = newNum;
        }
        return n == 1;
    }
};
