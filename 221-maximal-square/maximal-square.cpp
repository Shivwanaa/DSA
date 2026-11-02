class Solution {
public:
vector<vector<int>>dp;
    int check(int i,int j,vector<vector<char>>& matrix){
        if(i>=matrix.size()||j>=matrix[0].size()){
            return 0;
        }
        if(matrix[i][j]=='0'){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=check(i+1,j,matrix);
        int b=check(i,j+1,matrix);
        int c=check(i+1,j+1,matrix);
        return dp[i][j]=1+min({a,b,c});
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int side=0;
        dp=vector<vector<int>>(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    side=max(side,check(i,j,matrix));
                }
            }
        }
        return side*side;
    }
};