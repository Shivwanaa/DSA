class Solution {
public:
vector<int>dp;
    bool check(int i,vector<int>& nums){
        if(i==nums.size()-1){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j=1;j<=nums[i];j++){
            if(check(i+j,nums)){
                return dp[i]= true;
            }
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        dp=vector<int>(nums.size()+1,-1);
        return check(0,nums);
    }
};