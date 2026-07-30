class Solution {
public:
vector<vector<int>>dp;
    int check(int i,int j,vector<int>& nums){
        if(j-i<1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        for(int k=i+1;k<j;k++){
            ans=max(ans,nums[i]*nums[k]*nums[j]+check(i,k,nums)+check(k,j,nums));
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        dp=vector<vector<int>>(nums.size()+1,vector<int>(nums.size()+1,-1));
        return check(0,nums.size()-1,nums);
    }
};