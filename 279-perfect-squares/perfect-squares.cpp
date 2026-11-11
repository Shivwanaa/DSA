class Solution {
public:
vector<int>dp;
    int check(int n){
        if(n==0){
            return 0;
        }

        if(n<0){
            return 1e9;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=1e9;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+check(n-i*i));
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        dp=vector<int>(n+1,-1);
        return check(n);
    }
};