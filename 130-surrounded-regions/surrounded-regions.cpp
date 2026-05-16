class Solution {
public:
    void check(int i,int j,vector<vector<char>>& grid){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=='X'||grid[i][j]=='c'){
            return;
        }
        grid[i][j]='c';
        check(i+1,j,grid);
        check(i-1,j,grid);
        check(i,j+1,grid);
        check(i,j-1,grid);
    }
    void solve(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if((i==0||j==0||i==grid.size()-1||j==grid[0].size()-1)&&grid[i][j]=='O'){
                    check(i,j,grid);
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!='c'){
                    grid[i][j]='X';
                }
                if(grid[i][j]=='c'){
                    grid[i][j]='O';
                }
            }
        }
    }
};