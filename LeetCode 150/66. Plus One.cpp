class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), rem = 1, cur;
        for(int i=n-1; i>=0; i--) {
            cur = rem + digits[i];
            digits[i] = cur % 10;
            rem = cur / 10;
        }
        if(rem) {
            digits.push_back(rem);
            for(int i=digits.size() - 1; i>0; i--) {
                swap(digits[i], digits[i - 1]);
            }
        }
        return digits;
    }
};
