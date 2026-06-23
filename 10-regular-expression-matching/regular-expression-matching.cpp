class Solution {
public:
vector<vector<int>>dp;
    bool check(string &s, string &p,int i,int j){
        if(i==s.size() && j==p.size()){
            return true;
        }
        if(i>s.size() || j>p.size()){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool a=((s[i]==p[j] || p[j]=='.')? true:false);
        if(j+1<p.size() && p[j+1]=='*'){
            return dp[i][j]= check(s,p,i,j+2)||(a && check(s,p,i+1,j));
        }
        else{
            if(a)
            return dp[i][j]= check(s,p,i+1,j+1);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        dp=vector<vector<int>>(s.size()+1,vector<int>(p.size()+1,-1));
        return check(s,p,0,0);
    }
};