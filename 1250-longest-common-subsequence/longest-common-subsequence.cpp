class Solution {
public:
vector<vector<int>>m;
    int check(string &text1, string &text2,int i,int j){
        if(i==text1.size() && j==text2.size()){
            return 0;
        }
        if(i>=text1.size() ||j>=text2.size()){
            return 0;
        }
        if(m[i][j]!=-1){
            return m[i][j];
        }
        int ans=0;
        if(text1[i]==text2[j]){
            ans=1+check(text1,text2,i+1,j+1);
        }
        else{
            ans=ans+max(check(text1,text2,i+1,j),check(text1,text2,i,j+1));
        }
        m[i][j]=ans;
        return m[i][j];

    }
    int longestCommonSubsequence(string text1, string text2) {
        m=vector<vector<int>>(text1.size()+1,vector<int>(text2.size()+1,-1));
        return check(text1,text2,0,0);
    }
};