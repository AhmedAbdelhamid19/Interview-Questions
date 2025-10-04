class Solution {
public:
    vector<int> twoSum(vector<int> numbers, int target) {
        int n = numbers.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int idx = binarySearch(numbers, target - numbers[i], i);
            if(idx == i) {
                if(i - 1 >= 0 && numbers[i - 1] == numbers[i]) idx = i - 1;
                else if(i + 1 < n && numbers[i + 1] == numbers[i]) idx = i + 1;
                else idx = -1;
            }
            if(~idx) {
                ans = {min(i, idx) + 1, max(i, idx) + 1};
                break;
            }
        }
        return ans;
    }
private:
    int binarySearch(vector<int>& numbers, int num, int cur) {
        int l=0, r=numbers.size()-1;
        while(l <= r) {
            int m = (l + r) / 2;
            if(numbers[m] == num) return m;

            if(numbers[m] > num) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};
