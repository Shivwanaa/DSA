class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>q;
        vector<vector<int>>effort(heights.size(),vector<int>(heights[0].size(),1e9));
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        effort[0][0]=0;
        q.push({0,{0,0}});
        while(q.size()){
            int ef=q.top().first;
            auto[i,j]=q.top().second;
            q.pop();
            if(i==heights.size()-1 && j==heights[0].size()-1){
                return effort[heights.size()-1][heights[0].size()-1];
            }
            for(auto k:dir){
                if(i+k[0]<0||i+k[0]>=heights.size()||j+k[1]<0||j+k[1]>=heights[0].size()){
                    continue;
                }
                int newEffort = max(
                    effort[i][j],
                    abs(heights[i+k[0]][j+k[1]]-heights[i][j])
                );
                if(newEffort<effort[i+k[0]][j+k[1]]){
                    effort[i+k[0]][j+k[1]]=newEffort;
                    q.push({newEffort,{i+k[0],j+k[1]}});
                }
            }
        }
        return -1;
    }
};