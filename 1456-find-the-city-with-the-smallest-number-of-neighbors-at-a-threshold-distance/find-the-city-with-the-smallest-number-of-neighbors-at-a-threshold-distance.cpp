class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i){
                    dist[i][j]=0;
                }
            }
        }
        for(auto i:edges){
            dist[i[0]][i[1]]=i[2];
            dist[i[1]][i[0]]=i[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int tempcities=1e9;
        int ans=-1;
        for(int i=0;i<n;i++){
            int a=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold){
                    a++;
                }

            }
            if(tempcities>=a){
                tempcities=a;
                ans=i;
            }
        }
        return ans;
    }
};