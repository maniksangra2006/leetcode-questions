class Twitter {
public:
unordered_map<int,unordered_set <int>>follows;
unordered_map <int ,vector <pair <int, int>>> tweets;
int timer;
    Twitter() {
        timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<vector<int>> pq;
        follows[userId].insert(userId);
        for(int followee : follows[userId]){
            if(!tweets[followee].empty()){
                int idx=tweets[followee].size()-1;
                pq.push({
                    tweets[followee][idx].first,
                    tweets[followee][idx].second,
                    followee,
                    idx
                });
            }
        }
        while(!pq.empty() && feed.size()<10){
        auto top =pq.top();
        pq.pop();
        int tweetId=top[1];
        int user=top[2];
        int idx=top[3];
        feed.push_back(tweetId);

        
       if(idx>0){
        pq.push({
        tweets[user][idx-1].first,
        tweets[user][idx-1].second,
        user,
        idx-1
        });
       }
        }
    return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            follows[followerId].erase(followeeId);
        }
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