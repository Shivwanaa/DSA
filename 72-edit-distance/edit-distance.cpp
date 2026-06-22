class Solution {
public:
vector<vector<int>>dp;
    int check(string &word1, string& word2,int i,int j){
        if(i>word1.size() ||j>word2.size()){
            return 1e9;
        }
        if(j==word2.size() && i==word1.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j]= check(word1,word2,i+1,j+1);
        }
        int ins=1+check(word1,word2,i,j+1);
        int rep=1+check(word1,word2,i+1,j+1);
        int del=1+check(word1,word2,i+1,j);
        return dp[i][j]= min({ins,rep,del});
    }
    int minDistance(string word1, string word2) {
        dp=vector<vector<int>>(word1.size()+1,vector<int>(word2.size()+1,-1));
        if(word1==word2){
            return 0;
        }
        return check(word1,word2,0,0);
    }
};