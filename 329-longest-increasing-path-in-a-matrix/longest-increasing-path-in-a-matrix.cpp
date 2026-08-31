class Solution {
public:
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
vector<vector<int>>dp;;
    int check(int i,int j,vector<vector<int>>& matrix){
        if(i<0||j<0||i>=matrix.size()||j>=matrix[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        for(auto k:dir){
            int nr=k[0]+i;
            int nc=k[1]+j;
            if(nr>=0 && nr<matrix.size()&& nc>=0 && nc<matrix[0].size()){
                if(matrix[i][j]<matrix[nr][nc]){
                    ans=max(ans,1+check(nr,nc,matrix));
                }
            }
        }
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
        return ans+1;
    }
};