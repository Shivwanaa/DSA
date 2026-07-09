class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                q.push({i,j});
            }
            if(grid[i][j]==1){
                count++;
            }
            }
        }
        // vector<vector<int>>dir(4,vector<int>(2));
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        int ans=0;
        while(q.size() && count){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto [r,c]=q.front();
                q.pop();
                for(auto i:dir){
                    if(r+i[0]<grid.size() && c+i[1]<grid[0].size() && grid[r+i[0]][c+i[1]]==1){
                        grid[r+i[0]][c+i[1]]=2;
                        q.push({r+i[0],c+i[1]});
                        count--;                        
                    }
                }
            }
            ans++;
        }
        if(count!=0){
            return -1;
        }
        return ans;
    }
};