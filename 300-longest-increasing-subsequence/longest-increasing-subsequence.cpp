class Solution {
public:
vector<vector<int>>dp;
    int check(int i,vector<int>& nums,int prev){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int p=0,np=0;
        if(prev==-1||nums[prev]<nums[i]){
            p=1+check(i+1,nums,i);
        }
        np=check(i+1,nums,prev);
        return dp[i][prev+1]=max(p,np);
    }
    int lengthOfLIS(vector<int>& nums) {
        dp=vector<vector<int>>(nums.size()+1,vector<int>(nums.size()+1,-1));
        return check(0,nums,-1);
    }
};