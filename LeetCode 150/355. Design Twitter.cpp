
class Twitter {
public:
    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for(int i=tweets.size()-1; i>=0; i--) {
            if(ans.size() == 10) break;
            auto &[followeeId, tweetId] = tweets[i];
            if(followers[userId].find(followeeId)!=followers[userId].end() || followeeId == userId) {
                ans.push_back(tweetId);
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
private:
    unordered_set<int> followers[10005];
    vector<pair<int,int>> tweets;
};
