class Solution {
public:
vector<int>dp;
    bool check(int i,string s,vector<string>& wordDict){
        if(i>=s.size()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        for(auto word:wordDict){
            if(i+word.size()<=s.size() && s.substr(i,word.size())==word){
                if(check(i+word.size(),s,wordDict)){
                    return dp[i]= true;
                }
            }
        }
        return dp[i]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp=vector<int>(s.size()+1,-1);
        return check(0,s,wordDict);
    }
};