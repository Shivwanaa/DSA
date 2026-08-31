class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //djikistra
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
        q.push({0,0,0});
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> dist(
            heights.size()+1,
            vector<int>(heights[0].size()+1, 1e9)
        );
        dist[0][0]=0;
        int temp=1e9;
        while(q.size()){
            auto[dis,r,c]=q.top();
            q.pop();
            if(dist[r][c]>dis){
                continue;
            }
            if(r==heights.size()-1 && c==heights[0].size()-1){
                return dis;
            }
            for(auto i:dir){
                int nr=i[0]+r;
                int nc=i[1]+c;
                if(nr>=0&& nr<heights.size()&& nc>=0 && nc<heights[0].size()){
                    temp=max(dis,abs(heights[nr][nc]-heights[r][c]));
                    if(dist[nr][nc]>temp){
                        dist[nr][nc]=temp;
                        q.push({temp,nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};