class Solution {
public:
vector<vector<vector<int>>>dp;
    int check(int k, vector<int>& prices,int i,bool buy){
        if(i==prices.size()||k==0){
            return 0;
        }
        if(dp[i][k][buy]!=-1){
            return dp[i][k][buy];
        }
        int nothing=check(k,prices,i+1,buy);
        int b=0,s=0;
        if(buy && k){
            b=-prices[i]+check(k,prices,i+1,false);
            dp[i][k][buy]= max(b,nothing);
        }
        else{
            s=prices[i]+check(k-1,prices,i+1,true);
            dp[i][k][buy]= max(s,nothing);
        }
        return dp[i][k][buy];
    }
    int maxProfit(int k, vector<int>& prices) {
        dp=vector<vector<vector<int>>>(prices.size()+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return check(k,prices,0,true);
    }
};