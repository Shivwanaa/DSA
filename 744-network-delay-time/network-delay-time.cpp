class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_set<int>v;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        unordered_map<int,vector<pair<int,int>>>m;
        for(auto i:times){
            m[i[0]].push_back({i[1],i[2]});
        }
        q.push({0,k});
        
        int ans=0;
        while(q.size()){
            auto[d,node]=q.top();
            q.pop();
            if(v.count(node)){
                continue;
            }
            v.insert(node);
            ans=max(ans,d);
            for(auto i:m[node]){
                if(!v.count(i.first)){
                q.push({d+i.second,i.first});
                }
            }
        }

        if(v.size()==n)
        return ans;
        return -1;
    }
};