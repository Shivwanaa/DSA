class Twitter {
public:
unordered_map<int,unordered_set<int>>friends;
unordered_map<int,vector<pair<int,int>>>posts;
int t=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({t,tweetId});
        t++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        friends[userId].insert(userId);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(auto i:friends[userId]){
            for(auto j:posts[i]){
                q.push({j.first,j.second});
                if(q.size()>10){
                    q.pop();
                }
            }
        }
        while(q.size()){
            ans.push_back(q.top().second);
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
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