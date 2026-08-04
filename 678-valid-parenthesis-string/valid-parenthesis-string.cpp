class Solution {
public:
vector<vector<int>>dp;
    bool check(int i,string& s,int o){
        if(i==s.size() && o==0){
            return true;
        }
        if(o<0||i>=s.size()){
            return false;
        }
        if(dp[i][o]!=-1){
            return dp[i][o];
        }
        if(s[i]=='('){
        if(check(i+1,s,o+1)){
            return dp[i][o]= true;
        }
        }
        else if(s[i]==')'){
        if(check(i+1,s,o-1)){
            return dp[i][o]= true;
        }
        }
        else if(s[i]=='*'){
            if(check(i+1,s,o+1)||check(i+1,s,o-1)||check(i+1,s,o)){
                return dp[i][o]= true;
            }
        }
        return dp[i][o]=false;
    }
    bool checkValidString(string s) {
        dp=vector<vector<int>>(s.size()+1,vector<int>(s.size()+1,-1));
        return check(0,s,0);
    }
};