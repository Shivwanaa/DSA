class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<int>>m;
        map<pair<int,int>,int>cost;
        for(auto i:flights){
            m[i[0]].push_back(i[1]);
            cost[{i[0],i[1]}]=i[2];
        }
        queue<pair<int,int>>pq;
        pq.push({src,0});
        int ans=1e9;
        vector<int>dist(n,1e9);
        unordered_set<int>v;
        while(pq.size() && k>=0){
            int s=pq.size();
            for(int i=0;i<s;i++){
                auto [f,c]=pq.front();
                pq.pop();
                cout<<f<<" ";
                if(f==dst){
                    ans=min(ans,c);
                }
                for(auto i:m[f]){
                    if(c+cost[{f,i}]>=dist[i]){
                        continue;
                    }
                    dist[i]=c+cost[{f,i}];
                    pq.push({i,dist[i]});
                }
            }
            k--;
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};