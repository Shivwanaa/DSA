class Solution {
public:
vector<int>dp;
    int check(int i, string &s){
        if(i>=s.size()){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=0,two=0,num=0;
        if(s[i]!='0'){
            one=check(i+1,s);
        }
        if(i+1<s.size()){
        num=(s[i]-'0')*10+(s[i+1]-'0');
        if(num>=10 && num<=26)
        two=check(i+2,s);
        }
        return dp[i]=one+two;
    }
    int numDecodings(string s) {
        if(s.size() && s[0]=='0'){
            return 0;
        }
        dp=vector<int>(s.size()+1,-1);
        return check(0,s);
    }
};