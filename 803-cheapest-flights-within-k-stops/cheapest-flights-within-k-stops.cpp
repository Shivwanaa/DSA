class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
        q.push({0,src,k+1});
        unordered_map<int,vector<pair<int,int>>>m;
        for(auto i:flights){
            m[i[0]].push_back({i[1],i[2]});
        }
        vector<vector<int>>dist(n,vector<int>(k+2,1e9));
        while(q.size()){
            auto[d,node,rem]=q.top();
            q.pop();
            if(node==dst){
                return d;
            }
            if(rem<=0 || dist[node][rem]<d){
                continue;
            }
            if(dist[node][rem]>d){
                dist[node][rem]=d;
            }
            for(auto i:m[node]){
                if(dist[i.first][rem-1]>d+i.second){
                    dist[i.first][rem-1]=d+i.second;
                q.push({d+i.second,i.first,rem-1});
                }
            }
        }
        return -1;
    }
};