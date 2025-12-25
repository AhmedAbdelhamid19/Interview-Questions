class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size(), i = 0;

        vector<string> v;
        while (i < n) {
            while (i < n && path[i] == '/') i++;

            string cur = "";
            while (i < n && path[i] != '/') cur.push_back(path[i++]);

            if (cur == "..") {
                if (v.size()) v.pop_back();
            } else if (cur == ".") {
                continue;
            } else if (cur.size()) {
                v.push_back(cur);
            }
        }

        string ans = "/";
        for (int i=0; i<v.size(); i++) {
            ans += v[i];
            if (i < v.size() - 1) ans += "/";
        }

        return ans;
    }
};
