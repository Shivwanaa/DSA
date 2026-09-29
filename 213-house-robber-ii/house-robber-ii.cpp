class Solution {
public:
vector<int>dp1;
vector<int>dp2;
    int check(int i,int end,vector<int>nums,vector<int>&dp){
        if(i>=end){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int p=nums[i]+check(i+2,end,nums,dp);
        int np=check(i+1,end,nums,dp);
        return dp[i]= max(p,np);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        dp1=vector<int>(nums.size()+1,-1);
        dp2=vector<int>(nums.size()+1,-1);
        int a=check(0,nums.size()-1,nums,dp1);
        int b=check(1,nums.size(),nums,dp2);
        return max(a,b);

    }
};