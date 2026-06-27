class Solution {
public:
vector<vector<int>>dp;
    int check(vector<int>& nums,int i,int j){
        if(j-i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int best=-1e9;
        for(int k=i;k<=j;k++){
            int tot=nums[i-1]*nums[j+1]*nums[k]+check(nums,i,k-1)+check(nums,k+1,j);
            best=max(best,tot);
        }
        return dp[i][j]=best;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        dp=vector<vector<int>>(nums.size(),vector<int>(nums.size(),-1));
        return check(nums,1,nums.size()-2);
    }
};