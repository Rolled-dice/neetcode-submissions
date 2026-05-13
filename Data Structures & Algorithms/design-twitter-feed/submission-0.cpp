class Twitter {
public:
    int globalcounter=0;
    unordered_map<int,vector<pair<int,int>>>timeWithUserIdandTweetId;
    unordered_map<int,set<int>>follow_other;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        timeWithUserIdandTweetId[userId].push_back({globalcounter++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
         vector<int>res;
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
         follow_other[userId].insert(userId);
         for(auto it:follow_other[userId]){
              for(auto post:timeWithUserIdandTweetId[it]){
                   pq.push(post);
                   if(pq.size()>10)pq.pop();
              }
         }
        
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(rbegin(res),rend(res));
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        // if(follow_other.find(followerId)!=follow_other.end()){
        follow_other[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // if(follow_other[followerId].find(followeeId)!=follow_other[followerId].end())
        if(followerId!=followeeId)
        follow_other[followerId].erase(followeeId);
    }
};
