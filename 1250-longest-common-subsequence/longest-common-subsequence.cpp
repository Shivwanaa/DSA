class Solution {
public:
vector<vector<int>>dp;
    int check(int i,int j,string& text1, string& text2){
        if(i>=text1.size() ||j>=text2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(text1[i]==text2[j]){
            return dp[i][j]=1+check(i+1,j+1,text1,text2);
        }
        else{
            return dp[i][j]= max(check(i+1,j,text1,text2),check(i,j+1,text1,text2));
        }
        return 0;
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp=vector<vector<int>>(text1.size(),vector<int>(text2.size(),-1));
        return check(0,0,text1,text2);
    }
};