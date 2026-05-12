class Solution {
public:
vector<vector<int>>dp;
    int check(string& s, string &t,int i,int j){
        if(j==t.size()){
            return 1;
        }
        if(i==s.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=0;
        if(s[i]==t[j]){
            a+=check(s,t,i+1,j+1);
        }
        a+=check(s,t,i+1,j);
        dp[i][j]=a;
        return a;
    }
    int numDistinct(string s, string t) {
        //now add memo
        // map<pair<int,int>,int>m;
        dp=vector<vector<int>>(s.size()+1,vector<int>(t.size()+1,-1));
        return check(s,t,0,0);
    }
};
