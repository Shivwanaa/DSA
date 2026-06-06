class Solution {
public:
vector<vector<vector<int>>>dp;
    int check(int i,unordered_map<int,pair<int,int>>&count,vector<string>& strs,int m,int n){
        if(m<0 ||n<0){
            return -1e9;
        }
        if(i==strs.size() ){
            return 0;
        }
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        int take=check(i+1,count,strs,m,n);
        int nottake=1+check(i+1,count,strs,m-count[i].first,n-count[i].second);
        dp[i][m][n]= max(take,nottake);
        return dp[i][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        unordered_map<int,pair<int,int>>count;
        for(int i=0;i<strs.size();i++){
            int o=0,z=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='1'){
                    o++;
                }
                else if(strs[i][j]=='0'){
                    z++;
                }
            }
            count[i]={z,o};
        }
        dp = vector<vector<vector<int>>>(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return check(0,count,strs,m,n);
    }
};