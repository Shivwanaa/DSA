class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>>dist(heights.size(),vector<int>(heights[0].size(),1e9));
        dist[0][0]=0;
        q.push({0,0,0});
        while(q.size()){
            auto [wt,r,c]=q.top();
            q.pop();
            if (wt>dist[r][c]) continue;
            for(auto k:dir){
                int nr=k[0]+r;
                int nc=k[1]+c;
                if(nr<0||nr>=heights.size()||nc<0||nc>=heights[0].size()){
                    continue;
                }
                if(dist[nr][nc]>max(wt,abs(heights[r][c]-heights[nr][nc]))){
                    dist[nr][nc]=max(wt,abs(heights[r][c]-heights[nr][nc]));
                    q.push({dist[nr][nc],nr,nc});
                }
                
            }
        }
        return dist[heights.size()-1][heights[0].size()-1];
    }
};