class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        unordered_map<int,vector<pair<int,int>>>m;
        for(auto i:times){
            m[i[0]].push_back({i[1],i[2]});
        }
        q.push({0,k});
        unordered_set<int>v;
        int ans=0;
        while(q.size()){
            auto[time,node]=q.top();
            q.pop();
            if(v.count(node)){
                continue;
            }
            ans=max(ans,time);
            v.insert(node);
            for(auto i:m[node]){
                q.push({time+i.second,i.first});
            }
        }
        if(v.size()==n){
            return ans;
        }
        return -1;
    }
};