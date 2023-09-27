
class Twitter {
public:
    unordered_map<int,unordered_set<int>> frnds;
    unordered_map<int,vector<pair<int,int>>> tweets;
    int k;
    Twitter() {
        k = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({k, tweetId});
        k++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>> maxHeap;
        for (auto frnd: frnds[userId]) {
            for (int j = 0 ; j < tweets[frnd].size() ; j++) {
                maxHeap.push(tweets[frnd][j]);
            }
        }
        for (int i = 0 ; i < tweets[userId].size() ; i++) {
            maxHeap.push(tweets[userId][i]);
        }
        vector<int> result;
        int count = 0;
        while (!maxHeap.empty() && count < 10) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        frnds[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        frnds[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */