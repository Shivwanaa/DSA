class Solution {
public:
vector<int>dp;
    int check(int i,vector<int>& nums){
        if(i>=nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=1e9;
        for(int j=0;j<nums[i];j++){
            ans=min(ans,1+check(i+j+1,nums));
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        dp=vector<int>(nums.size()+1,-1);
        return check(0,nums);
    }
};