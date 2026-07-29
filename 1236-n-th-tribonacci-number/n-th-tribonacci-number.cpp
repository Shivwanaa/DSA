class Solution {
public:
vector<int>dp;
    int check(int n){
        if(n==0){
            return 0;
        }
        if(n==1||n==2){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=check(n-1)+check(n-2)+check(n-3);
    }
    int tribonacci(int n) {
        dp.resize(n + 1, -1);
        return check(n);
    }
};