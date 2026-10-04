class Solution {
public:
vector<int>dp;
    bool check(vector<int>& nums,int i){
        if(i>=nums.size()-1){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j=1;j<=nums[i];j++){
            if(check(nums,j+i)){
                return dp[i]= true;
            }
        }
        return dp[i]= false;
    }
    bool canJump(vector<int>& nums) {
        dp=vector<int>(nums.size()+1,-1);
        return check(nums,0);
    }
};