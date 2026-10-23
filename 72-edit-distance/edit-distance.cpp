class Solution {
public:
vector<vector<int>>dp;
    int check(int i,int j,string word1, string word2){
        if(i==word1.size() && j==word2.size()){
            return 0;
        }
        if(i==word1.size() && j<word2.size()){
            return word2.size()-j;
        }
        if(j==word2.size() && i<word1.size()){
            return word1.size()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j]=check(i+1,j+1,word1,word2);
        }
        int ins=check(i,j+1,word1,word2);
        int del=check(i+1,j,word1,word2);
        int rep=check(i+1,j+1,word1,word2);

        return dp[i][j]=1+min({ins,del,rep});
    }
    int minDistance(string word1, string word2) {
        dp=vector<vector<int>>(word1.size()+1,vector<int>(word2.size()+1,-1));
        return check(0,0,word1,word2);
    }
};