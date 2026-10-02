class Solution {
public:
vector<vector<int>>dp;
    bool check(int i,vector<int>& nums,int target){
        if(target==0){
            return true;
        }
        if(i>=nums.size()||target<0){
            return false;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        return dp[i][target]=check(i+1,nums,target-nums[i])||check(i+1,nums,target);
    }
    bool canPartition(vector<int>& nums) {
        int s=0;
        dp=vector<vector<int>>(nums.size()+1,vector<int>(+1,-1));
        for(int i=0;i<nums.size();i++){
            s=s+nums[i];
        }
        if(s%2!=0){
            return false;
        }
        dp=vector<vector<int>>(nums.size()+1,vector<int>(s/2+1,-1));
        return check(0,nums,s/2);
    }
};