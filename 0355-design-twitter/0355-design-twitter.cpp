class Twitter {
public:

    int timeStamp = 0;
    unordered_map<int,vector<pair<int,int>>>userTweets;
    unordered_map<int,unordered_set<int>>followedBy;

    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {

        userTweets[userId].push_back({timeStamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        followedBy[userId].insert(userId);

        vector<int>feeds;

        priority_queue<tuple<int,int,int,int>>pq;  // timeStamp - tweetId - userId - i(index of last elemnt in vector<pair<int,int>> of userTweet (merge k sorted array concept))

        for(int id : followedBy[userId])
        {
            auto& vec = userTweets[id];

            int i=vec.size()-1;

            if(vec.size()>0)
            {
                pq.push({vec[i].first,vec[i].second,id,i});
            }
        } 

        int totalFeed=0;

        while(!pq.empty() && totalFeed<10)
        {
            auto [t,tId,uId,i] = pq.top(); pq.pop();

            feeds.push_back(tId);

            totalFeed+=1;

            auto& vec = userTweets[uId];

            if(i>0)
            {
                pq.push({vec[i-1].first,vec[i-1].second,uId,i-1});
            }
        }
        
        return feeds;
      
    }
    
    void follow(int followerId, int followeeId) {
         
         if(followerId!=followeeId)
         {
            followedBy[followerId].insert(followeeId);
         }
         
    }
    
    void unfollow(int followerId, int followeeId) {

        if(followerId!=followeeId)
        {

            followedBy[followerId].erase(followeeId);
            
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