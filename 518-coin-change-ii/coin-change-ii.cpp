class Solution {
public:
vector<vector<int>>dp;
    int check(int i,int amount, vector<int>& coins){
        if(amount==0 && i==coins.size()){
            return 1;
        }
        if(amount<0||i>=coins.size()){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int p=check(i,amount-coins[i],coins);
        int np=check(i+1,amount,coins);
        return dp[i][amount]=p+np;
    }
    int change(int amount, vector<int>& coins) {
        dp=vector<vector<int>>(coins.size()+1,vector<int>(amount+1,-1));
        return check(0,amount,coins);
    }
};