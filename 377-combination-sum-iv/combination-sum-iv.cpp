class Solution {
public:
vector<int>dp;
    int check(int i,vector<int>& nums, int target){
        if(target==0){
            return 1;
        }
        if(i==nums.size()||target<0){
            return 0;
        }
        if(dp[target]!=-1){
            return dp[target];
        }
        int ans=0;
        for(int j=0;j<nums.size();j++){
            ans=ans+check(j,nums,target-nums[j]);
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp=vector<int>(target+1,-1);
        return check(0,nums,target);
    }
};