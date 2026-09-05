class Solution {
public:
vector<vector<int>>dp;
    int check(int i,int j,vector<vector<int>>& obstacleGrid){
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1){
            if(obstacleGrid[i][j]==1){
                return 0;
            }
            return 1;
        }
        if(i<0||j<0||i>=obstacleGrid.size()||j>=obstacleGrid[0].size()|| obstacleGrid[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        obstacleGrid[i][j]=1;
        int ans=0;
        ans+=check(i+1,j,obstacleGrid);
        ans+=check(i,j+1,obstacleGrid);
        obstacleGrid[i][j]=0;
        return  dp[i][j]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        dp=vector<vector<int>>(obstacleGrid.size()+1,vector<int>(obstacleGrid[0].size()+1,-1));
        return check(0,0,obstacleGrid);
    }
};