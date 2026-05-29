class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // set<pair<int,int>>r;
        // set<pair<int,int>>b;
        unordered_map<int,vector<int>>red;
        unordered_map<int,vector<int>>blue;
        for(int i=0;i<n;i++){
            red[i]={};
            blue[i]={};
        }
        for(auto i:redEdges){
            red[i[0]].push_back(i[1]);
            // r.insert({i[0],i[1]});
        }
        for(auto i:blueEdges){
            blue[i[0]].push_back(i[1]);
            // b.insert({i[0],i[1]});
        }
        auto comp=[](pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
            return a.second.first>b.second.first;
        };
        set<pair<int,int>>v;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,decltype(comp)>q(comp);
        q.push({0,{0,0}});
        vector<int>dist(n,1e9);
        while(q.size()){
            pair<int,pair<int,int>>p=q.top();
            q.pop();
            if(v.count({p.first,p.second.second})){
                continue;
            }
            v.insert({p.first,p.second.second});
            dist[p.second.second]=min(dist[p.second.second],p.second.first);
            if(p.first==0||p.first==-1){
            for(auto i:red[p.second.second]){
                q.push({1,{p.second.first+1,i}});
            }
            }
            if(p.first==0||p.first==1){
            for(auto i:blue[p.second.second]){
                q.push({-1,{p.second.first+1,i}});
            }
            }
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
    }
};