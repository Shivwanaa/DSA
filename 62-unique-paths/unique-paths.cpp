class Solution {
public:
vector<vector<int>>mp;
    int dir[2][2]={{1,0},{0,1}};
    int check(int i,int j,int m,int n){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m ||j>=n||i<0||j<0){
            return 0;
        }
        if(mp[i][j]!=-1){
            return mp[i][j];
        }
        int ans=0;
        for(auto k:dir){
            ans=ans+check(i+k[0],j+k[1],m,n);
        }
        
        return mp[i][j]=ans;
    }
    int uniquePaths(int m, int n) {
        mp=vector<vector<int>>(m,vector<int>(n,-1));
        return check(0,0,m,n);
    }
};