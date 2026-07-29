class Solution {
public:
vector<vector<int>>dp;
    int check(int num,int n){
        if(num<=0){
            return 1e9;
        }
        if(n<0){
            return 1e9;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][num]!=-1){
            return dp[n][num];
        }
        int a=1e9,b=1e9;
        if(num*num<=n)
        a=1+check(num,n-num*num);
        b=check(num-1,n);
        return dp[n][num]=min({a,b});
    }
    int numSquares(int n) {
        int num = sqrt(n);
        dp=vector<vector<int>>(n+1,vector<int>(num+1,-1));
        return check(num,n);
    }
};
