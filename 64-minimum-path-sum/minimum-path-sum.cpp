class Solution {
public:
    int ans=1e9;
    int check(int i,int j,vector<vector<int>>& grid,map<pair<int,int>,int>&m){
        if( i<0|| j<0|| i>=grid.size() || j>=grid[0].size()){
            return 1e9;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        if(m.count({i,j})){
            return m[{i,j}];
        }
        int a=check(i+1,j,grid,m);
        int b=check(i,j+1,grid,m);
        m[{i,j}]= grid[i][j]+min(a,b);
        return m[{i,j}];
    }
    int minPathSum(vector<vector<int>>& grid) {
        map<pair<int,int>,int>m;
        return check(0,0,grid,m);
        
    }
};