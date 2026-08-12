class Solution {
public:
vector<vector<vector<int>>>dp;
const int mod=1e9+7;
    int check(int i,int n,int minProfit, vector<int>& group, vector<int>& profit){
        if(n<0){
            return 0;
        }
        if(i>=group.size()){
            if(minProfit<=0){
                return 1;
            }
            return 0;
        }
        if(dp[i][n][minProfit]!=-1){
            return dp[i][n][minProfit];
        }
        int p=check(i+1,n-group[i],max(0,minProfit-profit[i]),group,profit);
        int np=check(i+1,n,minProfit,group,profit);
        return dp[i][n][minProfit]=(p+np)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        dp=vector<vector<vector<int>>>(group.size()+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));

        return check(0,n,minProfit,group,profit);
    }
};