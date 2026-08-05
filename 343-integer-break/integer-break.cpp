class Solution {
public:
vector<int>dp;
    int check(int n){
        if(n==1){
            return 1;
        }
        if(dp[n]!=0){
            return dp[n];
        }
        int ans=0;
        for(int k=1;k<n;k++){
            int l=max(k,check(k));
            int r=max(n-k,check(n-k));
            ans=max(ans,l*r);
        }
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        dp=vector<int>(n+1,0);
        return check(n);
    }
};