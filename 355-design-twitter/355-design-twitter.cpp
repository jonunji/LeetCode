class Twitter {
public:
    
    unordered_map<int, unordered_set<int>> users;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int totalTweets = 0;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) 
    {
        tweets[userId].push_back({totalTweets++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        priority_queue<pair<int, int>> pq;
        
        for (pair<int, int> tweet : tweets[userId])
            pq.push(tweet);
        
        for (int followee : users[userId])
            for (pair<int, int> tweet : tweets[followee])
                pq.push(tweet);
        
        vector<int> res;
        for (int i = 0; i < 10 && !pq.empty(); i++)
        {

            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId)
    {
        users[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        users[followerId].erase(followeeId);
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