class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int emp=0;
        queue<pair<int,int>>q;
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[0].size();j++){
                if(rooms[i][j]==0){
                    q.push({i,j});
                }
                if(rooms[i][j]==INT_MAX){
                    emp++;
                }
            }
        }
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(q.size()){
            auto [i,j]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                if(i+dir[k][0]<0||i+dir[k][0]>=rooms.size()||j+dir[k][1]<0||j+dir[k][1]>=rooms[0].size()){
                    continue;
                }
                if(rooms[i+dir[k][0]][j+dir[k][1]]==INT_MAX){
                    rooms[i+dir[k][0]][j+dir[k][1]]=min(rooms[i][j]+1,rooms[i+dir[k][0]][j+dir[k][1]]);
                    q.push({i+dir[k][0],j+dir[k][1]});
                }   
            }
        }
    }
};