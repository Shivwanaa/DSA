class Solution {
public:
const int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>m;
        for(auto i:roads){
            m[i[0]].push_back({i[1],i[2]});
            m[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
        q.push({0,0});
        vector<long long>noded(n,1e18);
        noded[0]=0;
        vector<long long>c(n,0);
        c[0]=1;
        while(q.size()){
            auto [dist,top]=q.top();
            q.pop();
            if(dist != noded[top])
        continue;
            for(auto i:m[top]){
                if(noded[i.first]>dist+i.second){
                    noded[i.first]=dist+i.second;
                    c[i.first]=c[top];
                    q.push({dist+i.second,i.first});
                }
                else if(dist + i.second == noded[i.first]){
                        c[i.first]=(c[i.first]+c[top])% (1000000007);
                    
                }
            }
        }
        return c[n-1];
    }
};