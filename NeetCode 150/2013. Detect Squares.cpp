class DetectSquares {
public:
    DetectSquares() {
        hor = ver = vector<vector<int>>(1005);
        freq = vector<vector<int>>(1005, vector<int>(1005));
    }

    void add(vector<int> point) {
        ver[point[0]].push_back(point[1]);
        freq[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int ans = 0;
        int x = point[0], y = point[1];
        for(auto &curY: ver[x]) {
            if(curY == y) continue;

            int len = abs(curY - y);
            if(x - len >= 0)
                ans += freq[x - len][curY] * freq[x - len][y];
            if(x + len <= 1000)
                ans += freq[x + len][curY] * freq[x + len][y];
        }
        return ans;
    }
private:
    vector<vector<int>> hor, ver, freq;
};
/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
