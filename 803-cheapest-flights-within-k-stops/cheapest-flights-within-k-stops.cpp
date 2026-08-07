class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<int>>dist(n,vector<int>(k+2,1e9));
        queue<int>q;
        unordered_map<int,vector<pair<int,int>>>m;
        for(auto i:flights){
            m[i[0]].push_back({i[1],i[2]});
        }
        pq.push({0,src,k+1});
        int ans=1e9;
        while(pq.size()){
            auto[a,b,c]=pq.top();
            pq.pop();
            if(b==dst){
                return a;
            }
            if(c<=0 || dist[b][c]<a){
                continue;
            }
            if(dist[b][c]>a){
            dist[b][c]=a;
            }

            for(auto i:m[b]){
                if(dist[i.first][c-1]>a+i.second){
                    dist[i.first][c-1]=a+i.second;
                pq.push({a+i.second,i.first,c-1});
                }
            }
        }
        if(ans==1e9) return -1;
        return ans;
    }
};