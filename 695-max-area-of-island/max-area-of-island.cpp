class Solution {
public:
    int check(vector<vector<int>>& grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0){
            return 0;
        }
        grid[i][j]=0;
        int a=1;
        a=a+check(grid,i+1,j);
        a=a+check(grid,i-1,j);
        a=a+check(grid,i,j+1);
        a=a+check(grid,i,j-1);
        return a;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j])
                ans=max(ans,check(grid,i,j));
            }
        }
        return ans;
    }
};