class Solution {
public:
vector<vector<int>>dp;
    int check(int i,int j,int m,int n){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i<0||j<0||i>=m||j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int d=check(i+1,j,m,n);
        int u=check(i,j+1,m,n);
        return dp[i][j]= d+u;
    }
    int uniquePaths(int m, int n) {
        dp=vector<vector<int>>(m,vector<int>(n,-1));
        return check(0,0,m,n);
    }
};