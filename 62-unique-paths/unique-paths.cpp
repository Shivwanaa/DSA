class Solution {
public:
vector<vector<int>>map;
    int check(int i,int j,int m,int n){
        if(i>=m || j>=n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(map[i][j]!=-1){
            return map[i][j];
        }
        int p1=check(i+1,j,m,n);
        int p2=check(i,j+1,m,n);

        map[i][j]= p1+p2;
        return map[i][j];
    }
    int uniquePaths(int m, int n) {
        map=vector<vector<int>>(m,vector<int>(n,-1));
        return check(0,0,m,n);
    }
};