class Solution {
public:
vector<vector<int>>dp;
    int check(int i,int j,vector<int>& nums){
        if(j-i<3){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=1e9;
        for(int k=i+1;k<j-1;k++){
            ans=min(ans,nums[i]*nums[j-1]*nums[k]+check(i,k+1,nums)+check(k,j,nums));
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        dp=vector<vector<int>>(values.size()+1,vector<int>(values.size()+1,-1));
        return check(0,values.size(),values);
    }
};