class Solution {
public:
vector<vector<int>>dp;
    int check(vector<vector<int>>& pairs,int i,int j){
        if(i==pairs.size()){
            return 0;
        }
        if(dp[i][j+1]!=-1){
            return dp[i][j+1];
        }
        int take=0,nottake=0;
        if(j==-1 || pairs[i][0]>pairs[j][1]){
            take=1+check(pairs,i+1,i);
        }
        nottake=check(pairs,i+1,j);
        return dp[i][j+1]= max(take,nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        dp=vector<vector<int>>(pairs.size()+1,vector<int>(pairs.size()+1,-1));
        sort(pairs.begin(),pairs.end());
        return check(pairs,0,-1);
    }
};