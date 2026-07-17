class Solution {
public:
    int check(vector<vector<int>>& grid,int i,int j,int island){
        if(i<0||j<0||j>=grid[0].size()||i>=grid.size()||grid[i][j]!=1||grid[i][j]==0){
            return 0;
        }
        grid[i][j]=island;
        int s=1;
        s=s+check(grid,i+1,j,island);
        s=s+check(grid,i-1,j,island);
        s=s+check(grid,i,j+1,island);
        s=s+check(grid,i,j-1,island);
        return s;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int island=2;
        unordered_map<int,int>marea;
        marea[0]=0;
        int ar=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ar=check(grid,i,j,island);
                    marea[island]=ar;
                    island++;
                }
            }
        }
        if(marea.size()==1){
            return 1;
        }
        int maxarea=0;
        for(auto i:marea){
            maxarea=max(maxarea,i.second);
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    unordered_set<int>v;
                    int a=0;
                    v.insert(i>0?grid[i-1][j]:0);
                    v.insert(j>0?grid[i][j-1]:0);
                    v.insert(i<grid.size()-1?grid[i+1][j]:0);
                    v.insert(j<grid[0].size()-1?grid[i][j+1]:0);
                for(auto i:v){
                    a=a+marea[i];
                }
                maxarea=max(maxarea,a+1);
                }
            }
            
        }
        return maxarea;
    }
};