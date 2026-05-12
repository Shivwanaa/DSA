class Solution {
public:
    int check(vector<vector<int>>& grid,int an,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1 ){
            return 0;
        }
        if(grid[i][j]==2){
            return an==0;
        }
        int temp=grid[i][j];
        grid[i][j]=-1;
        int a=check(grid,an-1,i+1,j);
        int b=check(grid,an-1,i-1,j);
        int c=check(grid,an-1,i,j+1);
        int d=check(grid,an-1,i,j-1);
        grid[i][j]=temp;
        return a+b+c+d;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        //so entire grid has to be 1/-1-
        //map with 0 and 1
        // unordered_map<int,int>>m;
        int an=0;
        int r=0,c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                    // m[0].push_back({i,j});
                    an++;
                }
                if(grid[i][j]==1){
                    r=i;
                    c=j;
                }
                
            }
        } 
        return check(grid,an+1,r,c);
    }
};