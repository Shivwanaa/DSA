class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,1e9);
        dist[src]=0;
        for(int i=0;i<=k;i++){
            vector<int>temp=dist;
            for(auto j:flights){
                int a=j[0];
                int b=j[1];
                int c=j[2];
                if(dist[a]==1e9){
                    continue;
                }
                if(dist[a]+c<temp[b]){
                    temp[b]=dist[a]+c;
                }
            }
            dist=temp;
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};