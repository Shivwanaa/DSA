class Solution {
public:
vector<int>dp;
    int check(vector<int>& cost,int i){
        if(i>=cost.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int on=cost[i]+check(cost,i+1);
        int two=cost[i]+check(cost,i+2);
        dp[i]= min({on,two});
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp=vector<int>(cost.size()+1,-1);
        return min(check(cost,0),check(cost,1));
    }
};