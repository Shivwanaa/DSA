class Solution {
public:
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int check(int i,int j,vector<vector<int>>& grid){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0){
            return 0;
        }
        int t=grid[i][j];
        int ans=0;
        grid[i][j]=0;
        for(auto k:dir){
            if(i+k[0]>=0 && j+k[1]>=0 && i+k[0]<grid.size() && j+k[1]<grid[0].size()){
            ans=max(ans,t+check(i+k[0],j+k[1],grid));
        }
        }
        grid[i][j]=t;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans=max(ans,check(i,j,grid));
            }
        }
        return ans;
    }
};