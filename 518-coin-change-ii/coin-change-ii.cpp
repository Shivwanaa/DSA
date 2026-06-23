class Solution {
public:
vector<vector<int>>dp;
    int check(int amount, vector<int>& coins,int i){
        if(amount==0){
            return 1;
        }
        if(amount<0||i==coins.size()){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        return dp[i][amount]=check(amount-coins[i],coins,i)+check(amount,coins,i+1);
    }
    int change(int amount, vector<int>& coins) {
        dp=vector<vector<int>>(coins.size()+1,vector<int>(amount+1,-1));
        return check(amount,coins,0);
    }
};