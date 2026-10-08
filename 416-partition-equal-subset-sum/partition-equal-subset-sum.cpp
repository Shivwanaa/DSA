class Solution {
public:
vector<vector<int>>dp;
    bool check(int i,vector<int>& nums,int sum){
        if(sum==0){
            return true;
        }
        if(i>=nums.size()||sum<0){
            return false;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        
        return dp[i][sum]=check(i+1,nums,sum-nums[i])||check(i+1,nums,sum);

    }
    bool canPartition(vector<int>& nums) {
        int s=0;
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