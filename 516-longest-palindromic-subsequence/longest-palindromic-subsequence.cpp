class Solution {
public:
vector<vector<int>>m;
    int middle(string& s,int i,int j){
        if(i<0 ||j>=s.size()){
            return 0;
        }
        if(m[i][j]!=-1){
            return m[i][j];
        }
        if(s[i]==s[j] && i!=j){
            return m[i][j]= 2+middle(s,i-1,j+1);
        }
        if(s[i]==s[j] && i==j){
            return m[i][j]= 1+middle(s,i-1,j+1);
        }
        else{
            return m[i][j]= max(middle(s,i,j+1),middle(s,i-1,j));
        }
        return m[i][j];
    }
    int longestPalindromeSubseq(string s) {
        //subsequence
        int ans=0;
        m=vector<vector<int>>(s.size()+1,vector<int>(s.size()+1,-1));
        for(int i=0;i<s.size();i++){
            ans=max(ans,middle(s,i,i+1));
            ans=max(ans,middle(s,i,i));
        }
        return ans;
    }
};