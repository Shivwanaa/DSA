class Solution {
public:
vector<vector<int>>dp;
    int check(string &text1, string &text2,int i,int j){
        if(i>=text1.size() || j>=text2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(text1[i]==text2[j]){
            return dp[i][j]= 1+check(text1,text2,i+1,j+1);
        }
        
        else{
            return dp[i][j]= max(check(text1,text2,i+1,j),check(text1,text2,i,j+1));
        }
        return 0;
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp=vector<vector<int>>(text1.size()+1,vector<int>(text2.size()+1,-1));
        return check(text1,text2,0,0);
    }
};