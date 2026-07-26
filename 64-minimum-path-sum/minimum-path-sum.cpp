class Solution {
public:
map<pair<int,int>,int>m;
    int check(int i,int j,vector<vector<int>>& grid){
        if(m.find({i,j})!=m.end()){
            return m[{i,j}];
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()){
            return 1e9;
        }
        int a=check(i+1,j,grid);
        int b=check(i,j+1,grid);
        return m[{i,j}]= grid[i][j]+min(a,b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        return check(0,0,grid);
    }
};