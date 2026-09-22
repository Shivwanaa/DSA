class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int t=0;
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0){
            return 0;
        }
        while(q.size()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto[r,c]=q.front();
                q.pop();
                for(auto [i,j]:dir){
                    int nr=i+r;
                    int nc=j+c;
                    if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]!=-1){
                        if(grid[nr][nc]==1){
                            fresh--;
                        
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        }
                    }
                }
            }
            t++;
        }
        if(fresh==0){
            return t-1;
        }
        return -1;
    }
};