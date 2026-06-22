class Solution {
public:
vector<vector<int>>dp;
    int check(string &word1, string& word2,int i,int j){
        if(i==word1.size()){
            return word2.size()-j;
        }
        if(j==word2.size()){
            return word1.size()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i<word1.size() && j<word2.size() && word1[i]==word2[j]){
            return dp[i][j]=check(word1,word2,i+1,j+1);
        }
        int a=1+check(word1,word2,i+1,j);
        int b=1+check(word1,word2,i,j+1);
        return dp[i][j]= min(a,b);
    }
    int minDistance(string word1, string word2) {
        dp=vector<vector<int>>(word1.size()+1,vector<int>(word2.size()+1,-1));
        return check(word1,word2,0,0);
    }
};