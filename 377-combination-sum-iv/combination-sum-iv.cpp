class Solution {
public:
vector<int>dp;
    int check(vector<int>& nums, int target){
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        if(dp[target]!=-1){
            return dp[target];
        }
        int ans=0;
        for(int j=0;j<nums.size();j++){
            if(target>=nums[j])
            ans+=check(nums,target-nums[j]);
        }
        return dp[target]=ans;

    }
    int combinationSum4(vector<int>& nums, int target) {
        dp=vector<int>(target+1,-1);
        return check(nums,target);
    }
};