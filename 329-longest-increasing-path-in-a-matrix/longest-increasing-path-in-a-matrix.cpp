class Solution {
public:
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
vector<vector<int>>dp;
const int MOD = 1e9 + 7;
    int check(int i,int j,vector<vector<int>>& matrix){
        int ans=1;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(auto k:dir){
            int ni=i+k[0],nj=j+k[1];
            if(ni<0||nj<0||ni>=matrix.size()||nj>=matrix[0].size()){
                continue;
            }
            if(matrix[i][j]<matrix[ni][nj])
            ans=max(ans,1+check(ni,nj,matrix));
        }
        // matrix[i][j]=t;
        return dp[i][j]=ans;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        dp=vector<vector<int>>(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans=max(ans,check(i,j,matrix));
            }
        }
        return ans;
    }
};