class Solution {
public:
vector<vector<int>>dp;
    bool check(int i,int j,int k,string s1, string s2, string s3 ){
        if(k==s3.size()){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i<s1.size() && s3[k]==s1[i]){
            if(check(i+1,j,k+1,s1,s2,s3)){
                return dp[i][j]= true;
            }
        }
        if(j<s2.size() && s3[k]==s2[j]){
            if(check(i,j+1,k+1,s1,s2,s3)){
                return dp[i][j]= true;
            }
        }
        return dp[i][j]= false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        dp=vector<vector<int>>(s1.size()+1,vector<int>(s2.size()+1,-1));
        return check(0,0,0,s1,s2,s3);
    }
};