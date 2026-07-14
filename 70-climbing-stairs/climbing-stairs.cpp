class Solution {
public:
vector<int>dp;
    int check(int n){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int one=check(n-1);
        int two=check(n-2);
        return dp[n]= one+two;
    }
    int climbStairs(int n) {
        dp=vector<int>(n+1,-1);
        return check(n);
    }
};