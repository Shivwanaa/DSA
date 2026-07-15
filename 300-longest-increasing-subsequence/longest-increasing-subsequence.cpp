class Solution {
public:
vector<vector<int>>dp;
    int check(int i,int j,vector<int>&nums){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][j+1]!=-1){
            return dp[i][j+1];
        }
        int p=0,np=0;
        if(j==-1 || nums[i]>nums[j])
        p=1+check(i+1,i,nums);
        np=check(i+1,j,nums);
        return dp[i][j+1]= max(p,np);
    }
    int lengthOfLIS(vector<int>& nums) {
        dp=vector<vector<int>>(nums.size()+1,vector<int>(nums.size()+1,-1));
        return check(0,-1,nums);
    }
};