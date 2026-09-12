class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>m;
        for(auto i:times){
            m[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        vector<int>d(n+1,1e9);
        d[k]=0;
        while(q.size()){
            auto[t,node]=q.top();
            q.pop();
            if(d[node]<t){
                continue;
            }
            for(auto i:m[node]){
                if(d[i.first]>d[node]+i.second){
                    d[i.first]=d[node]+i.second;
                    q.push({d[node]+i.second,i.first});
                }
            }
        }
        int ans=0;
        for(int i=1;i<d.size();i++){
            ans=max(ans,d[i]);
        }
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};