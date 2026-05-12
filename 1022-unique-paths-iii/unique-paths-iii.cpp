class Solution {
public:
    int check(vector<vector<int>>& grid,int an,int i,int j,int re,int ce){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1||grid[i][j]==-2||grid[i][j]==-3){
            return 0;
        }
        if(i==re && j==ce){
            return an==0;
        }
        if(grid[i][j]==1){
            grid[i][j]=-3;
        }
        if(grid[i][j]==0){
        grid[i][j]=-2;
        an--;
        }
        int a=check(grid,an,i+1,j,re,ce);
        int b=check(grid,an,i-1,j,re,ce);
        int c=check(grid,an,i,j+1,re,ce);
        int d=check(grid,an,i,j-1,re,ce);

        if(grid[i][j]==-2)
        grid[i][j]=0;
        if(grid[i][j]==-3){
            grid[i][j]=1;
        }
        return a+b+c+d;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        //so entire grid has to be 1/-1-
        //map with 0 and 1
        // unordered_map<int,int>>m;
        int r,c,re,ce,an=0;
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
                if(grid[i][j]==2){
                    re=i;
                    ce=j;
                }
            }
        } 
        return check(grid,an,r,c,re,ce);
    }
};