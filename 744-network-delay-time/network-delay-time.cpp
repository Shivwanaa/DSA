class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>m;
        for(auto i:times){
            m[i[0]].push_back({i[1],i[2]});
        }
        auto comp=[](pair<int,int>a,pair<int,int>b){
            return a.second>b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>q(comp);
        q.push({k,0});
        int ans=-1;
        unordered_set<int>v;
        while(q.size()){
            auto [node,time]=q.top();
            q.pop();
            if(v.count(node)){
                continue;
            }
            v.insert(node);
            ans=max(ans,time);
            for(auto i:m[node]){
                q.push({i.first,time+i.second});
            }
        }
        if(v.size()==n){
            return ans;
        }
        return -1;
    }
};