class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dir[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,-1},{-1,1},{1,1},{-1,-1}};
        queue<tuple<int,int,int>>q;
        q.push({0,0,1});
        int ans=-1;
        if(grid[0][0]==1){
            return -1;
        }
        while(q.size()){
            auto [i,j,steps]=q.front();
            q.pop();
            
            if(i==grid.size()-1 && j==grid[0].size()-1){
                return steps;
            }
            for(auto k:dir){
                if(i+k[0]>=0 && i+k[0]<grid.size() && j+k[1]>=0 && j+k[1]<grid[0].size() && grid[i+k[0]][j+k[1]]==0){
                    int a=steps+1;
                    grid[i+k[0]][j+k[1]]=1;
                    q.push({i+k[0],j+k[1],a});
                }
            }
        }
        return ans;

    }
};