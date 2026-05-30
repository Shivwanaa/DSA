class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>m(n);
        const int MOD = 1e9 + 7;
        for(auto i:roads){
            m[i[0]].push_back({i[1],i[2]});
            m[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>q;
        int ans=0;
        q.push({0,0});
        vector<long long>dist(n,LLONG_MAX);
        vector<int>c(n,0);
        dist[0]=0;
        c[0]=1;
        while(q.size()){
            auto [t,f]=q.top();
            q.pop();
            if(dist[f]<t){
                continue;
            }
            for(auto i:m[f]){
                if(dist[i.first]>t+i.second){
                    dist[i.first]=t+i.second;
                    c[i.first]=c[f];
                   q.push({i.second+t,i.first});
                }
                else if(t+i.second==dist[i.first]){
                    c[i.first]=(c[i.first]+c[f])%MOD;
                }
            }
        }
        return c[n-1];
    }
};