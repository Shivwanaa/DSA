class Solution {
public:
vector<vector<int>>dp;
    int check(int i,vector<int>& coins, int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0||i>=coins.size()){
            return 1e9;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int p=1+check(i,coins,amount-coins[i]);
        int np=check(i+1,coins,amount);
        return dp[i][amount]=min(p,np);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp=vector<vector<int>>(coins.size()+1,vector<int>(amount+1,-1));
        int ans= check(0,coins,amount);
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};