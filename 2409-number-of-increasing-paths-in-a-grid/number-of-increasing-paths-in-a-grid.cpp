class Solution {
public:
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
vector<vector<int>>dp;
const int MOD = 1e9 + 7;
    int check(int i,int j,vector<vector<int>>& grid){
        long long ans=1;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(auto k:dir){
            int ni=i+k[0];
            int nj=j+k[1];
            if(ni<0||nj<0||ni>=grid.size()||nj>=grid[0].size()){
                continue;
            }
            if(grid[ni][nj]>grid[i][j]){
                ans=(ans+check(ni,nj,grid))%MOD;
            }
        }
        return dp[i][j]=ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        long long ans=0;
        dp=vector<vector<int>>(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                // cout<<check(i,j,grid)<<endl;
                ans=(ans+check(i,j,grid))%MOD;
            }
        }
        return ans;
    }
};