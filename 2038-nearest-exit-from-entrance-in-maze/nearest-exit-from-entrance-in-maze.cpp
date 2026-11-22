class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        queue<tuple<int,int,int>>q;
        q.push({entrance[0],entrance[1],0});
        int ans=-1;
        while(q.size()){
            auto [i,j,steps]=q.front();
            q.pop();
            maze[i][j]=',';
            if(i==maze.size()-1||j==maze[0].size()-1||i==0||j==0){
                if(i!=entrance[0] || j!=entrance[1])
                return steps;
            }
            for(auto k:dir){
                if(i+k[0]>=0 && i+k[0]<maze.size() && j+k[1]>=0 && j+k[1]<maze[0].size() && maze[i+k[0]][j+k[1]]=='.'){
                    int a=steps+1;
                    maze[i+k[0]][j+k[1]]=',';
                    q.push({i+k[0],j+k[1],a});
                }
            }
        }
        return ans;
    }
};