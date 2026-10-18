class Solution {
public:
vector<vector<int>>dp;
    int check(int i,int j,vector<vector<int>>& triangle){
        if(i==triangle.size()){
            return 0;
        }
        if(j>=triangle[i].size()){
            return 1e9;
        }
        if(dp[i][j]!=1e9){
            return dp[i][j];
        }
        int l=0,r=0;
        l=triangle[i][j]+check(i+1,j,triangle);
        r=triangle[i][j]+check(i+1,j+1,triangle);

        return dp[i][j]=min(l,r);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp=vector<vector<int>>(triangle.size()+1,vector<int>(triangle[triangle.size()-1].size()+1,1e9));
        return check(0,0,triangle);
    }
};