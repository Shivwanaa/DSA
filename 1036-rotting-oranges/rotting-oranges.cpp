class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        queue<pair<int,int>>q;
        int rot=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    rot++;
                }
            }
        }
        int s=q.size();
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(rot>0 && q.size()){
            int qs=q.size();
            for(int l=0;l<qs;l++){
                auto [i,j]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    if(i+dir[k][0]<0 ||i+dir[k][0]>=grid.size()||j+dir[k][1]<0||j+dir[k][1]>=grid[0].size()){
                        continue;
                    }
                    if(grid[i+dir[k][0]][j+dir[k][1]]==1){
                        rot--;
                        grid[i+dir[k][0]][j+dir[k][1]]=2;
                        q.push({i+dir[k][0],j+dir[k][1]});
                    }
                }
            }
            ans++;
        }
        if(rot!=0){
            return -1;
        }
        return ans;
    }
};