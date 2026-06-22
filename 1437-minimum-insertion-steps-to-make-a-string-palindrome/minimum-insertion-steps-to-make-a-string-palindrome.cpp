class Solution {
public:
vector<vector<int>>dp;
    int check(string& s,int i,int j){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return dp[i][j]=check(s,i+1,j-1);
        }
        int f=0,b=0;
        f=1+check(s,i,j-1);
        b=1+check(s,i+1,j);
        return dp[i][j]= min(f,b);
    }
    int minInsertions(string s) {
        dp=vector<vector<int>>(s.size()+1,vector<int>(s.size()+1,-1));
        return check(s,0,s.size()-1);
    }
};