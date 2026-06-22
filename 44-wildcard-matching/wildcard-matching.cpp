class Solution {
public:
vector<vector<int>>dp;
    bool check(string& s, string& p,int i,int j){
        if(i==s.size() && j==p.size()){
            return true;
        }
        if(j==p.size()){
            return false;
        }
        bool m=false;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(p[j]=='*'){
            return dp[i][j]=check(s,p,i,j+1)||(i<s.size() && check(s,p,i+1,j));
        }
        else if(i<s.size() &&(s[i]==p[j] || p[j]=='?')){
            m=check(s,p,i+1,j+1);
        }
        dp[i][j]=m;
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        dp=vector<vector<int>>(s.size()+1,vector<int>(p.size()+1,-1));
        return check(s,p,0,0);
    }
};