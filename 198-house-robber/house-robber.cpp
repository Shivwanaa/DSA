class Solution {
public:
vector<int>dp;
    int check(int i,vector<int>& nums){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int p=nums[i]+check(i+2,nums);
        int np=check(i+1,nums);
        return dp[i]=max(p,np);
    }
    int rob(vector<int>& nums) {
        dp=vector<int>(nums.size()+1,-1);
        return check(0,nums);
    }
};