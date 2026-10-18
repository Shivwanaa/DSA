class Solution {
public: 
vector<vector<int>>dp;
    int check(int i,int j,vector<vector<int>>& grid){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        if(i>=grid.size()|| j>=grid[0].size()){return 1e9;}
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=grid[i][j]+check(i+1,j,grid);
        int right=grid[i][j]+check(i,j+1,grid);

        return dp[i][j]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        dp=vector<vector<int>>(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        return check(0,0,grid);
    }
};