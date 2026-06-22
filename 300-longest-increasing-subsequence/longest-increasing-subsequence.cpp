class Solution {
public:
vector<vector<int>>dp;
    int check(vector<int>& nums,int i,int prev){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int a=0,b=0,c=0;
        if(prev==-1||nums[prev]<nums[i]){
            a=1+check(nums,i+1,i);
        }
        c=check(nums,i+1,prev);
        dp[i][prev+1]= max(a,c);
        return dp[i][prev+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        dp=vector<vector<int>>(nums.size()+1,vector<int>(nums.size()+1,-1));
        return check(nums,0,-1);
    }
};