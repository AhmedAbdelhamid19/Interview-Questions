class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<bool> v(n);
        for(int i=0; i<n; i++) {
            bool flag = true;
            for(int j=0; j<3; j++) {
                if(triplets[i][j] > target[j]) flag = false;
            }
            v[i] = flag;
        }
        vector<int> res(3);
        for(int i=0; i<n; i++) {
            if(v[i]) {
                for(int j=0; j<3; j++) {
                    res[j] = max(res[j], triplets[i][j]);
                }
            }
        }
        for(int i=0; i<3; i++) {
            if(res[i] != target[i]) return false;
        }
        return true;
    }
};
