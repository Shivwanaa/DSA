class Twitter {
public:
unordered_map<int,vector<pair<int,int>>>tweets;
int ord=0;
unordered_map<int,unordered_set<int>>fr;
    Twitter() {
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({ord,tweetId});
        ord++;
    }
    vector<int> getNewsFeed(int userId) { 
        priority_queue<pair<int,int>>q;
        vector<int>ans;
        
        for(auto i:tweets[userId]){
            q.push({i.first,i.second});
        }
        for(auto i:fr[userId]){
            for(auto j:tweets[i]){
                q.push({j.first,j.second});
            }
        }
        int len=10;
        while(q.size() && len){
            auto [ord,tid]=q.top();
            q.pop();
            ans.push_back(tid);
            len--;
        }
        return ans;
    }
    void follow(int followerId, int followeeId) {
        fr[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) { 
        fr[followerId].erase(followeeId);
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