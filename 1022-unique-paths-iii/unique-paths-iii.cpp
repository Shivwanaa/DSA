class Solution {
public:
    int check(int i,int j,vector<vector<int>>& grid,set<pair<int,int>>&v,int c){

        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==-1|| v.count({i,j})){
            return 0;
        }
        if(grid[i][j]==2){
            if(c==0)
            return 1;
            return 0;
        }
        v.insert({i,j});
        grid[i][j]=-1;
        int ans=0;
        ans+=check(i+1,j,grid,v,c-1);
        ans+=check(i-1,j,grid,v,c-1);
        ans+=check(i,j+1,grid,v,c-1);
        ans+=check(i,j-1,grid,v,c-1);
        grid[i][j]=0;
        v.erase({i,j});
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int c=0;
        int si,sj;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    c++;
                }
                if(grid[i][j]==1){
                    si=i;
                    sj=j;
                }
            }
        }
        set<pair<int,int>>v;
        return check(si,sj,grid,v,c+1);
        return -1;
    }
};