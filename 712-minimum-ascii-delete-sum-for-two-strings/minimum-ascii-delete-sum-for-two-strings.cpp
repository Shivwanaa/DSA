class Solution {
public:
vector<vector<int>>m;
    int check(string &s1, string &s2,int i,int j){
        if(i>s1.size() ||j>s2.size()){
            return 1e9;
        }
        if(i==s1.size() && j==s2.size()){
            return 0;
        }
        int nodel=1e9,del1=1e9,del2=1e9;
        if(m[i][j]!=-1){
            return m[i][j];
        }
        if(s1[i]==s2[j]){
        nodel=check(s1,s2,i+1,j+1);
        }
        del1=int(s1[i])+check(s1,s2,i+1,j);
        del2=int(s2[j])+check(s1,s2,i,j+1);
        m[i][j]= min({nodel,del1,del2});
        return m[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
        m=vector<vector<int>>(s1.size()+1,vector<int>(s2.size()+1,-1));
        return check(s1,s2,0,0);
    }
};