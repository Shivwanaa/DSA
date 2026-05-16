class Solution {
public:
    void check(vector<vector<int>>& grid, int i, int j, int color,int o){
        if(i<0 ||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]!=o){
            return;
        }
        grid[i][j]=color;
        check(grid,i+1,j,color,o);
        check(grid,i-1,j,color,o);
        check(grid,i,j+1,color,o);
        check(grid,i,j-1,color,o);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        check(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};