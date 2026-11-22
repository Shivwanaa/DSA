class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
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
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        int time=0;
        while(q.size()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto [r,c]=q.front();
                q.pop();
                for(auto k:dir){
                    int nr=k[0]+r;
                    int nc=k[1]+c;
                    if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1){
                        q.push({nr,nc});
                        fresh--;
                        grid[nr][nc]=2;
                    }
                }
            }
            time++;
        }
        if(fresh!=0){
            return -1;
        }
        return time-1;
    }
};