class Solution {
public:
vector<int>dp;
    int check(int n){
        if(n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,i*check(n-i));
            ans=max(ans,i*(n-i));
        }
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        dp=vector<int>(n+1,-1);
        return check(n);
    }
};