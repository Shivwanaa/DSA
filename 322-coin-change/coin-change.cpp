class Solution {
public:
vector<vector<int>>dp;
    int check(vector<int>& coins, int amount,int i){
        if(amount==0){
            return 0;
        }
        if(i==coins.size()||amount<0){
            return 1e9;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int a=1+check(coins,amount-coins[i],i);
        int b=check(coins,amount,i+1);
        return dp[i][amount]= min(a,b);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp=vector<vector<int>>(coins.size()+1,vector<int>(amount+1,-1));
        int ans=check(coins,amount,0);
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};