class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> wordList) {
        int n = wordList.size(), ans = 0;
        sort(wordList.begin(), wordList.end());
        vector<bool> vis(n, false);

        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        while (q.size()) {
            auto [cur, lev] = q.front();
            q.pop();
            if(cur == endWord) return lev;

            for(int i=0; i<cur.size(); i++) {
                char curChar = cur[i];
                for(char ch='a'; ch<='z'; ch++) {
                    if(ch == cur[i]) continue;
                    cur[i] = ch;

                    int idx = binarySearch(cur, wordList);
                    if(idx != -1 && !vis[idx]) {
                        if(cur == endWord) return lev + 1;
                        q.push({cur, lev + 1});
                        vis[idx] = true;
                    }
                }
                cur[i] = curChar;
            }
        }
        return 0;
    }
private:
    int binarySearch(string& s, vector<string>& wordList) {
        int l=0, r=wordList.size() -1;
        while(l <= r) {
            int m = (l + r) / 2;
            if(wordList[m] == s) return m;
            else if(wordList[m] > s) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
};
