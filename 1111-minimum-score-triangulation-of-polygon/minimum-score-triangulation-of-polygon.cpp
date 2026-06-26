class Solution {
public:
vector<vector<int>>dp;
    int check(vector<int>& values,int i,int j){
        if(i>=j){
            return 0;
        }
        if(j-i<2){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=1e9;
        for(int k=i+1;k<j;k++){
            int tot=values[i]*values[k]*values[j]+check(values,i,k)+check(values,k,j);
            ans=min(ans,tot);
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        dp=vector<vector<int>>(values.size(),vector<int>(values.size(),-1));
        return check(values,0,values.size()-1);
    }
};