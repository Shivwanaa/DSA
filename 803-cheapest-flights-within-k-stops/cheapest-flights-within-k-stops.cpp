class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>m;
        for(auto i:flights){
            m[i[0]].push_back({i[1],i[2]});
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        unordered_set<int>v;
        int ans=1e9;
        k=k+2;
        vector<int>dist(n,1e9);
        while(q.size() && k){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto[node,cost]=q.front();
                q.pop();
                if(node==dst){
                ans=min(ans,cost);
            }
                for(auto i:m[node]){
                    if(dist[i.first]<cost+i.second){
                        continue;
                    }
                    dist[i.first]=cost+i.second;
                    q.push({i.first,i.second+cost});
                }
            }
            k--;
        }
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};