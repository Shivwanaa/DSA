class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> q;
        map<int,vector<pair<int,int>>>m;
        for(auto i:times){
            m[i[0]].push_back({i[1],i[2]});
        }
        unordered_set<int>v;
        
        q.push({0,k});
        int ans=0;
        while(q.size()){
            auto [t,k]=q.top();
            q.pop();
            if(v.count(k)){
                continue;
            }
            v.insert(k);
            ans=max(ans,t);
            for(auto i:m[k]){
                q.push({t+i.second,i.first});
            }
        }
        if(v.size()==n){
            return ans;
        }
        return -1;
    }
};