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
        int one=cost[i]+check(cost,i+1);
        int two=cost[i]+check(cost,i+2);
        return dp[i]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp=vector<int>(cost.size(),-1);
        return min(check(cost,0),check(cost,1));
    }
};